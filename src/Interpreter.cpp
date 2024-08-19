#include "Interpreter.hpp"

Interpreter::Interpreter(const std::wstring* string)
	: m_string(string) {

}

void Interpreter::run(ProgramNode* node) {
	m_scope.addScope();
	node->accept(*this);
}

void Interpreter::visitBinaryExpressionNode(ASTNode* node) {
	auto expr = static_cast<BinaryExpressionNode*>(node);
	std::shared_ptr<Value> lexpr = getExpressionValue(expr->LExpression.get());

	if (!lexpr->reassignable && expr->operatorType == BinaryOperatorType::Assignment) {
		Error::Log(node->position, L"Cannot apply assignment operation on a non reassignable object", *m_string);
	}
	if (!lexpr->editable && isEditOperator[static_cast<OperatorType>(expr->operatorType)]) {
		Error::Log(node->position, L"Cannot apply operation on a non editable object", *m_string);
	}

	std::shared_ptr<Value> rexpr = getExpressionValue(expr->RExpression.get());

	if (expr->operatorType == BinaryOperatorType::ReferenceAssignment) {
		if (!lexpr->reference) {
			Error::Log(node->position, L"Cannot apply reference assignment on non reference variable", *m_string);
		}
		lexpr = std::make_shared<Value>(rexpr->getReferenceObject());
		updateValue(lexpr);
		return;
	}

	try {
		doBinaryOperation(
			lexpr, rexpr, static_cast<OperatorType>(expr->operatorType)
		);
	}
	catch (const std::exception& e) {
		std::wstringstream errorMessage;
		errorMessage << e.what();
		Error::Log(node->position, errorMessage.str(), *m_string);
	}
}

void Interpreter::visitBlockNode(ASTNode* node) {
	auto block = dynamic_cast<BlockNode*>(node);
	if (!m_dontMakeNewScope) {
		m_scope.addScope();
	}
	m_dontMakeNewScope = 0;
	for (int i = getInitialIndex(block->nodes.size()); i >= 0 && i < block->nodes.size(); i = advanceIndex(i)) {
		block->nodes[i]->accept(*this);
		
		if (m_return) {
			break;
		}
	}
	m_scope.popScope();
}

void Interpreter::visitBooleanLiteralNode(ASTNode* node) {
	auto boolLiteral = dynamic_cast<BooleanLiteralNode*>(node);
	switch (boolLiteral->value) {
	case BooleanType::True:
		m_tmpValue = makeValue<bool>(1);
		break;
	case BooleanType::Maybe:
		m_tmpValue = makeValue<bool>(Random::get<double>());
		break;
	case BooleanType::False:
		m_tmpValue = makeValue<bool>(0);
		break;
	}
}

void Interpreter::visitBreakStatementNode(ASTNode* node) {
	m_break = 1;
}

void Interpreter::visitCallExpressionNode(ASTNode* node) {
	m_scope.addScope();

	CallExpressionNode* callexpr = dynamic_cast<CallExpressionNode*>(node);
	std::vector<std::shared_ptr<Value>> arguments;
	arguments.reserve(callexpr->arguments.size());
	for (const auto& expr : callexpr->arguments) {
		std::shared_ptr<Value> value = getExpressionValue(expr.get());
		arguments.push_back(value);
	}

	FunctionDeclarationNode* func = m_scope.getFunction(callexpr->symbol, arguments);
	if (!func) {
		Error::Log(node->position, L"No function found", *m_string);
	}

	for (int i = 0; i < func->declaration.parameters.size(); ++i) {
		VariableDeclarationInfo& parameter = func->declaration.parameters[i];

		if (i < arguments.size()) {
			if (parameter.type == arguments[i]->type) {
				std::shared_ptr<Value> value;
				if (parameter.reference && !arguments[i]->reference) {
					value = std::make_shared<Value>(arguments[i].get());
				}
				else {
					value = std::make_shared<Value>(arguments[i]->type, arguments[i]->getCurrent());
				}
				if (!value->setDeclType(parameter.declType)) {
					Error::Log(node->position, L"Cannot convert declaration type", *m_string);
				}
				value->lifetime = parameter.lifetime;
				m_scope.addVariable(parameter.symbol, value);
			}
			else {
				m_scope.addVariable(
					parameter.symbol,
					convertValue(arguments[i], parameter.type)
				);
			}
		}
		else {
			std::shared_ptr<Value> value = getExpressionValue(parameter.defaultValue.get()
			);
			m_scope.addVariable(
				parameter.symbol,
				convertValue(value, parameter.type)
			);
		}
	}

	m_dontMakeNewScope = 1;
	m_return = 0;
	func->block->accept(*this);

	if (!func->declaration.returnType.empty() && m_return) {
		if (func->declaration.returnReference) {
			if (m_tmpValue->type != func->declaration.returnType) {
				Error::Log(node->position, L"Cannot reference an identifier with different type", *m_string);
			}
			if (!m_tmpValue->setDeclType(func->declaration.returnDeclType)) {
				Error::Log(node->position, L"Cannot convert declaration type", * m_string);
			}
		}
		else if (canConvert(m_tmpValue, func->declaration.returnType)) {
			updateValue(convertValue(m_tmpValue, func->declaration.returnType));
			auto val = m_scope.getVariable(L"a");
			if (val) {
				int64_t arg = val->get<int64_t>();
				int64_t bruh = m_tmpValue->get<int64_t>();
				int asd = 2;
			}
		}
	}
	else {
		updateValue();
	}
	m_return = 0;
}

void Interpreter::visitClassDeclarationNode(ASTNode* node) {

}

void Interpreter::visitDebugStatementNode(ASTNode* node) {
	std::wcout << node->str() << "\n";
	dynamic_cast<DebugStatementNode*>(node)->statement->accept(*this);
}

void Interpreter::visitEvaluateVariableDeclarationNode(ASTNode* node) {
	auto evalVariable = dynamic_cast<EvaluateVariableDeclarationNode*>(node);

	m_scope.addEvalVariable(
		evalVariable->declaration.symbol
		, evalVariable
	);
}

void Interpreter::visitFloatLiteralNode(ASTNode* node) {
	auto literal = dynamic_cast<FloatLiteralNode*>(node);
	m_tmpValue = makeValue<double>(literal->value);
}

void Interpreter::visitFunctionDeclarationNode(ASTNode* node) {
	m_scope.addFunction(dynamic_cast<FunctionDeclarationNode*>(node));
}

void Interpreter::visitFutureNode(ASTNode* node) {
	auto prev = dynamic_cast<FutureNode*>(node);

	if (!prev->expression) {
		Error::Log(node->position, L"Expect expression after future keyword", *m_string);
	}
	std::shared_ptr<Value> value = getExpressionValue(prev->expression.get());
	auto newValue = std::make_shared<Value>(*value);
	newValue->future();
	updateValue(newValue);
}

void Interpreter::visitIdentifierNode(ASTNode* node) {
	auto id = dynamic_cast<IdentifierNode*>(node);
	m_tmpValue = m_scope.getVariable(id->symbol);

	if (m_tmpValue) {
		return;
	}

	EvaluateVariableDeclarationNode* evalVar = m_scope.getEvaluateVariable(id->symbol);
	if (evalVar) {
		m_tmpValue = getExpressionValue(evalVar->declaration.value.get());
		return;
	}

	Error::Log(node->position, L"Identifier not found", *m_string);
}

void Interpreter::visitIfStatementNode(ASTNode* node) {
	auto statement = dynamic_cast<IfStatementNode*>(node);
	auto value = getExpressionValue(statement->condition.get());
	if (!value) {
		Error::Log(node->position, L"Cannot get condition return value", *m_string);
	}

	if (cast<bool>(value)) {
		m_dontMakeNewScope = 0;
		statement->mainBody->accept(*this);
	}
	else {
		m_dontMakeNewScope = 0;
		if (statement->elseBody) {
			statement->elseBody->accept(*this);
		}
	}
}

void Interpreter::visitIndexExpressionNode(ASTNode* node) {

}

void Interpreter::visitInputStatementNode(ASTNode* node) {
	auto inputStatement = dynamic_cast<InputStatementNode*>(node);
	for (int i = 0; i < inputStatement->expressions.size(); ++i) {
		std::shared_ptr<Value> value = getExpressionValue(inputStatement->expressions[i].get());
		if (!value) {
			Error::Log(node->position, L"Identifier not found", *m_string);
		}
		getInput(value);
	}
}

void Interpreter::visitIntegerLiteralNode(ASTNode* node) {
	auto integer = dynamic_cast<IntegerLiteralNode*>(node);
	m_tmpValue = makeValue<int64_t>(integer->value);
}

void Interpreter::visitLengthNode(ASTNode* node) {
	auto prev = dynamic_cast<LengthNode*>(node);

	if (!prev->expression) {
		Error::Log(node->position, L"Expect expression after length keyword", *m_string);
	}
	std::shared_ptr<Value> value = getExpressionValue(prev->expression.get());
	if (value->reference) {
		auto bruh = value->getReferenceObject();
		updateValue(makeValue<int64_t>(value->getReferenceObject()->value->size()));
	}
	else {
		updateValue(makeValue<int64_t>(value->value->size()));
	}
}

void Interpreter::visitMemberFunctionCallExpressionNode(ASTNode* node) {

}

void Interpreter::visitMemberVariableExpressionNode(ASTNode* node) {

}

void Interpreter::visitNormalStatementNode(ASTNode* node) {
	auto statement = dynamic_cast<NormalStatementNode*>(node);
	statement->statement->accept(*this);
}

void Interpreter::visitPreviousNode(ASTNode* node) {
	auto prev = dynamic_cast<PreviousNode*>(node);

	if (!prev->expression) {
		Error::Log(node->position, L"Expect expression after previous keyword", *m_string);
	}
	std::shared_ptr<Value> value = getExpressionValue(prev->expression.get());
	auto newValue = std::make_shared<Value>(*value);
	newValue->previous();
	updateValue(newValue);
}

void Interpreter::visitPrintStatementNode(ASTNode* node) {
	auto printStatement = dynamic_cast<PrintStatementNode*>(node);
	for (int i = 0; i < printStatement->expressions.size(); ++i) {
		std::shared_ptr<Value> value = getExpressionValue(printStatement->expressions[i].get());
		std::wcout << cast<std::wstring>(value);
		
		if (i != printStatement->expressions.size() - 1) {
			std::wcout << L" ";
		}
	}
}

void Interpreter::visitProgramNode(ASTNode* node) {
	auto program = dynamic_cast<ProgramNode*>(node);

	for (int i = getInitialIndex(program->nodes.size()); i >= 0 && i < program->nodes.size(); i = advanceIndex(i)) {
		program->nodes[i]->accept(*this);
	}
}

void Interpreter::visitReturnStatementNode(ASTNode* node) {
	auto ret = dynamic_cast<ReturnStatementNode*>(node);
	m_return = 1;
	if (!ret->expression) {
		updateValue();
		return;
	}
	updateValue(getExpressionValue(ret->expression.get()));
}

void Interpreter::visitReverseStatementNode(ASTNode* node) {
	m_reverse = !m_reverse;
}

void Interpreter::visitStringLiteralNode(ASTNode* node) {
	auto string = dynamic_cast<StringLiteralNode*>(node);
	m_tmpValue = makeValue<std::wstring>(string->value);
}

void Interpreter::visitUnaryExpressionNode(ASTNode* node) {
	auto uOp = dynamic_cast<UnaryExpressionNode*>(node);
	std::shared_ptr<Value> value = getExpressionValue(uOp->expression.get());

	if (!value->editable && isEditOperator[static_cast<OperatorType>(uOp->operatorType)]) {
		Error::Log(node->position, L"Cannot apply operation on a non editable object", *m_string);
	}

	doUnaryOperation(value, static_cast<OperatorType>(uOp->operatorType));
}

void Interpreter::visitVariableDeclarationNode(ASTNode* node) {
	auto decl = dynamic_cast<VariableDeclarationNode*>(node);
	for (const auto& variable : decl->declarations) {
		auto var = m_scope.getVariable(variable.symbol, 0);
		if (!var || (!variable.reference && var->priority <= variable.priority && var->overridable)) {
			// Variable didn't exist in this scope
			// or declaration has higher priority
			
			std::shared_ptr<Value> value;
			if (variable.defaultValue) {
				if (variable.reference) {
					auto expr = getExpressionValue(variable.defaultValue.get());
					if (variable.type != expr->type) {
						Error::Log(node->position, L"Cannot reference a variable with different type", *m_string);
					}
					value = std::make_shared<Value>(expr.get());
					if (!value->setDeclType(variable.declType)) {
						Error::Log(node->position, L"Cannot convert declaration type", *m_string);
					}
				}
				else {
					value = getExpressionValue(variable.defaultValue.get())->copy();
					if (!(value = convertValue(value, variable.type))) {
						Error::Log(node->position, L"Cannot convert type", *m_string);
					}
					value->setDeclType(variable.declType);
				}
				value->lifetime = variable.lifetime;
				value->priority = variable.priority;
				m_scope.addVariable(variable.symbol, value);
			}
			else {
				if (variable.type == L"int") {
					value = makeValue<int64_t>(0);
				}
				else if (variable.type == L"float") {
					value = makeValue<double>(0);
				}
				else if (variable.type == L"bool") {
					value = makeValue<bool>(0);
				}
				else if (variable.type == L"string") {
					value = makeValue<std::wstring>(L"");
				}
				value->setDeclType(variable.declType);
				value->lifetime = variable.lifetime;
				value->priority = variable.priority;
				m_scope.addVariable(variable.symbol, value);
			}
		}
	}
}

std::shared_ptr<Value> Interpreter::getExpressionValue(ASTNode* node) {
	updateValue();
	node->accept(*this);
	try {
		//node->accept(*this);
	}
	catch (const std::exception& e) {
		std::wstringstream errorMessage;
		errorMessage << e.what();
		Error::Log(node->position, errorMessage.str(), *m_string);
	}
	if (!m_tmpValue) {
		Error::Log(node->position, L"Expect value", *m_string);
	}
	return m_tmpValue;
}

void Interpreter::doBinaryOperation(const std::shared_ptr<Value>& l, const std::shared_ptr<Value>& r, OperatorType type) {
	if (l->type == L"int") {
		m_tmpValue = Integer::BinaryOperation(type, l, r);
	}
	else if (l->type == L"float") {
		m_tmpValue = Float::BinaryOperation(type, l, r);
	}
	else if (l->type == L"bool") {
		m_tmpValue = Boolean::BinaryOperation(type, l, r);
	}
	else if (l->type == L"string") {
		m_tmpValue = String::BinaryOperation(type, l, r);
	}
	else {
		throw std::runtime_error("Invalid type");
	}
}

void Interpreter::doUnaryOperation(const std::shared_ptr<Value>& l, OperatorType type) {
	if (l->type == L"int") {
		m_tmpValue = Integer::UnaryOperation(type, l);
	}
	else if (l->type == L"float") {
		m_tmpValue = Float::UnaryOperation(type, l);
	}
	else if (l->type == L"bool") {
		m_tmpValue = Boolean::UnaryOperation(type, l);
	}
	else if (l->type == L"string") {
		m_tmpValue = String::UnaryOperation(type, l);
	}
	else {
		throw std::runtime_error("Invalid type");
	}
}

void Interpreter::updateValue(const std::shared_ptr<Value>& value) {
	m_tmpValue = value;
}

void Interpreter::getInput(const std::shared_ptr<Value>& value) {
	if (value->type == L"int") {
		int64_t input;
		std::wcin >> input;
		value->set<int64_t>(input);
	}
	else if (value->type == L"float") {
		double input;
		std::wcin >> input;
		value->set<double>(input);
	}
	else if (value->type == L"bool") {
		bool input;
		std::wcin >> input;
		value->set<bool>(input);

	}
	else if (value->type == L"string") {
		std::wstring input;
		std::wcin >> input;
		value->set<std::wstring>(input);
	}
}

int Interpreter::advanceIndex(int index) const {
	if (m_reverse) {
		return index - 1;
	}
	return index + 1;
}

int Interpreter::getInitialIndex(int size) const {
	if (m_reverse) {
		return size - 1;
	}
	return 0;
}
