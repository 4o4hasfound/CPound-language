#pragma once
#include <memory>

#include "Visitor.hpp"
#include "ASTNodes/ASTNodeBase.hpp"

class StatementNode : public ASTNode {
public:
	StatementNode(ASTNode::ASTNodeType nodeType, std::wstring::const_iterator pos);
	StatementNode(ASTNode::ASTNodeType nodeType, std::unique_ptr<ASTNode>&& _statement, std::wstring::const_iterator pos);

	virtual void accept(Visitor& visitor) = 0;
	virtual std::wstring str() const = 0;

	std::unique_ptr<ASTNode> statement;
};