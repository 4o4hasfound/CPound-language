#include "ASTNodes/TimelineInsertNode.hpp"

TimelineInsertNode::TimelineInsertNode(std::wstring::const_iterator pos)
	: ASTNode(ASTNode::Past, pos) {

}

TimelineInsertNode::TimelineInsertNode(std::wstring::const_iterator pos, std::unique_ptr<ASTNode>&& expr)
	: ASTNode(ASTNode::Past, pos)
	, expression(std::forward<std::unique_ptr<ASTNode>>(expr)) {

}

void TimelineInsertNode::accept(Visitor& visitor) {
	visitor.visitTimelineInsertNode(this);
}

std::wstring TimelineInsertNode::str() const {
	return std::wstring();
}
