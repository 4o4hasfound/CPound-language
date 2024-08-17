#pragma once
#include <vector>

#include "Types.hpp"
#include "ASTNodes/ASTNodeBase.hpp"

class VariableDeclarationNode : public ASTNode {
public:
	VariableDeclarationNode(std::wstring::const_iterator pos);

	virtual void accept(Visitor& visitor);
	virtual std::wstring str() const override final;

	std::vector<VariableDeclarationInfo> declarations;
};