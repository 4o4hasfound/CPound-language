#pragma once
#include <any>
#include <string>
#include <memory>

#include "Types.hpp"

class Value {
public:
	Value() = default;
	Value(Value* ref);
	Value(const std::wstring& _type, const std::any& _value);

	bool setDeclType(VariableDeclarationType _type);

	std::any value;
	std::wstring type;

	bool overridable = true;
	bool editable = true;
	bool reassignable = true;
	bool reference = false;

	LifetimeInfo lifetime;

	int priority = 0;

	template<typename T>
	T get() const {
		if (reference) {
			return std::any_cast<Value*>(value)->get<T>();
		}
		return std::any_cast<T>(value);
	}
	template<typename T>
	void set(const T& t) {
		if (reference) {
			std::any_cast<Value*>(value)->set<T>(t);
		}
		else {
			value = t;
		}
	}

	std::wstring str() const;

	std::shared_ptr<Value> copy() const;
};

template<typename T>
std::shared_ptr<Value> makeValue(const T& value);
template<typename T>
std::shared_ptr<Value> changeValue(std::shared_ptr<Value> value, const T& v) {
	value->set<T>(v);
	return value;
}

template<>
inline std::shared_ptr<Value> makeValue<int64_t>(const int64_t& value) {
	return std::make_shared<Value>(L"int", value);
}
template<>
inline std::shared_ptr<Value> makeValue<double>(const double& value) {
	return std::make_shared<Value>(L"float", value);
}

template<>
inline std::shared_ptr<Value> makeValue<bool>(const bool& value) {
	return std::make_shared<Value>(L"bool", value);
}

template<>
inline std::shared_ptr<Value> makeValue<std::wstring>(const std::wstring& value) {
	return std::make_shared<Value>(L"string", value);
}