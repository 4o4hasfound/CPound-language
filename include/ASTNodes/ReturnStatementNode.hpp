#pragma once
#include <string>
#include <memory>

#include "Visitor.hpp"
#include "ASTNodes/ASTNodeBase.hpp"

class ReturnStatementNode : public ASTNode {
public:
	ReturnStatementNode(std::wstring::const_iterator pos);
	ReturnStatementNode(std::wstring::const_iterator pos, std::unique_ptr<ASTNode>&& expr);

	virtual void accept(Visitor& visitor);
	virtual std::wstring str() const override final;

	std::unique_ptr<ASTNode> expression;
};