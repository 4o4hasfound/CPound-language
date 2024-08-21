#pragma once
#include <memory>

#include "Visitor.hpp"
#include "Types.hpp"

#include "ASTNodes/ASTNodeBase.hpp"

class BinaryExpressionNode : public ASTNode {
public:
	BinaryExpressionNode(const PositionInfo& pos);
	BinaryExpressionNode(const PositionInfo& pos, BinaryOperatorType _type);
	BinaryExpressionNode(const PositionInfo& pos, std::unique_ptr<ASTNode>&& lexpr, std::unique_ptr<ASTNode>&& rexpr, BinaryOperatorType _type);

	virtual void accept(Visitor& visitor);
	virtual std::wstring str() const override final;

	std::unique_ptr<ASTNode> LExpression;
	std::unique_ptr<ASTNode> RExpression;
	BinaryOperatorType operatorType;
};