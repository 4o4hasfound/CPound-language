#pragma once
#include <memory>

#include "Visitor.hpp"
#include "ASTNodes/ASTNodeBase.hpp"
#include "ASTNodes/StatementNode.hpp"

class DebugStatementNode : public StatementNode {
public:
	DebugStatementNode(const PositionInfo& pos);
	DebugStatementNode(const PositionInfo& pos, std::unique_ptr<ASTNode>&& _statement);

	virtual void accept(Visitor& visitor);
	virtual std::wstring str() const override final;
};