#include "ASTNodes/EvaluateVariableDeclarationNode.hpp"

EvaluateVariableDeclarationNode::EvaluateVariableDeclarationNode(std::wstring::const_iterator pos)
	: ASTNode(ASTNode::EvaluateVariableDeclaration, pos) {

}

EvaluateVariableDeclarationNode::EvaluateVariableDeclarationNode(std::wstring::const_iterator pos, std::wstring type, std::wstring symbol)
	: ASTNode(ASTNode::EvaluateVariableDeclaration, pos)
	, declaration(type, symbol) {

}

EvaluateVariableDeclarationNode::EvaluateVariableDeclarationNode(std::wstring::const_iterator pos, std::wstring type, std::wstring symbol, std::unique_ptr<ASTNode>&& value)
	: ASTNode(ASTNode::EvaluateVariableDeclaration, pos)
	, declaration(type, symbol, std::forward<std::unique_ptr<ASTNode>>(value)) {

}

void EvaluateVariableDeclarationNode::accept(Visitor& visitor) {
	visitor.visitEvaluateVariableDeclarationNode(this);
}

std::wstring EvaluateVariableDeclarationNode::str() const {
	return std::wstring();
}

