#pragma once

#include "Visitor.hpp"
#include "Types.hpp"

#include "ASTNodes/BlockNode.hpp"
#include "ASTNodes/ASTNodeBase.hpp"

class FunctionDeclarationNode : public ASTNode {
public:
	FunctionDeclarationNode(std::wstring::const_iterator pos);
	FunctionDeclarationNode(std::wstring::const_iterator pos, const std::wstring& _symbol);
	FunctionDeclarationNode(std::wstring::const_iterator pos, const std::wstring& _symbol, VariableDeclarationType retDeclType, const std::wstring& retType);
	FunctionDeclarationNode(std::wstring::const_iterator pos, const std::wstring& _symbol, VariableDeclarationType retDeclType, const std::wstring& retType, std::unique_ptr<ASTNode>&& _block);

	virtual void accept(Visitor& visitor);
	virtual std::wstring str() const override final;

	FunctionDeclarationInfo declaration;
	std::unique_ptr<ASTNode> block;
};