#include "ASTNodes/BlockNode.hpp"

BlockNode::BlockNode(std::wstring::const_iterator pos)
	: ASTNode(ASTNode::Block, pos) {

}

void BlockNode::accept(Visitor& visitor) {
	visitor.visitBlockNode(this);
}

std::wstring BlockNode::str() const {
	return std::wstring();
}
