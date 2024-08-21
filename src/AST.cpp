#include "AST.hpp"

const std::unordered_map<OperatorType, int> AST::s_presedence{ {
	{OperatorType::LogicalNot, 15},
	{OperatorType::BitwiseNot, 15},
	{OperatorType::LogicalNot, 15},
	{OperatorType::BitwiseNot, 15},
	{OperatorType::UnaryPlus, 15},
	{OperatorType::UnaryNegation, 15},
	{OperatorType::FrontIncrement, 15},
	{OperatorType::FrontDecrement, 15},
	{OperatorType::EndIncrement, 15},
	{OperatorType::EndDecrement, 15},
	{OperatorType::Past, 15},
	{OperatorType::Current, 15},
	{OperatorType::Exponentiation, 14},
	{OperatorType::Multiplication, 13},
	{OperatorType::Division, 13},
	{OperatorType::Modulus, 13},
	{OperatorType::Addition, 12},
	{OperatorType::Subtraction, 12},
	{OperatorType::LeftShift, 11},
	{OperatorType::RightShift, 11},
	{OperatorType::Less, 10},
	{OperatorType::LessEqual, 10},
	{OperatorType::Greater, 10},
	{OperatorType::GreaterEqual, 10},
	{OperatorType::EqualTo, 9},
	{OperatorType::NotEqualTo, 9},
	{OperatorType::ReferenceEqualTo, 9},
	{OperatorType::ReferenceNotEqual, 9},
	{OperatorType::BitwiseAnd, 8},
	{OperatorType::BitwiseXor, 7},
	{OperatorType::BitwiseOr, 6},
	{OperatorType::LogicalAnd, 5},
	{OperatorType::LogicalOr, 4},
	{OperatorType::ReferenceAssignment, 3},
	{OperatorType::Assignment, 2},
	{OperatorType::AdditionAssignment, 2},
	{OperatorType::SubtractionAssignment, 2},
	{OperatorType::MultiplicationAssignment, 2},
	{OperatorType::DivisionAssignment, 2},
	{OperatorType::ModulusAssignment, 2},
	{OperatorType::ExponentiationAssignment, 2},
	{OperatorType::BitwiseAndAssignment, 2},
	{OperatorType::BitwiseOrAssignment, 2},
	{OperatorType::BitwiseXorAssignment, 2},
	{OperatorType::BitwiseNotAssignment, 2},
	{OperatorType::LogicalAndAssignment, 2},
	{OperatorType::LogicalOrAssignment, 2},
	{OperatorType::LogicalNotAssignment, 2},
	{OperatorType::LeftShiftAssignment, 2},
	{OperatorType::RightShiftAssignment, 2},
} };

AST::AST(const std::vector<std::unique_ptr<Token>>& tokens)
	: m_tokens(tokens), m_index(0), m_fallbackIndex(0) {

}

void AST::build(const std::wstring* string) {
	m_string = string;
	program = parseProgram();
}

void AST::debug() const {
	debug(program.get());
}

void AST::debug(ASTNode* node, int depth) const {
	if (!node) {
		return;
	}
	for (int i = 0; i < depth; ++i) {
		std::wcout << L"    ";
	}
	switch (node->type) {
	case ASTNode::Program: {
		ProgramNode* program = dynamic_cast<ProgramNode*>(node);
		std::wcout << L"Program: " << program->nodes.size() << L"\n";
		for (auto& n : program->nodes) {
			debug(n.get(), depth + 1);
		}
		break;
	}
	case ASTNode::Block: {
		BlockNode* block = dynamic_cast<BlockNode*>(node);
		std::wcout << L"Block: " << block->nodes.size() << L"\n";
		for (auto& n : block->nodes) {
			debug(n.get(), depth + 1);
		}
		break;
	}
	case ASTNode::VariableDeclaration: {
		VariableDeclarationNode* decl = dynamic_cast<VariableDeclarationNode*>(node);
		std::wcout << "Variable declaration: " << decl->declarations.size() << "\n";
		for (auto& n : decl->declarations) {
			debug(n, depth + 1);
		}
		break;
	}
	case ASTNode::FunctionDeclaration: {
		FunctionDeclarationNode* func = dynamic_cast<FunctionDeclarationNode*>(node);
		std::wcout << "Function declaration: " << func->declaration.symbol << ": " << KeywordTypeStringMap[static_cast<KeywordType>(func->declaration.returnDeclType)] << " " << func->declaration.returnType << "\n";
		for (auto& n : func->declaration.parameters) {
			debug(n, depth + 1);
		}
		debug(func->block.get(), depth + 1);
		break;
	}
	//case ASTNode::Expression: {
	//	ExpressionNode* expr = dynamic_cast<ExpressionNode*>(node);
	//	std::wcout << "ExpressionNode:\n";
	//	debug(expr->expression.get(), depth + 1);
	//	break;
	//}
	case ASTNode::NormalStatement: {
		NormalStatementNode* statement = dynamic_cast<NormalStatementNode*>(node);
		std::wcout << "Statement: \n";
		debug(statement->statement.get(), depth + 1);
		break;
	}
	case ASTNode::DebugStatement: {
		DebugStatementNode* statement = dynamic_cast<DebugStatementNode*>(node);
		std::wcout << "Debug Statement: \n";
		debug(statement->statement.get(), depth + 1);
		break;
	}
	case ASTNode::IfStatement: {
		IfStatementNode* ifStatement = dynamic_cast<IfStatementNode*>(node);
		std::wcout << "If Statement: \n";
		debug(ifStatement->condition.get(), depth + 1);
		debug(ifStatement->mainBody.get(), depth + 1);
		debug(ifStatement->elseBody.get(), depth + 1);
		break;
	}
	case ASTNode::ReturnStatement: {
		ReturnStatementNode* retStatement = dynamic_cast<ReturnStatementNode*>(node);
		std::wcout << "Ima dip Statement: \n";
		debug(retStatement->expression.get(), depth + 1);
		break;
	}
	case ASTNode::ReverseStatement: {
		ReverseStatementNode* revStatement = dynamic_cast<ReverseStatementNode*>(node);
		std::wcout << "Reverse Statement: \n";
		break;
	}
	case ASTNode::PrintStatement: {
		PrintStatementNode* printStatement = dynamic_cast<PrintStatementNode*>(node);
		std::wcout << "Print Statement: \n";
		for (const auto& n : printStatement->expressions) {
			debug(n.get(), depth + 1);
		}
		break;
	}
	case ASTNode::BinaryExpression: {
		BinaryExpressionNode* biOP = dynamic_cast<BinaryExpressionNode*>(node);
		std::wcout << "Binary ExpressionNode Statement: " << operatorTypeStringMap[static_cast<OperatorType>(biOP->operatorType)] << "\n";
		debug(biOP->LExpression.get(), depth + 1);
		debug(biOP->RExpression.get(), depth + 1);
		break;
	}
	case ASTNode::UnaryExpression: {
		UnaryExpressionNode* uOP = dynamic_cast<UnaryExpressionNode*>(node);
		std::wcout << "Binary ExpressionNode Statement: " << operatorTypeStringMap[static_cast<OperatorType>(uOP->operatorType)] << "\n";
		debug(uOP->expression.get(), depth + 1);
		break;
	}
	case ASTNode::StringLiteral: {
		StringLiteralNode* literal = dynamic_cast<StringLiteralNode*>(node);
		std::wcout << "String literal: " << literal->value << "\n";
		break;
	}
	case ASTNode::IntegerLiteral: {
		IntegerLiteralNode* literal = dynamic_cast<IntegerLiteralNode*>(node);
		std::wcout << "Interger literal: " << literal->value << "\n";
		break;
	}
	case ASTNode::FloatLiteral: {
		FloatLiteralNode* literal = dynamic_cast<FloatLiteralNode*>(node);
		std::wcout << "Float literal: " << literal->value << "\n";
		break;
	}
	case ASTNode::BooleanLiteral: {
		BooleanLiteralNode* literal = dynamic_cast<BooleanLiteralNode*>(node);
		std::wcout << "Boolean literal: " << booleanTypeStringMap[literal->value] << "\n";
		break;
	}
	case ASTNode::Identifier: {
		IdentifierNode* identifier = dynamic_cast<IdentifierNode*>(node);
		std::wcout << "Identifier: " << identifier->symbol << "\n";
		break;
	}
	case ASTNode::CallExpression: {
		CallExpressionNode* callexpr = dynamic_cast<CallExpressionNode*>(node);
		std::wcout << "Call Expression: " << callexpr->symbol << "\n";
		for (const auto& arg : callexpr->arguments) {
			debug(arg.get(), depth + 1);
		}
		break;
	}
	}
}

void AST::debug(const VariableDeclarationInfo& declInfo, int depth) const {
	for (int i = 0; i < depth; ++i) {
		std::wcout << "    ";
	}
	std::wcout << "variable: ";
	std::wcout << declInfo.symbol << ", " << KeywordTypeStringMap[static_cast<KeywordType>(declInfo.declType)];
	std::wcout << ", " << declInfo.type << ", lifetime: " << declInfo.lifetime.scope << " scopes, " << declInfo.lifetime.forwardLine << " forward lines, " << declInfo.lifetime.backwardLine << " backward lines, " << declInfo.lifetime.second << " seconds";
	std::wcout << "\n";
	debug(declInfo.defaultValue.get(), depth + 1);
}

Token* AST::peek(int delta) const {
	if (m_index + delta < m_tokens.size()) {
		return m_tokens[m_index + delta].get();
	}
	return nullptr;
}

bool AST::match(Token::TokenType type) const {
	return tokenIsType(peek(), type);
}

void AST::loadIndex() {
	m_fallbackIndex = m_index;
}

void AST::fallback() {
	m_index = m_fallbackIndex;
}

Token* AST::advance(int delta) {
	Token* ret = peek();
	m_index += delta;
	return ret;
}

Token* AST::past() const {
	if (m_index - 1 >= 0) {
		return m_tokens[m_index].get();
	}
	return nullptr;
}

Token* AST::consume(Token::TokenType type, const std::string& errorMessage) {
	if (peek()->isType(type)) return advance();
	throw std::runtime_error(errorMessage);
}

bool AST::isEnd() const {
	return m_index >= m_tokens.size();
}

std::unique_ptr<ProgramNode> AST::parseProgram() {
	if (peek()) {
		auto program = std::make_unique<ProgramNode>(peek()->position);
		while (m_index < m_tokens.size()) {
			std::unique_ptr<ASTNode> node;
			if ((node = parseKeyword())
				|| (node = parseVariableDeclaration())
				|| (node = parseEvaluationVariableDeclaration())
				|| (node = parseFunctionDeclaration())
				|| (node = parseIfStatement())
				|| (node = parseExpressionStatement())
				|| (node = parseBlock())) {
				program->nodes.push_back(std::move(node));
			}
			else {
				break;
			}
		}
		if (m_index < m_tokens.size() - 1) {
			Error::Log(peek(), L"Unrecognized token", *m_string);
		}
		return program;
	}
	return nullptr;
}

std::unique_ptr<ASTNode> AST::parseBlock(bool checkForStatementType) {
	loadIndex();

	if (!tokenIsType(peek(), DelimiterType::LCurlyBracket)) {
		fallback();
		return nullptr;
	}

	auto block = std::make_unique<BlockNode>(advance()->position);

	while (m_index < m_tokens.size()) {
		std::unique_ptr<ASTNode> node;
		if ((node = parseKeyword())
			|| (node = parseVariableDeclaration())
			|| (node = parseEvaluationVariableDeclaration())
			|| (node = parseFunctionDeclaration())
			|| (node = parseExpressionStatement())
			|| (node = parseBlock())) {
			block->nodes.push_back(std::move(node));
		}
		else {
			if (match(DelimiterType::RCurlyBracket)) {
				advance();
			}
			break;
		}
	}

	if (checkForStatementType) {
		auto statement = parseStatementType();
		statement->statement = std::move(block);
		return statement;
	}
	else {
		return block;
	}
}

std::unique_ptr<ASTNode> AST::parseType() {
	return std::unique_ptr<ASTNode>();
}

VariableDeclarationType AST::parseDeclType() {
	Token* declType = peek();
	if (!declType || declType->type != Token::Keyword
		|| declType->valueType != static_cast<int>(KeywordType::VarVarVar)
		&& declType->valueType != static_cast<int>(KeywordType::VarVarConst)
		&& declType->valueType != static_cast<int>(KeywordType::VarConstVar)
		&& declType->valueType != static_cast<int>(KeywordType::VarConstConst)
		&& declType->valueType != static_cast<int>(KeywordType::ConstVarVar)
		&& declType->valueType != static_cast<int>(KeywordType::ConstVarConst)
		&& declType->valueType != static_cast<int>(KeywordType::ConstConstVar)
		&& declType->valueType != static_cast<int>(KeywordType::ConstConstConst)) {
		return VariableDeclarationType::Void;
	}
	advance();
	return getVariableDeclarationType(declType);
}

Token* AST::parseIdentifier() {
	Token* identifier = peek();
	if (!tokenIsType(identifier, Token::Identifier)) {
		return nullptr;
	}
	advance();
	return identifier;
}

LifetimeInfo AST::parseLifeTime() {
	LifetimeToken* lifetime;
	LifetimeInfo ret;
	while (match(Token::Lifetime)) {
		lifetime = dynamic_cast<LifetimeToken*>(advance());
		switch (static_cast<LifetimeType>(lifetime->valueType)) {
		case LifetimeType::Scope:
			ret.scope = lifetime->lifetimeValue;
			break;
		case LifetimeType::ForwardLine:
			ret.forwardLine = std::abs(lifetime->lifetimeValue);
			break;
		case LifetimeType::BackwardLine:
			ret.backwardLine = std::abs(lifetime->lifetimeValue);
			break;
		case LifetimeType::Time:
			ret.second = lifetime->lifetimeValue;
			break;
		}
	}
	return ret;
}

std::unique_ptr<StatementNode> AST::parseFunctionDeclaration() {
	// function id(declType typeId id<lifetime> (=exp), ...) retDeclType retType{}
	loadIndex();

	if (!tokenIsType(peek(), KeywordType::Function)) {
		fallback();
		return nullptr;
	}

	auto func = std::make_unique<FunctionDeclarationNode>(advance()->position);

	Token* retIdentifier = parseIdentifier();
	if (!retIdentifier) {
		Error::Log(peek(), L"Expect identifier after type identifier", *m_string);
	}

	if (!tokenIsType(advance(), DelimiterType::LParen)) {
		Error::Log(peek(), L"Parameter list doesn't open with a left parenthesis", *m_string);
	}

	std::unique_ptr<StatementNode> statement;
	func->declaration.symbol = retIdentifier->str();
	Token* op;

	bool hasDefaultValue = false;
	std::unique_ptr<ASTNode> expression = nullptr;

	while (!match(DelimiterType::RParen)) {
		bool reference = false;
		if (match(KeywordType::Reference)) {
			reference = true;
			advance();
		}

		VariableDeclarationType declType = parseDeclType();
		if (declType == VariableDeclarationType::Void) {
			fallback();
			return nullptr;
		}

		Token* type = parseIdentifier();
		if (!type) {
			Error::Log(peek(), L"Expect type identifier after declaration type", *m_string);
		}

		Token* identifier = parseIdentifier();
		if (!identifier) {
			Error::Log(peek(), L"Expect identifier after type identifier", *m_string);
		}

		LifetimeInfo varLifeTime = parseLifeTime();
		if (varLifeTime.backwardLine > 0) {
			Error::Log(peek(), L"Parameter lifetime cannot be negative lines", *m_string);
		}
		if (varLifeTime.scope > 1) {
			Error::Log(peek(), L"Parameter lifetime cannot has scope lifetime greater than 1", *m_string);
		}

		op = peek();

		expression = nullptr;
		if (tokenIsType(op, OperatorType::Assignment)) {
			advance();
			expression = parseExpression();

			if (!expression) {
				Error::Log(peek(), L"Expect expression after assignment", *m_string);
			}

			hasDefaultValue = true;
		}
		else if (hasDefaultValue) {
			Error::Log(peek(), L"Undefaulted parameter cannot appear after defaulted parameter", *m_string);
		}

		func->declaration.parameters.push_back(
			{ declType, type->str(), identifier->str(), varLifeTime, std::move(expression), nullptr, 0, reference }
		);
		if (!tokenIsType(peek(), DelimiterType::Comma)) {
			break;
		}
		advance();
	}
	if (!tokenIsType(advance(), DelimiterType::RParen)) {
		Error::Log(peek(), L"Parameter list doesn't close with a right parenthesis", *m_string);
	}
	bool reference = false;

	if (match(KeywordType::Reference)) {
		advance();
		reference = true;
	}

	VariableDeclarationType retDeclType = parseDeclType();
	if (retDeclType != VariableDeclarationType::Void) {
		Token* retType = parseIdentifier();
		if (!retType) {
			Error::Log(peek(), L"Expect type identifier after declaration type", *m_string);
		}
		func->declaration.returnType = retType->str();
	}
	func->declaration.returnReference = reference;
	func->declaration.returnDeclType = retDeclType;
	func->declaration.generateMangledSymbol();

	func->block = parseBlock(0);
	if (!func->block) {
		Error::Log(peek(), L"Function isn't followed by a block", *m_string);
	}
	statement = parseStatementType();
	statement->statement = std::move(func);
	return statement;
}

std::unique_ptr<StatementNode> AST::parseVariableDeclaration() {
	// declType type id<lifetime> (=exp), ...

	loadIndex();

	bool reference = false;
	if (match(KeywordType::Reference)) {
		reference = true;
		advance();
	}

	VariableDeclarationType declType = parseDeclType();
	if (declType == VariableDeclarationType::Void) {
		fallback();
		return nullptr;
	}

	auto var = std::make_unique<VariableDeclarationNode>(peek(-1)->position);

	Token* type = parseIdentifier();
	if (!type) {
		Error::Log(peek(), L"Expect type identifier after declaration type", *m_string);
	}

	std::unique_ptr<StatementNode> statement;
	Token* op;
	int priority = 0;

	while (true) {
		// Get all the declarations in the single line
		VariableDeclarationInfo info;

		Token* identifier = parseIdentifier();
		if (!identifier) {
			Error::Log(peek(), L"Expect identifier after type identifier", *m_string);
		}

		LifetimeInfo varLifeTime = parseLifeTime();

		if (match(DelimiterType::LBracket)) {
			std::unique_ptr<ASTNode> arrayLength = parseExpression();

			info.array = true;
			info.arrayLength = std::move(arrayLength);
			if (!tokenIsType(advance(), DelimiterType::RBracket)) {
				Error::Log(peek(), L"Expect closing bracket after array length", *m_string);
			}
		}

		op = peek();

		std::unique_ptr<ASTNode> expression = nullptr;
		if (tokenIsType(op, OperatorType::Assignment)) {
			advance();
			expression = parseExpression();

			if (!expression) {
				Error::Log(peek(), L"Expect expression after assignment", *m_string);
			}
		}

		info.reference = reference;
		info.declType = declType;
		info.type = type->str();
		info.symbol = identifier->str();
		info.lifetime = varLifeTime;
		info.defaultValue = std::move(expression);
		info.amount = nullptr;
		info.priority = priority;

		var->declarations.push_back(std::move(info));
		if (!tokenIsType(peek(), DelimiterType::Comma)) {
			break;
		}
		advance();
	}

	if (tokenIsType(peek(), TerminatorType::QuestionMark)) {
		statement = std::make_unique<DebugStatementNode>(advance()->position);
		priority = 0;
	}
	else if (tokenIsType(peek(), TerminatorType::ExclamationMark)) {
		priority = static_cast<TerminatorToken*>(peek())->count;
		advance();
		if (!peek()) {
			priority = 0;
			statement = std::make_unique<NormalStatementNode>(peek(-1)->position);
		}
		else if (tokenIsType(peek(), TerminatorType::QuestionMark)) {
			statement = std::make_unique<DebugStatementNode>(advance()->position);
		}
		else {
			statement = std::make_unique<NormalStatementNode>(peek()->position);
		}
	}
	else {
		priority = 0;
		statement = std::make_unique<NormalStatementNode>(peek(-1)->position);
	}

	for (auto& node : var->declarations) {
		node.priority = priority;
	}

	statement->statement = std::move(var);
	return statement;
}

std::unique_ptr<StatementNode> AST::parseEvaluationVariableDeclaration() {
	// evaluation type id (=exp), ...

	loadIndex();

	if (!match(KeywordType::Evaluate)) {
		fallback();
		return nullptr;
	}

	auto var = std::make_unique<EvaluateVariableDeclarationNode>(
		advance()->position
	);

	Token* type = parseIdentifier();
	if (!type) {
		Error::Log(peek(), L"Expect type identifier after evaluation keyword", *m_string);
	}

	Token* identifier = parseIdentifier();
	if (!identifier) {
		Error::Log(peek(), L"Expect identifier after evaluation type", *m_string);
	}

	if (!tokenIsType(advance(), OperatorType::Assignment)) {
		Error::Log(peek(), L"Expect assignment operator after evaluation identifier", *m_string);
	}

	std::unique_ptr<ASTNode> expression = parseExpression();
	if (!expression) {
		Error::Log(peek(), L"Evaluation variable needs to be initialized with a value or expression", *m_string);
	}
	std::unique_ptr<StatementNode> statement = parseStatementType();

	var->declaration.type = type->str();
	var->declaration.symbol = identifier->str();
	var->declaration.value = std::move(expression);

	statement->statement = std::move(var);
	return statement;
}

std::unique_ptr<StatementNode> AST::parseClassDeclaration() {
	loadIndex();

	return nullptr;
}

std::unique_ptr<ASTNode> AST::parseUnary() {
	loadIndex();
	Token* token = advance();
	if (isPrefixUnaryOperator(token)) {
		auto expr = std::make_unique<UnaryExpressionNode>(token->position);
		expr->operatorType = static_cast<BinaryOperatorType>(token->valueType);
		expr->expression = parseUnary();
		return expr;
	}
	else if (tokenIsType(token, Token::Keyword)) {
		switch (token->valueType) {
		case static_cast<int>(KeywordType::Past): {
			auto expr = std::make_unique<PastNode>(token->position, parseUnary());
			return expr;
		}
		case static_cast<int>(KeywordType::Future): {
			auto expr = std::make_unique<FutureNode>(token->position, parseUnary());
			return expr;
		}
		case static_cast<int>(KeywordType::Length): {
			auto expr = std::make_unique<TimelineLengthNode>(token->position, parseUnary());
			return expr;
		}
		case static_cast<int>(KeywordType::Index): {
			auto expr = std::make_unique<TimelineIndexNode>(token->position, parseUnary());
			return expr;
		}
		case static_cast<int>(KeywordType::Insert): {
			auto expr = std::make_unique<TimelineInsertNode>(token->position, parseUnary());
			return expr;
		}
		case static_cast<int>(KeywordType::Prune): {
			auto expr = std::make_unique<TimelinePruneNode>(token->position, parseUnary());
			return expr;
		}
		case static_cast<int>(KeywordType::Begin): {
			auto expr = std::make_unique<TimelineBeginNode>(token->position, parseUnary());
			return expr;
		}
		case static_cast<int>(KeywordType::End): {
			auto expr = std::make_unique<TimelineEndNode>(token->position, parseUnary());
			return expr;
		}
		}
	}
	fallback();
	return parsePrimary();
}

std::unique_ptr<ASTNode> AST::parsePrimary() {
	// primary : Identifier | Call expr | Literal (postfix operator) | LPAREN expr RPAREN 

	loadIndex();
	Token* token = advance();

	if (tokenIsType(token, Token::Identifier)) {
		if (isPostfixUnaryOperator(peek())) {
			auto expr = std::make_unique<UnaryExpressionNode>(peek()->position);
			expr->operatorType = static_cast<BinaryOperatorType>(advance()->valueType);
			expr->expression = std::make_unique<IdentifierNode>(token->position, token->str());
			return expr;
		}
		advance(-1);
		auto expr = parseCallExpression();
		if (expr) {
			return expr;
		}
		advance(1);
		return std::make_unique<IdentifierNode>(token->position, token->str());
	}
	else if (tokenIsType(token, NumericLiteralType::Integer)) {
		return std::make_unique<IntegerLiteralNode>(
			token->position,
			dynamic_cast<NumericLiteralToken*>(token)->literalValue
		);
	}
	else if (tokenIsType(token, NumericLiteralType::Float)) {
		return std::make_unique<FloatLiteralNode>(
			token->position,
			dynamic_cast<NumericLiteralToken*>(token)->literalValue
		);
	}
	else if (tokenIsType(token, Token::StringLiteral)) {
		return std::make_unique<StringLiteralNode>(
			token->position,
			dynamic_cast<StringLiteralToken*>(token)->literalValue
		);
	}
	else if (tokenIsType(token, Token::Boolean)) {
		return std::make_unique<BooleanLiteralNode>(
			token->position,
			static_cast<BooleanType>(token->valueType)
		);
	}
	else if (tokenIsType(token, DelimiterType::LParen)) {
		auto expr = parseExpression();
		if (tokenIsType(peek(), DelimiterType::RParen)) {
			advance();
		}
		return expr;
	}

	fallback();
	return nullptr;
}

std::unique_ptr<ASTNode> AST::parseExpression(int precedence) {
	auto left = parseUnary();
	Token* token = nullptr;
	while ((token = peek()) && getPrecendence(token) > precedence) {
		advance();
		auto expr = std::make_unique<BinaryExpressionNode>(token->position);
		expr->LExpression = std::move(left);
		expr->RExpression = parseExpression(getPrecendence(token));
		expr->operatorType = static_cast<BinaryOperatorType>(token->valueType);
		left = std::move(expr);
	}
	return left;
}

std::unique_ptr<ASTNode> AST::parseCallExpression() {
	loadIndex();
	Token* token = advance();
	if (!tokenIsType(token, Token::Identifier)
		|| !tokenIsType(advance(), DelimiterType::LParen)) {
		fallback();
		return nullptr;
	}

	auto callExpr = std::make_unique<CallExpressionNode>(token->position, token->str());

	while (m_index < m_tokens.size()) {
		auto expr = parseExpression();
		if (!expr) {
			if (!match(DelimiterType::RParen)) {
				Error::Log(peek()->position, L"Expect closing right parenthesis", *m_string);
			}
			advance();
			break;
		}
		callExpr->arguments.push_back(std::move(expr));
		if (match(DelimiterType::RParen)) {
			advance();
			break;
		}
		if (!match(DelimiterType::Comma)) {
			Error::Log(peek(), L"Expect comma after expression", *m_string);
		}
		advance();
	}

	return callExpr;
}

std::unique_ptr<ASTNode> AST::parseExpressionStatement() {
	loadIndex();
	auto expr = parseExpression();
	if (!expr) {
		fallback();
		return nullptr;
	}
	auto statement = parseStatementType();
	statement->statement = std::move(expr);
	return statement;
}

std::unique_ptr<StatementNode> AST::parseIfStatement() {
	loadIndex();

	if (!tokenIsType(peek(), KeywordType::If)) {
		fallback();
		return nullptr;
	}

	auto ifstatement = std::make_unique<IfStatementNode>(advance()->position);

	ifstatement->condition = parseExpression();
	if (!ifstatement->condition) {
		ifstatement->condition = std::make_unique<BooleanLiteralNode>(peek()->position, BooleanType::True);
	}

	ifstatement->mainBody = parseBlock(0);
	if (!ifstatement->mainBody) {
		Error::Log(peek(), L"If statement isn't followed by a block", *m_string);
	}

	if (match(KeywordType::Else)) {
		advance();

		if (match(KeywordType::If)) {
			ifstatement->elseBody = parseIfStatement();
		}
		else {
			ifstatement->elseBody = parseBlock();
			if (!ifstatement->elseBody) {
				Error::Log(peek(), L"Else statement isn't followed by a block", *m_string);
			}
		}
	}

	auto statement = parseStatementType();
	statement->statement = std::move(ifstatement);
	return statement;
}

std::unique_ptr<StatementNode> AST::parseReverseStatement() {
	loadIndex();
	if (!tokenIsType(peek(), KeywordType::Reverse)) {
		fallback();
		return nullptr;
	}
	auto statement = parseStatementType();
	statement->statement = std::make_unique<ReverseStatementNode>(advance()->position);
	return statement;
}

std::unique_ptr<StatementNode> AST::parseReturnStatement() {
	loadIndex();
	Token* token = advance();
	if (!tokenIsType(token, KeywordType::Return)) {
		fallback();
		return nullptr;
	}
	auto retStatement = std::make_unique<ReturnStatementNode>(token->position);
	retStatement->expression = parseExpression();
	auto statement = parseStatementType();
	statement->statement = std::move(retStatement);

	return statement;
}

std::unique_ptr<StatementNode> AST::parsePrintStatement() {
	loadIndex();

	if (!tokenIsType(peek(), KeywordType::Print)) {
		fallback();
		return nullptr;
	}

	auto print = std::make_unique<PrintStatementNode>(advance()->position);
	std::unique_ptr<ASTNode> expr;
	while (true) {
		expr = parseExpression();
		if (!expr) {
			break;
		}
		print->expressions.push_back(std::move(expr));
		if (!match(DelimiterType::Comma)) {
			break;
		}
		advance();
	}
	auto statement = parseStatementType();
	statement->statement = std::move(print);

	return statement;
}

std::unique_ptr<StatementNode> AST::parseInputStatement() {
	loadIndex();

	if (!tokenIsType(peek(), KeywordType::Input)) {
		fallback();
		return nullptr;
	}

	auto print = std::make_unique<InputStatementNode>(advance()->position);
	std::unique_ptr<ASTNode> expr;
	while (true) {
		expr = parseExpression();
		if (!expr) {
			break;
		}
		print->expressions.push_back(std::move(expr));
		if (!match(DelimiterType::Comma)) {
			break;
		}
		advance();
	}
	auto statement = parseStatementType();
	statement->statement = std::move(print);

	return statement;
}

std::unique_ptr<StatementNode> AST::parseKeyword() {
	std::unique_ptr<StatementNode> node;
	if ((node = parseIfStatement())
		|| (node = parseReturnStatement())
		|| (node = parseReverseStatement())
		|| (node = parseInputStatement())
		|| (node = parsePrintStatement())) {
		return node;
	}
	return nullptr;
}

std::unique_ptr<StatementNode> AST::parseStatementType() {
	loadIndex();

	std::unique_ptr<StatementNode> statement = nullptr;
	if (tokenIsType(peek(), TerminatorType::QuestionMark)) {
		statement = std::make_unique<DebugStatementNode>(advance()->position);
	}
	else if (tokenIsType(peek(), TerminatorType::ExclamationMark)) {
		advance();
		if (!peek()) {
			statement = std::make_unique<NormalStatementNode>(peek(-1)->position);
		}
		else if (tokenIsType(peek(), TerminatorType::QuestionMark)) {
			statement = std::make_unique<DebugStatementNode>(advance()->position);
		}
		else {
			statement = std::make_unique<NormalStatementNode>(peek()->position);
		}
	}
	else {
		if (!peek()) {
			statement = std::make_unique<NormalStatementNode>(peek(-1)->position);
		}
		else {
			statement = std::make_unique<NormalStatementNode>(peek()->position);
		}
	}

	return statement;
}

bool AST::skipTerminatorType() {
	bool hasTerminator = false;
	while (match(Token::Delimiter)) {
		advance();
		hasTerminator = true;
	}
	return hasTerminator;
}

VariableDeclarationType AST::getVariableDeclarationType(Token* token) const {
	switch (static_cast<VariableDeclarationType>(token->valueType)) {
	case VariableDeclarationType::VarVarVar:
		return VariableDeclarationType::VarVarVar;
	case VariableDeclarationType::VarVarConst:
		return VariableDeclarationType::VarVarConst;
	case VariableDeclarationType::VarConstVar:
		return VariableDeclarationType::VarConstVar;
	case VariableDeclarationType::VarConstConst:
		return VariableDeclarationType::VarConstConst;
	case VariableDeclarationType::ConstVarVar:
		return VariableDeclarationType::ConstVarVar;
	case VariableDeclarationType::ConstVarConst:
		return VariableDeclarationType::ConstVarConst;
	case VariableDeclarationType::ConstConstVar:
		return VariableDeclarationType::ConstConstVar;
	case VariableDeclarationType::ConstConstConst:
		return VariableDeclarationType::ConstConstConst;
	}
	return VariableDeclarationType::Void;
}

int AST::getPrecendence(Token* token) const {
	if (!token->isType(Token::Operator)) {
		return -1;
	}
	return s_presedence.at(static_cast<OperatorType>(token->valueType));
}

bool AST::isAssignmentOperator(Token* token) const {
	return token && token->type == Token::Operator
		&& (token->valueType == static_cast<int>(OperatorType::Assignment)
			|| token->valueType == static_cast<int>(OperatorType::AdditionAssignment)
			|| token->valueType == static_cast<int>(OperatorType::SubtractionAssignment)
			|| token->valueType == static_cast<int>(OperatorType::MultiplicationAssignment)
			|| token->valueType == static_cast<int>(OperatorType::DivisionAssignment)
			|| token->valueType == static_cast<int>(OperatorType::ModulusAssignment)
			|| token->valueType == static_cast<int>(OperatorType::ExponentiationAssignment));
}

bool AST::isUnaryOperator(Token* token) const {
	return isPrefixUnaryOperator(token) || isPostfixUnaryOperator(token);
}
bool AST::isUnaryKeyword(Token* token) const {
	return token && token->type == Token::Keyword
		&& token->valueType == static_cast<int>(KeywordType::Past)
		&& token->valueType == static_cast<int>(KeywordType::Future)
		&& token->valueType == static_cast<int>(KeywordType::Length);
}
bool AST::isPrefixUnaryOperator(Token* token) const {
	return token && token->isType(Token::Operator) &&
		(token->valueType == static_cast<int>(OperatorType::LogicalNot)
			|| token->valueType == static_cast<int>(OperatorType::BitwiseNot)
			|| token->valueType == static_cast<int>(OperatorType::UnaryPlus)
			|| token->valueType == static_cast<int>(OperatorType::UnaryNegation)
			|| token->valueType == static_cast<int>(OperatorType::UnaryAbs));
}
bool AST::isPostfixUnaryOperator(Token* token) const {
	return token && token->isType(Token::Operator) &&
		(token->valueType == static_cast<int>(OperatorType::FrontIncrement)
			|| token->valueType == static_cast<int>(OperatorType::EndIncrement)
			|| token->valueType == static_cast<int>(OperatorType::FrontDecrement)
			|| token->valueType == static_cast<int>(OperatorType::EndDecrement));
}

bool AST::tokenIsType(Token* token, Token::TokenType type) const {
	return token && token->isType(type);
}
