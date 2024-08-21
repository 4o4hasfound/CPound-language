#include "ASTNodes/MemberVariableExpressionNode.hpp"

MemberVariableExpressionNode::MemberVariableExpressionNode(const PositionInfo& pos)
	: ASTNode(ASTNode::MemberVariableExpression, pos) {

}

MemberVariableExpressionNode::MemberVariableExpressionNode(const PositionInfo& pos, const std::wstring& _symbol, const std::wstring& _variableSymbol)
	: ASTNode(ASTNode::MemberVariableExpression, pos)
	, symbol(_symbol)
	, variableSymbol(_variableSymbol) {

}

void MemberVariableExpressionNode::accept(Visitor& visitor)	{
	visitor.visitMemberVariableExpressionNode(this);
}

std::wstring MemberVariableExpressionNode::str() const {
	return std::wstring();
}
