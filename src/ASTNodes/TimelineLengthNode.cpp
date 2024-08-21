#include "ASTNodes/TimelineLengthNode.hpp"

TimelineLengthNode::TimelineLengthNode(const PositionInfo& pos)
	: ASTNode(ASTNode::TimelineLength, pos) {

}

TimelineLengthNode::TimelineLengthNode(const PositionInfo& pos, std::unique_ptr<ASTNode>&& expr)
	: ASTNode(ASTNode::TimelineLength, pos)
	, expression(std::forward<std::unique_ptr<ASTNode>>(expr)) {

}

void TimelineLengthNode::accept(Visitor& visitor) {
	visitor.visitTimelineLengthNode(this);
}

std::wstring TimelineLengthNode::str() const {
	return std::wstring();
}
