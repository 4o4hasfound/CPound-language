#pragma once
#include <memory>
#include <vector>
#include <string>

#include "Types.hpp"

#include "Visitor.hpp"
#include "ASTNodes/ASTNodeBase.hpp"

class ClassDeclarationNode : public ASTNode {
public:
	ClassDeclarationNode(std::wstring::const_iterator pos);
	ClassDeclarationNode(std::wstring::const_iterator pos, const std::wstring& symbol);
	ClassDeclarationNode(std::wstring::const_iterator pos, const std::wstring& symbol, const std::wstring& parentSymbol);

	virtual void accept(Visitor& visitor);
	virtual std::wstring str() const override final;

	ClassDeclarationInfo declaration;
};