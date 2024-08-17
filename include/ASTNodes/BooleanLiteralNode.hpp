#pragma once

#include "Visitor.hpp"
#include "Types.hpp"

#include "ASTNodes/ASTNodeBase.hpp"

class BooleanLiteralNode : public ASTNode {
public:
	BooleanLiteralNode(std::wstring::const_iterator pos);
	BooleanLiteralNode(std::wstring::const_iterator pos, BooleanType _value);

	virtual void accept(Visitor& visitor);
	virtual std::wstring str() const override final;

	BooleanType value;
};