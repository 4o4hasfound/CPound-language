#include "ASTNodes/LengthNode.hpp"

LengthNode::LengthNode(std::wstring::const_iterator pos)
	: ASTNode(ASTNode::Length, pos) {

}

LengthNode::LengthNode(std::wstring::const_iterator pos, std::unique_ptr<ASTNode>&& expr)
	: ASTNode(ASTNode::Length, pos)
	, expression(std::forward<std::unique_ptr<ASTNode>>(expr)) {

}

void LengthNode::accept(Visitor& visitor) {
	visitor.visitLengthNode(this);
}

std::wstring LengthNode::str() const {
	return std::wstring();
}
