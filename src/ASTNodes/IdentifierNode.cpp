#include "ASTNodes/IdentifierNode.hpp"

IdentifierNode::IdentifierNode(std::wstring::const_iterator pos)
	: ASTNode(ASTNode::Identifier, pos)
	, symbol(L"") {
}

IdentifierNode::IdentifierNode(std::wstring::const_iterator pos, const std::wstring& _symbol)
	: ASTNode(ASTNode::Identifier, pos)
	, symbol(_symbol) {

}

void IdentifierNode::accept(Visitor& visitor) {
	visitor.visitIdentifierNode(this);
}

std::wstring IdentifierNode::str() const {
	return std::wstring();
}
