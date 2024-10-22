#include "ASTNodes/UnaryExpressionNode.hpp"

UnaryExpressionNode::UnaryExpressionNode(const PositionInfo& pos)
	: ASTNode(ASTNode::UnaryExpression, pos) {

}

UnaryExpressionNode::UnaryExpressionNode(const PositionInfo& pos, BinaryOperatorType _operatorType)
	: ASTNode(ASTNode::UnaryExpression, pos)
	, operatorType(_operatorType) {

}

UnaryExpressionNode::UnaryExpressionNode(const PositionInfo& pos, std::unique_ptr<ASTNode>&& expr, BinaryOperatorType _operatorType)
	: ASTNode(ASTNode::UnaryExpression, pos)
	, expression(std::forward<std::unique_ptr<ASTNode>>(expr))
	, operatorType(_operatorType) {

}

void UnaryExpressionNode::accept(Visitor& visitor) {
	visitor.visitUnaryExpressionNode(this);
}

std::wstring UnaryExpressionNode::str() const {
	return std::wstring();
}
