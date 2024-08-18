#pragma once
#include <memory>
#include <vector>

#include "Visitor.hpp"
#include "ASTNodes/ASTNodeBase.hpp"

class InputStatementNode : public ASTNode {
public:
	InputStatementNode(std::wstring::const_iterator pos);

	virtual void accept(Visitor& visitor);
	virtual std::wstring str() const override final;

	std::vector<std::unique_ptr<ASTNode>> expressions;
};