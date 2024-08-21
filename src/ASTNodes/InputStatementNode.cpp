#include "ASTNodes/InputStatementNode.hpp"

InputStatementNode::InputStatementNode(const PositionInfo& pos)
	: ASTNode(ASTNode::InputStatement, pos) {

}

void InputStatementNode::accept(Visitor& visitor) {
	visitor.visitInputStatementNode(this);
}

std::wstring InputStatementNode::str() const {
	return std::wstring();
}
