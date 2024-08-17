#include "ASTNodes/DebugStatementNode.hpp"

DebugStatementNode::DebugStatementNode(std::wstring::const_iterator pos)
	: StatementNode(ASTNode::DebugStatement, pos) {

}

DebugStatementNode::DebugStatementNode(std::wstring::const_iterator pos, std::unique_ptr<ASTNode>&& _statement)
	: StatementNode(ASTNode::DebugStatement, std::forward<std::unique_ptr<ASTNode>>(_statement), pos) {

}

void DebugStatementNode::accept(Visitor& visitor) {
	visitor.visitDebugStatementNode(this);
}

std::wstring DebugStatementNode::str() const {
	return std::wstring();
}
