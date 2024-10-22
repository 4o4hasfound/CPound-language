#include "ASTNodes/PrintStatementNode.hpp"

PrintStatementNode::PrintStatementNode(const PositionInfo& pos)
	: ASTNode(ASTNode::PrintStatement, pos) {

}

void PrintStatementNode::accept(Visitor& visitor) {
	visitor.visitPrintStatementNode(this);
}

std::wstring PrintStatementNode::str() const {
	return std::wstring();
}
