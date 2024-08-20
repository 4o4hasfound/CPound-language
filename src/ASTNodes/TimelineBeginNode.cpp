#include "ASTNodes/TimelineBeginNode.hpp"

TimelineBeginNode::TimelineBeginNode(std::wstring::const_iterator pos)
	: ASTNode(ASTNode::TimelineBegin, pos) {

}

TimelineBeginNode::TimelineBeginNode(std::wstring::const_iterator pos, std::unique_ptr<ASTNode>&& expr)
	: ASTNode(ASTNode::TimelineBegin, pos)
	, expression(std::forward<std::unique_ptr<ASTNode>>(expr)) {

}

void TimelineBeginNode::accept(Visitor& visitor) {
	visitor.visitTimelineBeginNode(this);
}

std::wstring TimelineBeginNode::str() const {
	return std::wstring();
}
