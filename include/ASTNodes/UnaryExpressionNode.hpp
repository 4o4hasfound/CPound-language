#pragma once
#include <memory>

#include "Visitor.hpp"
#include "Types.hpp"

#include "ASTNodes/ASTNodeBase.hpp"

class UnaryExpressionNode : public ASTNode {
public:
	UnaryExpressionNode(const PositionInfo& pos);
	UnaryExpressionNode(const PositionInfo& pos, BinaryOperatorType _operatorType);
	UnaryExpressionNode(const PositionInfo& pos, std::unique_ptr<ASTNode>&& expr, BinaryOperatorType _operatorType);

	virtual void accept(Visitor& visitor);
	virtual std::wstring str() const override final;

	std::unique_ptr<ASTNode> expression;
	BinaryOperatorType operatorType;
};