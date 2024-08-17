#pragma once
#include <memory>

#include "Visitor.hpp"
#include "Types.hpp"

#include "ASTNodes/ASTNodeBase.hpp"

class UnaryExpressionNode : public ASTNode {
public:
	UnaryExpressionNode(std::wstring::const_iterator pos);
	UnaryExpressionNode(std::wstring::const_iterator pos, BinaryOperatorType _operatorType);
	UnaryExpressionNode(std::wstring::const_iterator pos, std::unique_ptr<ASTNode>&& expr, BinaryOperatorType _operatorType);

	virtual void accept(Visitor& visitor);
	virtual std::wstring str() const override final;

	std::unique_ptr<ASTNode> expression;
	BinaryOperatorType operatorType;
};