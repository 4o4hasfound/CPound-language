#include "ASTNodes/ASTNodeBase.hpp"

ASTNode::ASTNode(ASTNodeType nodeType, const PositionInfo& pos)
	: type(nodeType), position(pos) {

}
