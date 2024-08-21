#pragma once
#include <string>
#include <memory>

#include "Visitor.hpp"
#include "ASTNodes/ASTNodeBase.hpp"

class TimelineEndNode : public ASTNode {
public:
	TimelineEndNode(const PositionInfo& pos);
	TimelineEndNode(const PositionInfo& pos, std::unique_ptr<ASTNode>&& expr);

	virtual void accept(Visitor& visitor);
	virtual std::wstring str() const override final;

	std::unique_ptr<ASTNode> expression;
};