#pragma once
#include <memory>

#include "Visitor.hpp"
#include "ASTNodes/ASTNodeBase.hpp"
#include "ASTNodes/CallExpressionNode.hpp"

class MemberVariableExpressionNode : public ASTNode {
public:
	MemberVariableExpressionNode(std::wstring::const_iterator pos);
	MemberVariableExpressionNode(std::wstring::const_iterator pos, const std::wstring& _symbol, const std::wstring& _variableSymbol);

	virtual void accept(Visitor& visitor);
	virtual std::wstring str() const override final;

	std::wstring symbol;
	std::wstring variableSymbol;
};