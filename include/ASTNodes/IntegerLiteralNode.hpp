#pragma once

#include "Visitor.hpp"
#include "ASTNodes/ASTNodeBase.hpp"

class IntegerLiteralNode : public ASTNode {
public:
	IntegerLiteralNode(std::wstring::const_iterator pos);
	IntegerLiteralNode(std::wstring::const_iterator pos, int64_t _value);

	virtual void accept(Visitor& visitor);
	virtual std::wstring str() const override final;

	int64_t value;
};