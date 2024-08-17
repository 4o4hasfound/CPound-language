#pragma once
#include <string>

#include "Visitor.hpp"
#include "ASTNodes/ASTNodeBase.hpp"

class IdentifierNode : public ASTNode {
public:
	IdentifierNode(std::wstring::const_iterator pos);
	IdentifierNode(std::wstring::const_iterator pos, const std::wstring& _symbol);

	virtual void accept(Visitor& visitor);
	virtual std::wstring str() const override final;

	std::wstring symbol;
};