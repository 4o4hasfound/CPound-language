#pragma once
#include <memory>
#include <vector>
#include <string>

#include "Types.hpp"

#include "Visitor.hpp"
#include "ASTNodes/ASTNodeBase.hpp"

class ClassDeclarationNode : public ASTNode {
public:
	ClassDeclarationNode(const PositionInfo& pos);
	ClassDeclarationNode(const PositionInfo& pos, const std::wstring& symbol);
	ClassDeclarationNode(const PositionInfo& pos, const std::wstring& symbol, const std::wstring& parentSymbol);

	virtual void accept(Visitor& visitor);
	virtual std::wstring str() const override final;

	ClassDeclarationInfo declaration;
};