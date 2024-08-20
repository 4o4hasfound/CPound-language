#include "ASTNodes/TimelinePruneNode.hpp"

TimelinePruneNode::TimelinePruneNode(std::wstring::const_iterator pos)
	: ASTNode(ASTNode::TimelinePrune, pos) {

}

TimelinePruneNode::TimelinePruneNode(std::wstring::const_iterator pos, std::unique_ptr<ASTNode>&& expr)
	: ASTNode(ASTNode::TimelinePrune, pos)
	, expression(std::forward<std::unique_ptr<ASTNode>>(expr)) {

}

void TimelinePruneNode::accept(Visitor& visitor) {
	visitor.visitTimelinePruneNode(this);
}

std::wstring TimelinePruneNode::str() const {
	return std::wstring();
}
