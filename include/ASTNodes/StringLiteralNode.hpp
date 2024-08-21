#pragma once

#include "Visitor.hpp"
#include "ASTNodes/ASTNodeBase.hpp"

class StringLiteralNode : public ASTNode {
public:
	StringLiteralNode(const PositionInfo& pos);
	StringLiteralNode(const PositionInfo& pos, const std::wstring& string);

	virtual void accept(Visitor& visitor);
	virtual std::wstring str() const override final;

	std::wstring value;
};