#include "ASTNodes/NormalStatementNode.hpp"

NormalStatementNode::NormalStatementNode(const PositionInfo& pos)
	: StatementNode(ASTNode::NormalStatement, pos) {

}

NormalStatementNode::NormalStatementNode(const PositionInfo& pos, std::unique_ptr<ASTNode>&& _node)
	: StatementNode(ASTNode::NormalStatement, std::forward<std::unique_ptr<ASTNode>>(_node), pos){

}

void NormalStatementNode::accept(Visitor& visitor) {
	visitor.visitNormalStatementNode(this);
}

std::wstring NormalStatementNode::str() const {
	return std::wstring();
}
