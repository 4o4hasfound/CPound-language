#include "ASTNodes/BlockNode.hpp"

BlockNode::BlockNode(const PositionInfo& pos)
	: ASTNode(ASTNode::Block, pos) {

}

void BlockNode::accept(Visitor& visitor) {
	visitor.visitBlockNode(this);
}

std::wstring BlockNode::str() const {
	return std::wstring();
}
