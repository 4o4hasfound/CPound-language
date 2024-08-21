#include "ASTNodes/FloatLiteralNode.hpp"

FloatLiteralNode::FloatLiteralNode(const PositionInfo& pos)
	: ASTNode(ASTNode::FloatLiteral, pos), value(0.0) {
}

FloatLiteralNode::FloatLiteralNode(const PositionInfo& pos, double _value)
	: ASTNode(ASTNode::FloatLiteral, pos), value(_value) {
}


void FloatLiteralNode::accept(Visitor& visitor) {
	visitor.visitFloatLiteralNode(this);
}

std::wstring FloatLiteralNode::str() const {
	return std::wstring();
}
