#pragma once

#include "Visitor.hpp"
#include "Types.hpp"

#include "ASTNodes/ASTNodeBase.hpp"

class BooleanLiteralNode : public ASTNode {
public:
	BooleanLiteralNode(const PositionInfo& pos);
	BooleanLiteralNode(const PositionInfo& pos, BooleanType _value);

	virtual void accept(Visitor& visitor);
	virtual std::wstring str() const override final;

	BooleanType value;
};