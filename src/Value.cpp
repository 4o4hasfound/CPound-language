#include "Value.hpp"

Value::Value(Value* ref)
	: reference(true)
	, type(ref->type)
	, editable(ref->editable)
	, reassignable(ref->reassignable)
	, overridable(ref->overridable)
	, lifetime(ref->lifetime)
	, priority(ref->priority)
	, value(ref) {

}

Value::Value(const std::wstring& _type, const std::any& _value)
	: type(_type)
	, value(_value) {

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
		_editable = _reassignable = false;
		_overridable = true;
		break;
	case VariableDeclarationType::ConstConstVar:
		_editable = _reassignable = false;
		_overridable = true;
		break;
	case VariableDeclarationType::ConstConstConst:
		_editable = _reassignable = _overridable = false;
		break;
	}

	// For reference, declaration type can only be var -> cconst, not the other way around
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

std::wstring Value::str() const {
	if (type == L"int") {
		return std::to_wstring(get<int64_t>());
	}
	else if (type == L"float") {
		return std::to_wstring(get<double>());
	}
	else if (type == L"bool") {
		return std::to_wstring(get<bool>());
	}
	else if (type == L"string") {
		return get<std::wstring>();
	}
	return L"";
}

std::shared_ptr<Value> Value::copy() const {
	return std::make_shared<Value>(*this);
}
