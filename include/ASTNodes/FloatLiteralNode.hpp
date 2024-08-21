#pragma once

#include "Visitor.hpp"
#include "ASTNodes/ASTNodeBase.hpp"

class FloatLiteralNode : public ASTNode {
public:
	FloatLiteralNode(const PositionInfo& pos);
	FloatLiteralNode(const PositionInfo& pos, double _value);

	virtual void accept(Visitor& visitor);
	virtual std::wstring str() const override final;

	double value;
};