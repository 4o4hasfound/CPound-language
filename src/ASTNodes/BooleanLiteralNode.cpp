#include "ASTNodes/BooleanLiteralNode.hpp"

BooleanLiteralNode::BooleanLiteralNode(const PositionInfo& pos)
	: ASTNode(ASTNode::BooleanLiteral, pos) {

}

BooleanLiteralNode::BooleanLiteralNode(const PositionInfo& pos, BooleanType _value)
	: ASTNode(ASTNode::BooleanLiteral, pos)
	, value(_value) {

}

void BooleanLiteralNode::accept(Visitor& visitor) {
	visitor.visitBooleanLiteralNode(this);
}

std::wstring BooleanLiteralNode::str() const {
	return std::wstring();
}
