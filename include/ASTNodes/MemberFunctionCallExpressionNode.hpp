#pragma once
#include <memory>

#include "Visitor.hpp"
#include "ASTNodes/ASTNodeBase.hpp"
#include "ASTNodes/CallExpressionNode.hpp"

class MemberFunctionCallExpressionNode : public ASTNode {
public:
	MemberFunctionCallExpressionNode(const PositionInfo& pos);
	MemberFunctionCallExpressionNode(const PositionInfo& pos, const std::wstring& _symbol, std::unique_ptr<CallExpressionNode>&& expr);

	virtual void accept(Visitor& visitor);
	virtual std::wstring str() const override final;

	std::wstring symbol;
	std::unique_ptr<CallExpressionNode> callExpr;
};