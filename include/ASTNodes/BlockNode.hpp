#pragma once
#include <memory>
#include <vector>
#include <string>

#include "Visitor.hpp"
#include "ASTNodes/ASTNodeBase.hpp"

class BlockNode : public ASTNode {
public:
	BlockNode(const PositionInfo& pos);

	virtual void accept(Visitor& visitor);
	virtual std::wstring str() const override final;

	std::vector<std::unique_ptr<ASTNode>> nodes;
};