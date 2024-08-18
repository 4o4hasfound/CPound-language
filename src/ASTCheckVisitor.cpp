#include "ASTCheckVisitor.hpp"

ASTCheckVisitor::ASTCheckVisitor(const std::wstring* string)
	: m_depth(0), m_string(string) {

}

void ASTCheckVisitor::visitBinaryExpressionNode(ASTNode* node) {

}

void ASTCheckVisitor::visitBlockNode(ASTNode* node) {
	for (auto& n : dynamic_cast<BlockNode*>(node)->nodes) {
		++m_depth;
		n->accept(*this);
		--m_depth;
	}
}

void ASTCheckVisitor::visitBooleanLiteralNode(ASTNode* node) {

}

void ASTCheckVisitor::visitBreakStatementNode(ASTNode* node) {

}

void ASTCheckVisitor::visitCallExpressionNode(ASTNode* node) {

}

void ASTCheckVisitor::visitClassDeclarationNode(ASTNode* node) {
	if (m_depth > 1) {
		Error::Log(node->position, L"Class declaration cannot uccur outside of global scope", *m_string);
	}
}

void ASTCheckVisitor::visitDebugStatementNode(ASTNode* node) {
	dynamic_cast<DebugStatementNode*>(node)->statement->accept(*this);
}

void ASTCheckVisitor::visitEvaluateVariableDeclarationNode(ASTNode* node) {

}

void ASTCheckVisitor::visitFloatLiteralNode(ASTNode* node) {

}

void ASTCheckVisitor::visitFunctionDeclarationNode(ASTNode* node) {
	if (m_depth > 1) {
		Error::Log(node->position, L"Function declaration cannot occur outside of global scope", *m_string);
	}
	dynamic_cast<FunctionDeclarationNode*>(node)->block->accept(*this);
}

void ASTCheckVisitor::visitIdentifierNode(ASTNode* node) {

}

void ASTCheckVisitor::visitIfStatementNode(ASTNode* node) {
	++m_depth;
	dynamic_cast<IfStatementNode*>(node)->mainBody->accept(*this);
	if (dynamic_cast<IfStatementNode*>(node)->elseBody) {
		dynamic_cast<IfStatementNode*>(node)->elseBody->accept(*this);
	}
	--m_depth;
}

void ASTCheckVisitor::visitIndexExpressionNode(ASTNode* node) {

}

void ASTCheckVisitor::visitInputStatementNode(ASTNode* node) {

}

void ASTCheckVisitor::visitIntegerLiteralNode(ASTNode* node) {

}

void ASTCheckVisitor::visitMemberFunctionCallExpressionNode(ASTNode* node) {

}

void ASTCheckVisitor::visitMemberVariableExpressionNode(ASTNode* node) {

}

void ASTCheckVisitor::visitNormalStatementNode(ASTNode* node) {
	dynamic_cast<NormalStatementNode*>(node)->statement->accept(*this);
}

void ASTCheckVisitor::visitPrintStatementNode(ASTNode* node) {

}

void ASTCheckVisitor::visitProgramNode(ASTNode* node) {
	for (auto& n : dynamic_cast<ProgramNode*>(node)->nodes) {
		++m_depth;
		n->accept(*this);
		--m_depth;
	}
}

void ASTCheckVisitor::visitReturnStatementNode(ASTNode* node) {

}

void ASTCheckVisitor::visitReverseStatementNode(ASTNode* node) {

}

void ASTCheckVisitor::visitStringLiteralNode(ASTNode* node) {

}

void ASTCheckVisitor::visitUnaryExpressionNode(ASTNode* node) {

}

void ASTCheckVisitor::visitVariableDeclarationNode(ASTNode* node) {

}
