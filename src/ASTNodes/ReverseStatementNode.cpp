#include "ASTNodes/ReverseStatementNode.hpp"

ReverseStatementNode::ReverseStatementNode(std::wstring::const_iterator pos)
	: ASTNode(ASTNode::ReverseStatement, pos) {

}

void ReverseStatementNode::accept(Visitor& visitor) {
	visitor.visitReverseStatementNode(this);
}

std::wstring ReverseStatementNode::str() const {
	return std::wstring();
}
