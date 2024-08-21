#pragma once

#include "Visitor.hpp"
#include "ASTNodes/ASTNodeBase.hpp"

class IntegerLiteralNode : public ASTNode {
public:
	IntegerLiteralNode(const PositionInfo& pos);
	IntegerLiteralNode(const PositionInfo& pos, int64_t _value);

	virtual void accept(Visitor& visitor);
	virtual std::wstring str() const override final;

	int64_t value;
};