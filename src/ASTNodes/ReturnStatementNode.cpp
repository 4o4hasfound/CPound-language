#include "ASTNodes/ReturnStatementNode.hpp"

ReturnStatementNode::ReturnStatementNode(const PositionInfo& pos)
	: ASTNode(ASTNode::ReturnStatement, pos) {

}

ReturnStatementNode::ReturnStatementNode(const PositionInfo& pos, std::unique_ptr<ASTNode>&& expr)
	: ASTNode(ASTNode::ReturnStatement, pos)
	, expression(std::forward<std::unique_ptr<ASTNode>>(expr)) {

}

void ReturnStatementNode::accept(Visitor& visitor) {
	visitor.visitReturnStatementNode(this);
}

std::wstring ReturnStatementNode::str() const {
	return std::wstring();
}
