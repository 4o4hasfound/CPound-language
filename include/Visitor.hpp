#pragma once

class ASTNode;

class Visitor {
public:
	Visitor() = default;

	virtual void visitBinaryExpressionNode(ASTNode* node) = 0;
	virtual void visitBlockNode(ASTNode* node) = 0;
	virtual void visitBooleanLiteralNode(ASTNode* node) = 0;
	virtual void visitBreakStatementNode(ASTNode* node) = 0;
	virtual void visitCallExpressionNode(ASTNode* node) = 0;
	virtual void visitClassDeclarationNode(ASTNode* node) = 0;
	virtual void visitDebugStatementNode(ASTNode* node) = 0;
	virtual void visitEvaluateVariableDeclarationNode(ASTNode* node) = 0;
	virtual void visitFloatLiteralNode(ASTNode* node) = 0;
	virtual void visitFunctionDeclarationNode(ASTNode* node) = 0;
	virtual void visitIdentifierNode(ASTNode* node) = 0;
	virtual void visitIfStatementNode(ASTNode* node) = 0;
	virtual void visitIndexExpressionNode(ASTNode* node) = 0;
	virtual void visitInputStatementNode(ASTNode* node) = 0;
	virtual void visitIntegerLiteralNode(ASTNode* node) = 0;
	virtual void visitMemberFunctionCallExpressionNode(ASTNode* node) = 0;
	virtual void visitMemberVariableExpressionNode(ASTNode* node) = 0;
	virtual void visitNormalStatementNode(ASTNode* node) = 0;
	virtual void visitPrintStatementNode(ASTNode* node) = 0;
	virtual void visitProgramNode(ASTNode* node) = 0;
	virtual void visitReturnStatementNode(ASTNode* node) = 0;
	virtual void visitReverseStatementNode(ASTNode* node) = 0;
	virtual void visitStringLiteralNode(ASTNode* node) = 0;
	virtual void visitUnaryExpressionNode(ASTNode* node) = 0;
	virtual void visitVariableDeclarationNode(ASTNode* node) = 0;
};