#pragma once
#include <string>

#include "Visitor.hpp"
#include "PositionInfo.hpp"

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
		Past,
		Future,
		TimelineBegin,
		TimelineEnd,
		TimelineLength,
		TimelinePrune,
		TimelineInsert,
		TimelineIndex
	};

	ASTNode(ASTNodeType nodeType, const PositionInfo& pos);
	virtual ~ASTNode() = default;

	virtual void accept(Visitor& visitor) = 0;
	virtual std::wstring str() const = 0;

	ASTNodeType type;
	PositionInfo position;
};