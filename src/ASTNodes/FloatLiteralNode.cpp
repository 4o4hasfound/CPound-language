#include "ASTNodes/FloatLiteralNode.hpp"

FloatLiteralNode::FloatLiteralNode(std::wstring::const_iterator pos)
	: ASTNode(ASTNode::FloatLiteral, pos), value(0.0) {
}

FloatLiteralNode::FloatLiteralNode(std::wstring::const_iterator pos, double _value)
	: ASTNode(ASTNode::FloatLiteral, pos), value(_value) {
}


void FloatLiteralNode::accept(Visitor& visitor) {
	visitor.visitFloatLiteralNode(this);
}

std::wstring FloatLiteralNode::str() const {
	return std::wstring();
}
