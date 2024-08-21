#pragma once
#include <string>
#include <memory>

#include "Visitor.hpp"
#include "ASTNodes/ASTNodeBase.hpp"

class IndexExpressionNode : public ASTNode {
public:
	IndexExpressionNode(const PositionInfo& pos);
	IndexExpressionNode(const PositionInfo& pos, const std::wstring& _symbol);
	IndexExpressionNode(const PositionInfo& pos, const std::wstring& _symbol, std::unique_ptr<ASTNode>&& expr);

	virtual void accept(Visitor& visitor);
	virtual std::wstring str() const override final;

	std::wstring symbol;
	std::unique_ptr<ASTNode> expression;
};