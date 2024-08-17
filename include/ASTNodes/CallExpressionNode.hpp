#pragma once
#include <memory>
#include <vector>

#include "Visitor.hpp"
#include "ASTNodes/ASTNodeBase.hpp"

class CallExpressionNode : public ASTNode {
public:
	CallExpressionNode(std::wstring::const_iterator pos);
	CallExpressionNode(std::wstring::const_iterator pos, const std::wstring& functionSymbol);

	virtual void accept(Visitor& visitor);
	virtual std::wstring str() const override final;

	std::wstring symbol;
	std::vector<std::unique_ptr<ASTNode>> arguments;
};