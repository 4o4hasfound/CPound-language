#include "ASTNodes/DebugStatementNode.hpp"

DebugStatementNode::DebugStatementNode(const PositionInfo& pos)
	: StatementNode(ASTNode::DebugStatement, pos) {

}

DebugStatementNode::DebugStatementNode(const PositionInfo& pos, std::unique_ptr<ASTNode>&& _statement)
	: StatementNode(ASTNode::DebugStatement, std::forward<std::unique_ptr<ASTNode>>(_statement), pos) {

}

void DebugStatementNode::accept(Visitor& visitor) {
	visitor.visitDebugStatementNode(this);
}

std::wstring DebugStatementNode::str() const {
	return std::wstring();
}
