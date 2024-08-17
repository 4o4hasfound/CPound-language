#pragma once
#include <memory>

#include "Visitor.hpp"
#include "ASTNodes/ASTNodeBase.hpp"
#include "ASTNodes/StatementNode.hpp"

class DebugStatementNode : public StatementNode {
public:
	DebugStatementNode(std::wstring::const_iterator pos);
	DebugStatementNode(std::wstring::const_iterator pos, std::unique_ptr<ASTNode>&& _statement);

	virtual void accept(Visitor& visitor);
	virtual std::wstring str() const override final;
};