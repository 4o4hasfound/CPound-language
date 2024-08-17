#include "ASTNodes/VariableDeclarationNode.hpp"

VariableDeclarationNode::VariableDeclarationNode(std::wstring::const_iterator pos)
	: ASTNode(ASTNode::VariableDeclaration, pos) {

}

void VariableDeclarationNode::accept(Visitor& visitor) {
	visitor.visitVariableDeclarationNode(this);
}

std::wstring VariableDeclarationNode::str() const {
	return std::wstring();
}
