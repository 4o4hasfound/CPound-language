#include "ASTNodes/PastNode.hpp"

PastNode::PastNode(std::wstring::const_iterator pos)
	: ASTNode(ASTNode::Past, pos) {

}

PastNode::PastNode(std::wstring::const_iterator pos, std::unique_ptr<ASTNode>&& expr)
	: ASTNode(ASTNode::Past, pos)
	, expression(std::forward<std::unique_ptr<ASTNode>>(expr)) {

}

void PastNode::accept(Visitor& visitor) {
	visitor.visitPastNode(this);
}

std::wstring PastNode::str() const {
	return std::wstring();
}
