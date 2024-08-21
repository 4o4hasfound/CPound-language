#include "ASTNodes/ProgramNode.hpp"

ProgramNode::ProgramNode(const PositionInfo& pos)
	: ASTNode(ASTNode::Program, pos) {

}

void ProgramNode::accept(Visitor& visitor) {
	visitor.visitProgramNode(this);
}

std::wstring ProgramNode::str() const {
	return std::wstring();
}
