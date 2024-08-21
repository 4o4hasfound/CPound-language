#include "Value.hpp"

Value::Value()
	: createTimePoint(std::chrono::high_resolution_clock::now()) {

}

Value::Value(Value* ref)
	: reference(true)
	, type(ref->type)
	, editable(ref->editable)
	, reassignable(ref->reassignable)
	, overridable(ref->overridable)
	, lifetime(ref->lifetime)
	, priority(ref->priority)
	, index(0)
	, createTimePoint(std::chrono::high_resolution_clock::now()) {
	if (ref->reference) {
		value = std::make_shared<std::vector<std::any>>(1, ref->getReferenceObject());
	}
	else {
		value = std::make_shared<std::vector<std::any>>(1, ref);
	}
}

Value::Value(const std::wstring& _type, const std::any& _value)
	: type(_type)
	, value(std::make_shared<std::vector<std::any>>(1, _value))
	, index(0)
	, createTimePoint(std::chrono::high_resolution_clock::now()) {

}

bool Value::setDeclType(VariableDeclarationType _type) {
	bool _editable = 1, _reassignable = 1, _overridable = 1;
	switch (_type) {
	case VariableDeclarationType::VarVarVar:
		_editable = _reassignable = _overridable = true;
		break;
	case VariableDeclarationType::VarVarConst:
		_editable = _reassignable = true;
		_overridable = false;
		break;
	case VariableDeclarationType::VarConstVar:
		_editable = _overridable = true;
		_reassignable = false;
		break;
	case VariableDeclarationType::VarConstConst:
		_editable = true;
		_reassignable = _overridable = false;
		break;
	case VariableDeclarationType::ConstVarVar:
		_editable = false;
		_reassignable = _overridable = true;
		break;
	case VariableDeclarationType::ConstVarConst:
		_editable = _overridable = false;
		_reassignable = true;
		break;
	case VariableDeclarationType::ConstConstVar:
		_editable = _reassignable = false;
		_overridable = true;
		break;
	case VariableDeclarationType::ConstConstConst:
		_editable = _reassignable = _overridable = false;
		break;
	}

	// For reference, declaration type can only be var -> const, not the other way around
	if (reference 
		&& ((!editable && _editable)
		|| (!reassignable && _reassignable)
		|| (!overridable && _overridable))) {
		return false;
	}
	editable = _editable;
	reassignable = _reassignable;
	overridable = _overridable;
	return true;
}

bool Value::isVoid() const {
	if ((*value).size() && index >= 0 && index < (*value).size()) {
		return false;
	}
	return true;
}

bool Value::isValid(ASTNode* node) const {
	return isValidTime(node) && isValidLine(node);
}

bool Value::isValidTime(ASTNode* node) const {
	auto time = (std::chrono::high_resolution_clock::now() - createTimePoint);
	auto elapse = std::chrono::duration_cast<std::chrono::milliseconds>(time).count();

	if (static_cast<double>(elapse) * 0.001 > lifetime.second) {
		return false;
	}
	return true;
}

bool Value::isValidLine(ASTNode* node) const {
	int delta = node->position.lineIndex - createLineIndex;
	if (delta > 0) {
		if ((delta > lifetime.forwardLine)) {
			return false;
		}
		return true;
	}
	else {
		if ((std::abs(delta) > lifetime.backwardLine)) {
			return false;
		}
		return true;
	}
}

void Value::past() {
	if (reference) {
		std::any_cast<Value*>((*value)[index])->past();
	}
	else {
		--index;
	}
}
void Value::future() {
	if (reference) {
		std::any_cast<Value*>((*value)[index])->future();
	}
	else {
		++index;
	}
}

void Value::begin() {
	if (reference) {
		std::any_cast<Value*>((*value)[index])->begin();
	}
	else {
		index = 0;
	}
}

void Value::end() {
	if (reference) {
		std::any_cast<Value*>((*value)[index])->end();
	}
	else {
		index = value->size() - 1;
	}
}

void Value::timelineInsert() {
	if ((*value).size() && index < 0 || index > (*value).size() || (*value)[index].type() == typeid(std::nullptr_t)) {
		throw std::runtime_error("Variable is void, timeline index " + std::to_string(index) + " isn't available");
	}
	if (reference) {
		std::any_cast<Value*>((*value)[index])->timelineInsert();
	}
	else {
		value->insert(value->begin() + index, getDefaultValue());
	}
}

void Value::timelinePrune() {
	if (isVoid()) {
		throw std::runtime_error("Variable is void");
	}
	if (reference) {
		std::any_cast<Value*>((*value)[index])->timelinePrune();
	}
	else {
		value->erase(value->begin() + index);
	}
}

int64_t Value::getIndex() const {
	if (reference) {
		return std::any_cast<Value*>((*value)[index])->getIndex();
	}
	else {
		return index;
	}
}

std::any Value::getCurrent() const {
	if (reference) {
		auto val = std::any_cast<Value*>((*value)[index]);
		return std::any_cast<Value*>((*value)[index])->getCurrent();
	}
	return (*value)[index];
}
Value* Value::getReferenceObject() {
	if (reference) {
		return std::any_cast<Value*>((*value)[index]);
	}
	return this;
}

std::shared_ptr<Value> Value::copy() const {
	auto ret = std::make_shared<Value>(*this);
	ret->value = std::make_shared<std::vector<std::any>>(*ret->value);
	return ret;
}

void Value::setDefaultValue() {
	if (type == L"int") {
		set(static_cast<int64_t>(0));
	}
	else if (type == L"float") {
		set(static_cast<double>(0));
	}
	else if (type == L"bool") {
		set(static_cast<bool>(0));
	}
	else if (type == L"string") {
		set(static_cast<std::wstring>(L""));
	}
}

std::any Value::getDefaultValue() {
	if (type == L"int") {
		return static_cast<int64_t>(0);
	}
	else if (type == L"float") {
		return static_cast<double>(0);
	}
	else if (type == L"bool") {
		return static_cast<bool>(0);
	}
	else if (type == L"string") {
		return static_cast<std::wstring>(L"");
	}
}
