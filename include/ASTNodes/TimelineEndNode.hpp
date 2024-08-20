#pragma once
#include <string>
#include <memory>

#include "Visitor.hpp"
#include "ASTNodes/ASTNodeBase.hpp"

class TimelineEndNode : public ASTNode {
public:
	TimelineEndNode(std::wstring::const_iterator pos);
	TimelineEndNode(std::wstring::const_iterator pos, std::unique_ptr<ASTNode>&& expr);

	virtual void accept(Visitor& visitor);
	virtual std::wstring str() const override final;

	std::unique_ptr<ASTNode> expression;
};