#include "ASTNodes/TimelineInsertNode.hpp"

TimelineInsertNode::TimelineInsertNode(const PositionInfo& pos)
	: ASTNode(ASTNode::Past, pos) {

}

TimelineInsertNode::TimelineInsertNode(const PositionInfo& pos, std::unique_ptr<ASTNode>&& expr)
	: ASTNode(ASTNode::Past, pos)
	, expression(std::forward<std::unique_ptr<ASTNode>>(expr)) {

}

void TimelineInsertNode::accept(Visitor& visitor) {
	visitor.visitTimelineInsertNode(this);
}

std::wstring TimelineInsertNode::str() const {
	return std::wstring();
}
