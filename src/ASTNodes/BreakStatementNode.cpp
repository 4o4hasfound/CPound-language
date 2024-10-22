#include "ASTNodes/BreakStatementNode.hpp"

BreakStatementNode::BreakStatementNode(const PositionInfo& pos)
	: ASTNode(ASTNode::BreakStatement, pos) {
	
}

void BreakStatementNode::accept(Visitor& visitor) {
	visitor.visitBreakStatementNode(this);
}

std::wstring BreakStatementNode::str() const {
	return std::wstring();
}
