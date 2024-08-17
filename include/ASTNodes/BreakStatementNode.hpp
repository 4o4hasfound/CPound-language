#pragma once

#include "Visitor.hpp"
#include "ASTNodes/ASTNodeBase.hpp"

class BreakStatementNode : public ASTNode {
public:
	BreakStatementNode(std::wstring::const_iterator pos);

	virtual void accept(Visitor& visitor);
	virtual std::wstring str() const override final;
};