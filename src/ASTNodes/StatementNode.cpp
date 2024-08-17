#include "ASTNodes/StatementNode.hpp"

StatementNode::StatementNode(ASTNode::ASTNodeType nodeType, std::wstring::const_iterator pos)
	: ASTNode(nodeType, pos) {

}

StatementNode::StatementNode(ASTNode::ASTNodeType nodeType, std::unique_ptr<ASTNode>&& _statement, std::wstring::const_iterator pos)
	: ASTNode(nodeType, pos)
	, statement(std::forward<std::unique_ptr<ASTNode>>(_statement)) {

}