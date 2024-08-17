#include "ASTNodes/FunctionDeclarationNode.hpp"

FunctionDeclarationNode::FunctionDeclarationNode(std::wstring::const_iterator pos)
	: ASTNode(ASTNode::FunctionDeclaration, pos) {

}

FunctionDeclarationNode::FunctionDeclarationNode(std::wstring::const_iterator pos, const std::wstring& _symbol)
	: ASTNode(ASTNode::FunctionDeclaration, pos)
	, declaration(_symbol) {

}


FunctionDeclarationNode::FunctionDeclarationNode(std::wstring::const_iterator pos, const std::wstring& _symbol, VariableDeclarationType retDeclType, const std::wstring& retType)
	: ASTNode(ASTNode::FunctionDeclaration, pos)
	, declaration(_symbol, retDeclType, retType) {

}

FunctionDeclarationNode::FunctionDeclarationNode(std::wstring::const_iterator pos, const std::wstring& _symbol, VariableDeclarationType retDeclType, const std::wstring& retType, std::unique_ptr<ASTNode>&& _block)
	: ASTNode(ASTNode::FunctionDeclaration, pos)
	, declaration(_symbol, retDeclType, retType)
	, block(std::forward<std::unique_ptr<ASTNode>>(_block)) {

}

void FunctionDeclarationNode::accept(Visitor& visitor) {
	visitor.visitFunctionDeclarationNode(this);
}

std::wstring FunctionDeclarationNode::str() const {
	return std::wstring();
}


