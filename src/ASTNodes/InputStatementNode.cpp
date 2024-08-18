#include "ASTNodes/InputStatementNode.hpp"

InputStatementNode::InputStatementNode(std::wstring::const_iterator pos)
	: ASTNode(ASTNode::InputStatement, pos) {

}

void InputStatementNode::accept(Visitor& visitor) {
	visitor.visitInputStatementNode(this);
}

std::wstring InputStatementNode::str() const {
	return std::wstring();
}
