#pragma once
#include <memory>
#include <string>
#include <sstream>

#include "Error.hpp"
#include "Value.hpp"
#include "Scope.hpp"
#include "Random.hpp"
#include "Visitor.hpp"
#include "ASTNodes.hpp"
#include "BuiltinTypes.hpp"

class Interpreter : private Visitor {
public:
	Interpreter(const std::wstring* string);

	void run(ProgramNode* node);

private:
	const std::wstring* m_string;
	Scope m_scope;
	std::shared_ptr<Value> m_tmpValue;
	bool m_break = 0, m_return = 0, m_dontMakeNewScope = 0, m_reverse = 0;

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

	std::shared_ptr<Value> getExpressionValue(ASTNode* node);
	void doBinaryOperation(const std::shared_ptr<Value>& l, const std::shared_ptr<Value>& r, OperatorType type);
	void doUnaryOperation(const std::shared_ptr<Value>& l, OperatorType type);

	void updateValue(const std::shared_ptr<Value>& value = nullptr);

	int advanceIndex(int index) const;
	int getInitialIndex(int size) const;
};