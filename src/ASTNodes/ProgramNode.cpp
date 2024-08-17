#include "ASTNodes/ProgramNode.hpp"

ProgramNode::ProgramNode(std::wstring::const_iterator pos)
	: ASTNode(ASTNode::Program, pos) {

}

void ProgramNode::accept(Visitor& visitor) {
	visitor.visitProgramNode(this);
}

std::wstring ProgramNode::str() const {
	return std::wstring();
}
