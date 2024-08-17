#pragma once
#include <vector>
#include <memory>
#include <string>

#include "Types.hpp"
#include "Visitor.hpp"
#include "ASTNodes/ASTNodeBase.hpp"

class EvaluateVariableDeclarationNode : public ASTNode {
public:
	EvaluateVariableDeclarationNode(std::wstring::const_iterator pos);
	EvaluateVariableDeclarationNode(std::wstring::const_iterator pos, std::wstring type, std::wstring symbol);
	EvaluateVariableDeclarationNode(std::wstring::const_iterator pos, std::wstring type, std::wstring symbol, std::unique_ptr<ASTNode>&& value);

	virtual void accept(Visitor& visitor);
	virtual std::wstring str() const override final;

	EvaluateVariableDeclarationInfo declaration;
};