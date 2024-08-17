#include "ASTNodes/ASTNodeBase.hpp"

ASTNode::ASTNode(ASTNodeType nodeType, std::wstring::const_iterator pos)
	: type(nodeType), position(pos) {

}
