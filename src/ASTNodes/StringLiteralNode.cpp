#include "ASTNodes/StringLiteralNode.hpp"

StringLiteralNode::StringLiteralNode(const PositionInfo& pos)
	: ASTNode(ASTNode::StringLiteral, pos) {

}

StringLiteralNode::StringLiteralNode(const PositionInfo& pos, const std::wstring& string)
	: ASTNode(ASTNode::StringLiteral, pos) 
	, value(string) {

}

void StringLiteralNode::accept(Visitor& visitor) {
	visitor.visitStringLiteralNode(this);
}

std::wstring StringLiteralNode::str() const {
	return std::wstring();
}
