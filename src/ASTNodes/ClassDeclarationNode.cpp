#include "ASTNodes/ClassDeclarationNode.hpp"

ClassDeclarationNode::ClassDeclarationNode(std::wstring::const_iterator pos)
	: ASTNode(ASTNode::ClassDeclaration, pos) {

}

ClassDeclarationNode::ClassDeclarationNode(std::wstring::const_iterator pos, const std::wstring& symbol)
	: ASTNode(ASTNode::ClassDeclaration, pos)
	, declaration(symbol) {

}

ClassDeclarationNode::ClassDeclarationNode(std::wstring::const_iterator pos, const std::wstring& symbol, const std::wstring& parentSymbol)
	: ASTNode(ASTNode::ClassDeclaration, pos)
	, declaration(symbol, parentSymbol) {

}

void ClassDeclarationNode::accept(Visitor& visitor) {
	visitor.visitClassDeclarationNode(this);
}

std::wstring ClassDeclarationNode::str() const {
	return std::wstring();
}
