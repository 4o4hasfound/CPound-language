#pragma once
#include <string>
#include <memory>

#include "Visitor.hpp"
#include "ASTNodes/ASTNodeBase.hpp"

class TimelinePruneNode : public ASTNode {
public:
	TimelinePruneNode(const PositionInfo& pos);
	TimelinePruneNode(const PositionInfo& pos, std::unique_ptr<ASTNode>&& expr);

	virtual void accept(Visitor& visitor);
	virtual std::wstring str() const override final;

	std::unique_ptr<ASTNode> expression;
};