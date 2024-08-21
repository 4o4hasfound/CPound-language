#pragma once
#include <memory>

#include "Visitor.hpp"
#include "ASTNodes/ASTNodeBase.hpp"
#include "ASTNodes/CallExpressionNode.hpp"

class PrintStatementNode : public ASTNode {
public:
	PrintStatementNode(const PositionInfo& pos);

	virtual void accept(Visitor& visitor);
	virtual std::wstring str() const override final;

	std::vector<std::unique_ptr<ASTNode>> expressions;
};