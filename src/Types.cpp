#include "Types.hpp"

std::unordered_map<OperatorType, bool> isEditOperator{
	{ OperatorType::LeftShiftAssignment		, 1 },
	{ OperatorType::RightShiftAssignment	, 1 },
	{ OperatorType::Assignment				, 0 },
	{ OperatorType::AdditionAssignment		, 1 },
	{ OperatorType::SubtractionAssignment	, 1 },
	{ OperatorType::MultiplicationAssignment, 1 },
	{ OperatorType::DivisionAssignment		, 1 },
	{ OperatorType::ModulusAssignment		, 1 },
	{ OperatorType::ExponentiationAssignment, 1 },
	{ OperatorType::BitwiseAndAssignment	, 1 },
	{ OperatorType::BitwiseOrAssignment		, 1 },
	{ OperatorType::BitwiseXorAssignment	, 1 },
	{ OperatorType::BitwiseNotAssignment	, 1 },
	{ OperatorType::LogicalAndAssignment	, 1 },
	{ OperatorType::LogicalOrAssignment		, 1 },
	{ OperatorType::LogicalNotAssignment	, 1 },
	{ OperatorType::FrontIncrement			, 1 },
	{ OperatorType::EndIncrement			, 1 },
	{ OperatorType::FrontDecrement			, 1 },
	{ OperatorType::EndDecrement			, 1 },
	{ OperatorType::Addition				, 0 },
	{ OperatorType::Subtraction				, 0 },
	{ OperatorType::Multiplication			, 0 },
	{ OperatorType::Division				, 0 },
	{ OperatorType::Modulus					, 0 },
	{ OperatorType::Exponentiation			, 0 },
	{ OperatorType::UnaryNegation			, 0 },
	{ OperatorType::UnaryPlus				, 0 },
	{ OperatorType::UnaryAbs				, 0 },
	{ OperatorType::EqualTo					, 0 },
	{ OperatorType::NotEqualTo				, 0 },
	{ OperatorType::Greater					, 0 },
	{ OperatorType::Less					, 0 },
	{ OperatorType::GreaterEqual			, 0 },
	{ OperatorType::LessEqual				, 0 },
	{ OperatorType::LogicalAnd				, 0 },
	{ OperatorType::LogicalOr				, 0 },
	{ OperatorType::LogicalNot				, 0 },
	{ OperatorType::BitwiseAnd				, 0 },
	{ OperatorType::BitwiseOr				, 0 },
	{ OperatorType::BitwiseXor				, 0 },
	{ OperatorType::BitwiseNot				, 0 },
	{ OperatorType::LeftShift				, 0 },
	{ OperatorType::RightShift				, 0 },
	{ OperatorType::Previous				, 0 },
	{ OperatorType::Current					, 0 },
	{ OperatorType::Delete					, 0  },
};

FunctionDeclarationInfo::FunctionDeclarationInfo(const std::wstring& _symbol)
	: symbol(_symbol) {

}

FunctionDeclarationInfo::FunctionDeclarationInfo(const std::wstring& _symbol, VariableDeclarationType retDeclType, const std::wstring& retType)
	: symbol(_symbol), returnDeclType(retDeclType), returnType(retType) {

}

void FunctionDeclarationInfo::generateMangledSymbol() {
	std::wstringstream wss;
	wss << symbol << "@";
	for (const auto& variable : parameters) {
		wss << variable.type << L'_';
	}
	mangledSymbol = wss.str();
}

ClassDeclarationInfo::ClassDeclarationInfo(const std::wstring& _symbol)
	: symbol(_symbol)
	, parentSymbol(L"") {

}

ClassDeclarationInfo::ClassDeclarationInfo(const std::wstring& _symbol, const std::wstring& _parentSymbol)
	: symbol(_symbol)
	, parentSymbol(_parentSymbol) {

}

EvaluateVariableDeclarationInfo::EvaluateVariableDeclarationInfo(std::wstring _type, std::wstring _symbol)
	: type(_type)
	, symbol(_symbol) {

}

EvaluateVariableDeclarationInfo::EvaluateVariableDeclarationInfo(std::wstring _type, std::wstring _symbol, std::unique_ptr<ASTNode>&& _value)
	: type(_type)
	, symbol(_symbol)
	, value(std::forward<std::unique_ptr<ASTNode>>(_value)) {

}
