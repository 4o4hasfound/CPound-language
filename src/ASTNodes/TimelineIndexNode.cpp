#include "ASTNodes/TimelineIndexNode.hpp"

TimelineIndexNode::TimelineIndexNode(const PositionInfo& pos)
	: ASTNode(ASTNode::TimelineIndex, pos) {

}

TimelineIndexNode::TimelineIndexNode(const PositionInfo& pos, std::unique_ptr<ASTNode>&& expr)
	: ASTNode(ASTNode::TimelineIndex, pos)
	, expression(std::forward<std::unique_ptr<ASTNode>>(expr)) {

}

void TimelineIndexNode::accept(Visitor& visitor) {
	visitor.visitTimelineIndexNode(this);
}

std::wstring TimelineIndexNode::str() const {
	return std::wstring();
}
