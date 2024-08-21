#pragma once
#include <memory>

#include "Visitor.hpp"
#include "ASTNodes/ASTNodeBase.hpp"
#include "ASTNodes/StatementNode.hpp"

class NormalStatementNode : public StatementNode {
public:
	NormalStatementNode(const PositionInfo& pos);
	NormalStatementNode(const PositionInfo& pos, std::unique_ptr<ASTNode>&& _node);

	virtual void accept(Visitor& visitor);
	virtual std::wstring str() const override final;
};