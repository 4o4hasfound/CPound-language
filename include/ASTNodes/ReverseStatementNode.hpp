#pragma once

#include "Visitor.hpp"
#include "ASTNodes/ASTNodeBase.hpp"

class ReverseStatementNode : public ASTNode {
public:
	ReverseStatementNode(const PositionInfo& pos);

	virtual void accept(Visitor& visitor);
	virtual std::wstring str() const override final;
};