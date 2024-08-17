#pragma once

#include "Error.hpp"
#include "Visitor.hpp"
#include "ASTNodes.hpp"

class ASTCheckVisitor : public Visitor {
public:
	ASTCheckVisitor(const std::wstring* string);

	virtual void visitBinaryExpressionNode(ASTNode* node) override;
	virtual void visitBlockNode(ASTNode* node) override;
	virtual void visitBooleanLiteralNode(ASTNode* node) override;
	virtual void visitBreakStatementNode(ASTNode* node) override;
	virtual void visitCallExpressionNode(ASTNode* node) override;
	virtual void visitClassDeclarationNode(ASTNode* node) override;
	virtual void visitDebugStatementNode(ASTNode* node) override;
	virtual void visitEvaluateVariableDeclarationNode(ASTNode* node) override;
	virtual void visitFloatLiteralNode(ASTNode* node) override;
	virtual void visitFunctionDeclarationNode(ASTNode* node) override;
	virtual void visitIdentifierNode(ASTNode* node) override;
	virtual void visitIfStatementNode(ASTNode* node) override;
	virtual void visitIndexExpressionNode(ASTNode* node) override;
	virtual void visitIntegerLiteralNode(ASTNode* node) override;
	virtual void visitMemberFunctionCallExpressionNode(ASTNode* node) override;
	virtual void visitMemberVariableExpressionNode(ASTNode* node) override;
	virtual void visitNormalStatementNode(ASTNode* node) override;
	virtual void visitPrintStatementNode(ASTNode* node) override;
	virtual void visitProgramNode(ASTNode* node) override;
	virtual void visitReturnStatementNode(ASTNode* node) override;
	virtual void visitReverseStatementNode(ASTNode* node) override;
	virtual void visitStringLiteralNode(ASTNode* node) override;
	virtual void visitUnaryExpressionNode(ASTNode* node) override;
	virtual void visitVariableDeclarationNode(ASTNode* node) override;
private:
	int m_depth;

	const std::wstring* m_string;
};