#include "ASTNodes/FutureNode.hpp"

FutureNode::FutureNode(std::wstring::const_iterator pos)
	: ASTNode(ASTNode::Future, pos) {

}

FutureNode::FutureNode(std::wstring::const_iterator pos, std::unique_ptr<ASTNode>&& expr)
	: ASTNode(ASTNode::Future, pos)
	, expression(std::forward<std::unique_ptr<ASTNode>>(expr)) {

}

void FutureNode::accept(Visitor& visitor) {
	visitor.visitFutureNode(this);
}

std::wstring FutureNode::str() const {
	return std::wstring();
}
