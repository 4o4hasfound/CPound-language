#include "ASTNodes/NormalStatementNode.hpp"

NormalStatementNode::NormalStatementNode(std::wstring::const_iterator pos)
	: StatementNode(ASTNode::NormalStatement, pos) {

}

NormalStatementNode::NormalStatementNode(std::wstring::const_iterator pos, std::unique_ptr<ASTNode>&& _node)
	: StatementNode(ASTNode::NormalStatement, std::forward<std::unique_ptr<ASTNode>>(_node), pos){

}

void NormalStatementNode::accept(Visitor& visitor) {
	visitor.visitNormalStatementNode(this);
}

std::wstring NormalStatementNode::str() const {
	return std::wstring();
}
