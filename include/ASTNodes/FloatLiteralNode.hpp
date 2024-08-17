#pragma once

#include "Visitor.hpp"
#include "ASTNodes/ASTNodeBase.hpp"

class FloatLiteralNode : public ASTNode {
public:
	FloatLiteralNode(std::wstring::const_iterator pos);
	FloatLiteralNode(std::wstring::const_iterator pos, double _value);

	virtual void accept(Visitor& visitor);
	virtual std::wstring str() const override final;

	double value;
};