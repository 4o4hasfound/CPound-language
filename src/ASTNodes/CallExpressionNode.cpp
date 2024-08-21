#include "ASTNodes/CallExpressionNode.hpp"

CallExpressionNode::CallExpressionNode(const PositionInfo& pos)
	: ASTNode(ASTNode::CallExpression, pos) {

}

CallExpressionNode::CallExpressionNode(const PositionInfo& pos, const std::wstring& functionSymbol)
	: ASTNode(ASTNode::CallExpression, pos)
	, symbol(functionSymbol) {

}

void CallExpressionNode::accept(Visitor& visitor) {
	visitor.visitCallExpressionNode(this);
}

std::wstring CallExpressionNode::str() const {
	return std::wstring();
}
