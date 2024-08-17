#include "ASTNodes/ReturnStatementNode.hpp"

ReturnStatementNode::ReturnStatementNode(std::wstring::const_iterator pos)
	: ASTNode(ASTNode::ReturnStatement, pos) {

}

ReturnStatementNode::ReturnStatementNode(std::wstring::const_iterator pos, std::unique_ptr<ASTNode>&& expr)
	: ASTNode(ASTNode::ReturnStatement, pos)
	, expression(std::forward<std::unique_ptr<ASTNode>>(expr)) {

}

void ReturnStatementNode::accept(Visitor& visitor) {
	visitor.visitReturnStatementNode(this);
}

std::wstring ReturnStatementNode::str() const {
	return std::wstring();
}
