#include "ASTNodes/TimelineEndNode.hpp"

TimelineEndNode::TimelineEndNode(const PositionInfo& pos)
	: ASTNode(ASTNode::TimelineEnd, pos) {

}

TimelineEndNode::TimelineEndNode(const PositionInfo& pos, std::unique_ptr<ASTNode>&& expr)
	: ASTNode(ASTNode::TimelineEnd, pos)
	, expression(std::forward<std::unique_ptr<ASTNode>>(expr)) {

}

void TimelineEndNode::accept(Visitor& visitor) {
	visitor.visitTimelineEndNode(this);
}

std::wstring TimelineEndNode::str() const {
	return std::wstring();
}
