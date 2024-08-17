#pragma once
#include <memory>

#include "Visitor.hpp"
#include "ASTNodes/ASTNodeBase.hpp"

class IfStatementNode : public ASTNode {
public:
	IfStatementNode(std::wstring::const_iterator pos);
	IfStatementNode(std::wstring::const_iterator pos, std::unique_ptr<ASTNode>&& _condition, std::unique_ptr<ASTNode>&& _mainBody, std::unique_ptr<ASTNode>&& _elseBody);

	virtual void accept(Visitor& visitor);
	virtual std::wstring str() const override final;

	std::unique_ptr<ASTNode> condition;
	std::unique_ptr<ASTNode> mainBody;
	std::unique_ptr<ASTNode> elseBody;
};