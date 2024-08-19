#include "Value.hpp"

Value::Value(Value* ref)
	: reference(true)
	, type(ref->type)
	, editable(ref->editable)
	, reassignable(ref->reassignable)
	, overridable(ref->overridable)
	, lifetime(ref->lifetime)
	, priority(ref->priority)
	, index(0) {
	if (ref->reference) {
		value = std::make_shared<std::vector<std::any>>(1, ref->getCurrent());
	}
	else {
		value = std::make_shared<std::vector<std::any>>(1, ref);
	}
}

Value::Value(const std::wstring& _type, const std::any& _value)
	: type(_type)
	, value(std::make_shared<std::vector<std::any>>(1, _value))
	, index(0) {

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
	if ((*value).size() && index >= 0 && index < (*value).size() && (*value)[index].type() != typeid(std::nullptr_t)) {
		return false;
	}
	return true;
}
void Value::previous() {
	if (isVoid()) {
		throw std::runtime_error("Variable is void");
	}
	if (reference) {
		std::any_cast<Value*>((*value)[index])->previous();
	}
	else {
		--index;
	}
}
void Value::future() {
	if (isVoid()) {
		throw std::runtime_error("Variable is void");
	}
	if (reference) {
		std::any_cast<Value*>((*value)[index])->future();
	}
	else {
		++index;
	}
}
std::any Value::getCurrent() const {
	if (reference) {
		auto val = std::any_cast<Value*>((*value)[index]);
		return std::any_cast<Value*>((*value)[index])->value;
	}
	return (*value)[index];
}
Value* Value::getReferenceObject() const {
	if (reference) {
		return std::any_cast<Value*>((*value)[index]);
	}
	return nullptr;
}

std::shared_ptr<Value> Value::copy() const {
	for (auto& n : *value) {
		if (n.type() != typeid(int64_t)) {
			break;
		}
		int val = std::any_cast<int64_t>(n);
	}
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
