#include "ASTNodes/BinaryExpressionNode.hpp"

BinaryExpressionNode::BinaryExpressionNode(std::wstring::const_iterator pos)
	: ASTNode(ASTNode::BinaryExpression, pos) {

}

BinaryExpressionNode::BinaryExpressionNode(std::wstring::const_iterator pos, BinaryOperatorType _type)
	: ASTNode(ASTNode::BinaryExpression, pos)
	, operatorType(_type) {

}

BinaryExpressionNode::BinaryExpressionNode(std::wstring::const_iterator pos, std::unique_ptr<ASTNode>&& lexpr, std::unique_ptr<ASTNode>&& rexpr, BinaryOperatorType _type)
	: ASTNode(ASTNode::BinaryExpression, pos)
	, operatorType(_type)
	, LExpression(std::forward<std::unique_ptr<ASTNode>>(lexpr))
	, RExpression(std::forward<std::unique_ptr<ASTNode>>(rexpr)) {

}

void BinaryExpressionNode::accept(Visitor& visitor) {
	visitor.visitBinaryExpressionNode(this);
}

std::wstring BinaryExpressionNode::str() const {
	return std::wstring();
}
