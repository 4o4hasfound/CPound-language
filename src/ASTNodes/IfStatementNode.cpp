#include "ASTNodes/IfStatementNode.hpp"

IfStatementNode::IfStatementNode(const PositionInfo& pos)
	: ASTNode(ASTNode::IfStatement, pos) {

}

IfStatementNode::IfStatementNode(const PositionInfo& pos, std::unique_ptr<ASTNode>&& _condition, std::unique_ptr<ASTNode>&& _mainBody, std::unique_ptr<ASTNode>&& _elseBody)
	: ASTNode(ASTNode::IfStatement, pos)
	, condition(std::forward<std::unique_ptr<ASTNode>>(_condition))
	, mainBody(std::forward<std::unique_ptr<ASTNode>>(_mainBody))
	, elseBody(std::forward<std::unique_ptr<ASTNode>>(_elseBody)) {

}

void IfStatementNode::accept(Visitor& visitor) {
	visitor.visitIfStatementNode(this);
}

std::wstring IfStatementNode::str() const {
	return std::wstring();
}
