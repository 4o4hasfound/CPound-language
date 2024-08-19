#include "ASTNodes/PreviousNode.hpp"

PreviousNode::PreviousNode(std::wstring::const_iterator pos)
	: ASTNode(ASTNode::Previous, pos) {

}

PreviousNode::PreviousNode(std::wstring::const_iterator pos, std::unique_ptr<ASTNode>&& expr)
	: ASTNode(ASTNode::Previous, pos)
	, expression(std::forward<std::unique_ptr<ASTNode>>(expr)) {

}

void PreviousNode::accept(Visitor& visitor) {
	visitor.visitPreviousNode(this);
}

std::wstring PreviousNode::str() const {
	return std::wstring();
}
