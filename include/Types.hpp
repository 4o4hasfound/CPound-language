#pragma once
#include <string>
#include <vector>
#include <memory>
#include <sstream>
#include <unordered_map>

#include "ASTNodes/ASTNodeBase.hpp"

enum class OperatorType {
	Addition = 0,
	Subtraction = 1,
	Multiplication = 2,
	Division = 3,
	Modulus = 4,
	Exponentiation = 5,
	UnaryNegation = 6,
	UnaryPlus = 7,
	UnaryAbs = 8,
	EqualTo = 9,
	NotEqualTo = 10,
	Greater = 11,
	Less = 12,
	GreaterEqual = 13,
	LessEqual = 14,
	LogicalAnd = 15,
	LogicalOr = 16,
	LogicalNot = 17,
	BitwiseAnd = 18,
	BitwiseOr = 19,
	BitwiseXor = 20,
	BitwiseNot = 21,
	LeftShift = 22,
	RightShift = 23,
	LeftShiftAssignment = 24,
	RightShiftAssignment = 25,
	Assignment = 26,
	AdditionAssignment = 27,
	SubtractionAssignment = 28,
	MultiplicationAssignment = 29,
	DivisionAssignment = 30,
	ModulusAssignment = 31,
	ExponentiationAssignment = 32,
	BitwiseAndAssignment = 33,
	BitwiseOrAssignment = 34,
	BitwiseXorAssignment = 35,
	BitwiseNotAssignment = 36,
	LogicalAndAssignment = 37,
	LogicalOrAssignment = 38,
	LogicalNotAssignment = 39,
	FrontIncrement = 40,
	EndIncrement = 41,
	FrontDecrement = 42,
	EndDecrement = 43,
	Past = 44,
	Current = 45,
	Delete = 46, 
	ReferenceAssignment = 47,
	ReferenceNotEqual = 48,
	ReferenceEqualTo = 49
};
enum class BooleanType {
	True,
	Maybe,
	False
};
enum class KeywordType {
	VarVarVar,
	VarVarConst,
	VarConstVar,
	VarConstConst,
	ConstVarVar,
	ConstVarConst,
	ConstConstVar,
	ConstConstConst,
	Class,
	Public,
	Private,
	Evaluate,
	Operator,
	Typecast,
	Inherit,
	Reference,
	If,
	Else,
	Return,
	Function,
	Print,
	Input,
	Reverse,
	Past,
	Future,
	Length,
	Index,
	Prune,
	Insert,
	Begin,
	End,
	Noop
};
enum class DelimiterType {
	LParen,
	RParen,
	LBracket,
	RBracket,
	LCurlyBracket,
	RCurlyBracket,
	Comma
};
enum class LifetimeType{
	Line,
	Second,
	Scope
};
enum class NumericLiteralType {
	Integer,
	Float
};
enum class TerminatorType {
	ExclamationMark,
	QuestionMark
};

enum class BinaryOperatorType {
	Addition = 0,
	Subtraction = 1,
	Multiplication = 2,
	Division = 3,
	Modulus = 4,
	Exponentiation = 5,
	EqualTo = 9,
	NotEqualTo = 10,
	Greater = 11,
	Less = 12,
	GreaterEqual = 13,
	LessEqual = 14,
	LogicalAnd = 15,
	LogicalOr = 16,
	BitwiseAnd = 18,
	BitwiseOr = 19,
	BitwiseXor = 20,
	LeftShift = 22,
	RightShift = 23,
	LeftShiftAssignment = 24,
	RightShiftAssignment = 25,
	Assignment = 26,
	AdditionAssignment = 27,
	SubtractionAssignment = 28,
	MultiplicationAssignment = 29,
	DivisionAssignment = 30,
	ModulusAssignment = 31,
	ExponentiationAssignment = 32,
	BitwiseAndAssignment = 33,
	BitwiseOrAssignment = 34,
	BitwiseXorAssignment = 35,
	LogicalAndAssignment = 37,
	LogicalOrAssignment = 38,
	ReferenceAssignment = 47,
	ReferenceNotEqual = 48,
	ReferenceEqualTo = 49
};
enum class UnaryOperatorType {
	UnaryNegation = 6,
	UnaryPlus = 7,
	UnaryAbs = 8,
	LogicalNot = 17,
	BitwiseNot = 21,
	FrontIncrement = 40,
	EndIncrement = 41,
	FrontDecrement = 42,
	EndDecrement = 43,
	Past = 44,
	Current = 45
};

enum class VariableDeclarationType {
	VarVarVar,
	VarVarConst,
	VarConstVar,
	VarConstConst,
	ConstVarVar,
	ConstVarConst,
	ConstConstVar,
	ConstConstConst,

	Void
};

struct LifetimeInfo {
	LifetimeType type = LifetimeType::Scope;
	double value = 1;
};

struct EvaluateVariableDeclarationInfo {
	EvaluateVariableDeclarationInfo() = default;
	EvaluateVariableDeclarationInfo(std::wstring _type, std::wstring _symbol);
	EvaluateVariableDeclarationInfo(std::wstring _type, std::wstring _symbol, std::unique_ptr<ASTNode>&& _value);
	std::wstring type;
	std::wstring symbol;
	std::unique_ptr<ASTNode> value;
};

struct VariableDeclarationInfo {
	VariableDeclarationType declType;
	std::wstring type;
	std::wstring symbol;
	LifetimeInfo lifetime;
	std::unique_ptr<ASTNode> defaultValue;
	std::unique_ptr<ASTNode> amount;
	int priority;
	bool reference = false;
	bool array = false;
	std::unique_ptr<ASTNode> arrayLength;
};

struct FunctionDeclarationInfo {
	FunctionDeclarationInfo() = default;
	FunctionDeclarationInfo(const std::wstring& _symbol);
	FunctionDeclarationInfo(const std::wstring& _symbol, VariableDeclarationType retDeclType, const std::wstring& retType);

	std::wstring returnType;
	VariableDeclarationType returnDeclType;
	bool returnReference;

	std::wstring symbol;
	std::wstring mangledSymbol;

	std::vector<VariableDeclarationInfo> parameters;

	void generateMangledSymbol();
};

struct OperatorFunctionDeclarationInfo {
	OperatorFunctionDeclarationInfo() = default;
	OperatorFunctionDeclarationInfo(OperatorType type);
	OperatorFunctionDeclarationInfo(OperatorType type, VariableDeclarationType retDeclType, VariableDeclarationType retType);

	VariableDeclarationType returnType;
	VariableDeclarationType returnDeclType;

	OperatorType operatorType;
	std::wstring mangledSymbol;

	VariableDeclarationInfo parameter;

	void generateMangledSymbol();
};

struct TypecaseFunctionDeclarationInfo {
	TypecaseFunctionDeclarationInfo() = default;
	TypecaseFunctionDeclarationInfo(const std::wstring& type);
	TypecaseFunctionDeclarationInfo(const std::wstring& type, VariableDeclarationType retDeclType, VariableDeclarationType retType);

	VariableDeclarationType returnType;
	VariableDeclarationType returnDeclType;

	std::wstring type;
	std::wstring mangledSymbol;

	VariableDeclarationInfo parameter;

	void generateMangledSymbol();
};

struct FunctionOverloadInfo {
	std::wstring name;
	std::unordered_map<std::wstring, FunctionDeclarationInfo> overloads;
};

struct ClassDeclarationInfo {
	ClassDeclarationInfo() = default;
	ClassDeclarationInfo(const std::wstring& _symbol);
	ClassDeclarationInfo(const std::wstring& _symbol, const std::wstring& _parentSymbol);

	std::wstring symbol;
	std::wstring parentSymbol;
	std::vector<EvaluateVariableDeclarationInfo> publicEvaluateVariableDecl;
	std::vector<EvaluateVariableDeclarationInfo> privateEvaluateVariableDecl;
	std::vector<VariableDeclarationInfo> publicVariableDecl;
	std::vector<VariableDeclarationInfo> privateVariableDecl;
	std::vector<FunctionOverloadInfo> publicFunctionDecl;
	std::vector<FunctionOverloadInfo> privateFunctionDecl;
	std::vector<OperatorFunctionDeclarationInfo> publicOperatorDecl;
	std::vector<OperatorFunctionDeclarationInfo> privateOperatorDecl;
	std::vector<TypecaseFunctionDeclarationInfo> publicCastingDecl;
	std::vector<TypecaseFunctionDeclarationInfo> privateCastingDecl;
};

extern std::unordered_map<OperatorType, bool> isEditOperator;