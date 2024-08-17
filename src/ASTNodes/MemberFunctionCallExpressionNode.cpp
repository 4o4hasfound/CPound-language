#include "ASTNodes/MemberFunctionCallExpressionNode.hpp"

MemberFunctionCallExpressionNode::MemberFunctionCallExpressionNode(std::wstring::const_iterator pos)
	: ASTNode(ASTNode::MemberFunctionCallExpression, pos) {

}

MemberFunctionCallExpressionNode::MemberFunctionCallExpressionNode(std::wstring::const_iterator pos, const std::wstring& _symbol, std::unique_ptr<CallExpressionNode>&& expr)
	: ASTNode(ASTNode::MemberFunctionCallExpression, pos)
	, symbol(_symbol)
	, callExpr(std::forward<std::unique_ptr<CallExpressionNode>>(expr)) {

}

void MemberFunctionCallExpressionNode::accept(Visitor& visitor)
{
}

std::wstring MemberFunctionCallExpressionNode::str() const
{
	return std::wstring();
}
