#include "ASTNodes/BinaryExpressionNode.hpp"

BinaryExpressionNode::BinaryExpressionNode(const PositionInfo& pos)
	: ASTNode(ASTNode::BinaryExpression, pos) {

}

BinaryExpressionNode::BinaryExpressionNode(const PositionInfo& pos, BinaryOperatorType _type)
	: ASTNode(ASTNode::BinaryExpression, pos)
	, operatorType(_type) {

}

BinaryExpressionNode::BinaryExpressionNode(const PositionInfo& pos, std::unique_ptr<ASTNode>&& lexpr, std::unique_ptr<ASTNode>&& rexpr, BinaryOperatorType _type)
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
