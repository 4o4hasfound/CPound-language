#include "ASTNodes/IntegerLiteralNode.hpp"

IntegerLiteralNode::IntegerLiteralNode(const PositionInfo& pos)
	: ASTNode(ASTNode::IntegerLiteral, pos) {
}

IntegerLiteralNode::IntegerLiteralNode(const PositionInfo& pos, int64_t _value)
	: ASTNode(ASTNode::IntegerLiteral, pos)
	, value(_value) {

}


void IntegerLiteralNode::accept(Visitor& visitor) {
	visitor.visitIntegerLiteralNode(this);
}

std::wstring IntegerLiteralNode::str() const {
	return std::wstring();
}
