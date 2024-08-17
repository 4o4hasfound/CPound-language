#pragma once
#include <string>
#include <memory>

#include "Visitor.hpp"
#include "ASTNodes/ASTNodeBase.hpp"

class IndexExpressionNode : public ASTNode {
public:
	IndexExpressionNode(std::wstring::const_iterator pos);
	IndexExpressionNode(std::wstring::const_iterator pos, const std::wstring& _symbol);
	IndexExpressionNode(std::wstring::const_iterator pos, const std::wstring& _symbol, std::unique_ptr<ASTNode>&& expr);

	virtual void accept(Visitor& visitor);
	virtual std::wstring str() const override final;

	std::wstring symbol;
	std::unique_ptr<ASTNode> expression;
};