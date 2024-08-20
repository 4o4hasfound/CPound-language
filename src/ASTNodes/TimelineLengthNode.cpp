#include "ASTNodes/TimelineLengthNode.hpp"

TimelineLengthNode::TimelineLengthNode(std::wstring::const_iterator pos)
	: ASTNode(ASTNode::TimelineLength, pos) {

}

TimelineLengthNode::TimelineLengthNode(std::wstring::const_iterator pos, std::unique_ptr<ASTNode>&& expr)
	: ASTNode(ASTNode::TimelineLength, pos)
	, expression(std::forward<std::unique_ptr<ASTNode>>(expr)) {

}

void TimelineLengthNode::accept(Visitor& visitor) {
	visitor.visitTimelineLengthNode(this);
}

std::wstring TimelineLengthNode::str() const {
	return std::wstring();
}
