#include "ASTNodes/StatementNode.hpp"

StatementNode::StatementNode(ASTNode::ASTNodeType nodeType, const PositionInfo& pos)
	: ASTNode(nodeType, pos) {

}

StatementNode::StatementNode(ASTNode::ASTNodeType nodeType, std::unique_ptr<ASTNode>&& _statement, const PositionInfo& pos)
	: ASTNode(nodeType, pos)
	, statement(std::forward<std::unique_ptr<ASTNode>>(_statement)) {

}