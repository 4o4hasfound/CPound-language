#include "ASTNodes/IntegerLiteralNode.hpp"

IntegerLiteralNode::IntegerLiteralNode(std::wstring::const_iterator pos)
	: ASTNode(ASTNode::IntegerLiteral, pos) {
}

IntegerLiteralNode::IntegerLiteralNode(std::wstring::const_iterator pos, int64_t _value)
	: ASTNode(ASTNode::IntegerLiteral, pos)
	, value(_value) {

}


void IntegerLiteralNode::accept(Visitor& visitor) {
	visitor.visitIntegerLiteralNode(this);
}

std::wstring IntegerLiteralNode::str() const {
	return std::wstring();
}
