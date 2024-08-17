#include "ASTNodes/MemberVariableExpressionNode.hpp"

MemberVariableExpressionNode::MemberVariableExpressionNode(std::wstring::const_iterator pos)
	: ASTNode(ASTNode::MemberVariableExpression, pos) {

}

MemberVariableExpressionNode::MemberVariableExpressionNode(std::wstring::const_iterator pos, const std::wstring& _symbol, const std::wstring& _variableSymbol)
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
