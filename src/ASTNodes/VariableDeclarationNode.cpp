#include "ASTNodes/VariableDeclarationNode.hpp"

VariableDeclarationNode::VariableDeclarationNode(const PositionInfo& pos)
	: ASTNode(ASTNode::VariableDeclaration, pos) {

}

void VariableDeclarationNode::accept(Visitor& visitor) {
	visitor.visitVariableDeclarationNode(this);
}

std::wstring VariableDeclarationNode::str() const {
	return std::wstring();
}
