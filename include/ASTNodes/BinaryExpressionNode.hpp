#pragma once
#include <memory>

#include "Visitor.hpp"
#include "Types.hpp"

#include "ASTNodes/ASTNodeBase.hpp"

class BinaryExpressionNode : public ASTNode {
public:
	BinaryExpressionNode(std::wstring::const_iterator pos);
	BinaryExpressionNode(std::wstring::const_iterator pos, BinaryOperatorType _type);
	BinaryExpressionNode(std::wstring::const_iterator pos, std::unique_ptr<ASTNode>&& lexpr, std::unique_ptr<ASTNode>&& rexpr, BinaryOperatorType _type);

	virtual void accept(Visitor& visitor);
	virtual std::wstring str() const override final;

	std::unique_ptr<ASTNode> LExpression;
	std::unique_ptr<ASTNode> RExpression;
	BinaryOperatorType operatorType;
};