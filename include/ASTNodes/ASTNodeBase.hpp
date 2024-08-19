#pragma once
#include <string>

#include "Visitor.hpp"

class ASTNode {
public:
	enum ASTNodeType {
		Program,
		Block,
		VariableDeclaration,
		EvaluateVariableDeclaration,
		FunctionDeclaration,
		ClassDeclaration,
		Expression,
		NormalStatement,
		DebugStatement,
		IfStatement,
		ReturnStatement,
		BreakStatement,
		ReverseStatement,
		PrintStatement,
		InputStatement,
		BinaryExpression,
		UnaryExpression,
		StringLiteral,
		IntegerLiteral,
		FloatLiteral,
		BooleanLiteral,
		Identifier,
		CallExpression,
		MemberVariableExpression,
		MemberFunctionCallExpression,
		IndexExpression,
		Previous,
		Future,
		Length
	};

	ASTNode(ASTNodeType nodeType, std::wstring::const_iterator pos);
	virtual ~ASTNode() = default;

	virtual void accept(Visitor& visitor) = 0;
	virtual std::wstring str() const = 0;

	ASTNodeType type;
	std::wstring::const_iterator position;
};