#include "ASTNodes/BooleanLiteralNode.hpp"

BooleanLiteralNode::BooleanLiteralNode(std::wstring::const_iterator pos)
	: ASTNode(ASTNode::BooleanLiteral, pos) {

}

BooleanLiteralNode::BooleanLiteralNode(std::wstring::const_iterator pos, BooleanType _value)
	: ASTNode(ASTNode::BooleanLiteral, pos)
	, value(_value) {

}

void BooleanLiteralNode::accept(Visitor& visitor) {
	visitor.visitBooleanLiteralNode(this);
}

std::wstring BooleanLiteralNode::str() const {
	return std::wstring();
}
