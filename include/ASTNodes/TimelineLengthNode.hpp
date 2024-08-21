#pragma once
#include <string>
#include <memory>

#include "Visitor.hpp"
#include "ASTNodes/ASTNodeBase.hpp"

class TimelineLengthNode : public ASTNode {
public:
	TimelineLengthNode(const PositionInfo& pos);
	TimelineLengthNode(const PositionInfo& pos, std::unique_ptr<ASTNode>&& expr);

	virtual void accept(Visitor& visitor);
	virtual std::wstring str() const override final;

	std::unique_ptr<ASTNode> expression;
};