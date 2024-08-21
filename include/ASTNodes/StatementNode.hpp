#pragma once
#include <memory>

#include "Visitor.hpp"
#include "ASTNodes/ASTNodeBase.hpp"

class StatementNode : public ASTNode {
public:
	StatementNode(ASTNode::ASTNodeType nodeType, const PositionInfo& pos);
	StatementNode(ASTNode::ASTNodeType nodeType, std::unique_ptr<ASTNode>&& _statement, const PositionInfo& pos);

	virtual void accept(Visitor& visitor) = 0;
	virtual std::wstring str() const = 0;

	std::unique_ptr<ASTNode> statement;
};