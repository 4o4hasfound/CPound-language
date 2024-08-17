#include "ASTNodes/IndexExpressionNode.hpp"

IndexExpressionNode::IndexExpressionNode(std::wstring::const_iterator pos)
	: ASTNode(ASTNode::IndexExpression, pos) {

}

IndexExpressionNode::IndexExpressionNode(std::wstring::const_iterator pos, const std::wstring& _symbol)
	: ASTNode(ASTNode::IndexExpression, pos)
	, symbol(_symbol) {

}
IndexExpressionNode::IndexExpressionNode(std::wstring::const_iterator pos, const std::wstring& _symbol, std::unique_ptr<ASTNode>&& expr)
	: ASTNode(ASTNode::IndexExpression, pos)
	, symbol(_symbol)
	, expression(std::forward<std::unique_ptr<ASTNode>>(expr)) {

}

void IndexExpressionNode::accept(Visitor& visitor) {
	visitor.visitIndexExpressionNode(this);
}

std::wstring IndexExpressionNode::str() const {
	return std::wstring();
}
