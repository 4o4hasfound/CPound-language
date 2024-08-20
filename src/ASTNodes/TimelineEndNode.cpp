#include "ASTNodes/TimelineEndNode.hpp"

TimelineEndNode::TimelineEndNode(std::wstring::const_iterator pos)
	: ASTNode(ASTNode::TimelineEnd, pos) {

}

TimelineEndNode::TimelineEndNode(std::wstring::const_iterator pos, std::unique_ptr<ASTNode>&& expr)
	: ASTNode(ASTNode::TimelineEnd, pos)
	, expression(std::forward<std::unique_ptr<ASTNode>>(expr)) {

}

void TimelineEndNode::accept(Visitor& visitor) {
	visitor.visitTimelineEndNode(this);
}

std::wstring TimelineEndNode::str() const {
	return std::wstring();
}
