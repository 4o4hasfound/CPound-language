#pragma once

#include "Visitor.hpp"
#include "ASTNodes/ASTNodeBase.hpp"

class StringLiteralNode : public ASTNode {
public:
	StringLiteralNode(std::wstring::const_iterator pos);
	StringLiteralNode(std::wstring::const_iterator pos, const std::wstring& string);

	virtual void accept(Visitor& visitor);
	virtual std::wstring str() const override final;

	std::wstring value;
};