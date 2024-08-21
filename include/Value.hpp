#pragma once
#include <any>
#include <string>
#include <memory>
#include <chrono>

#include "Types.hpp"

class Value {
public:
	Value();
	Value(Value* ref);
	Value(const std::wstring& _type, const std::any& _value);

	std::shared_ptr<std::vector<std::any>> value;
	std::wstring type;

	bool overridable = true;
	bool editable = true;
	bool reassignable = true;
	bool reference = false;

	LifetimeInfo lifetime;

	int priority = 0;
	int index = -1;

	int createLineIndex = 0;
	std::chrono::high_resolution_clock::time_point createTimePoint;

	template<typename T>
	T get() const;
	template<typename T>
	void set(const T& t);

	bool setDeclType(VariableDeclarationType _type);

	bool isVoid() const;
	bool isValid(ASTNode* node) const;
	bool isValidTime(ASTNode* node) const;
	bool isValidLine(ASTNode* node) const;

	// timeline operation
	void past();
	void future();
	void begin();
	void end();
	void timelineInsert();
	void timelinePrune();
	int64_t getIndex() const;
	
	std::any getCurrent() const;
	Value* getReferenceObject();

	std::shared_ptr<Value> copy() const;
	void setDefaultValue();
	std::any getDefaultValue();
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

template<typename T>
T Value::get() const {
	if (isVoid()) {
		throw std::runtime_error("Variable is void, timeline index " + std::to_string(index) + " isn't available");
	}
	if (reference) {
		return std::any_cast<Value*>((*value)[index])->get<T>();
	}
	return std::any_cast<T>((*value)[index]);
}

template<typename T>
void Value::set(const T& t) {
	if (reference) {
		if (isVoid()) {
			throw std::runtime_error("Variable is void, timeline index " + std::to_string(index) + " isn't available");
		}
		std::any_cast<Value*>((*value)[index])->set<T>(t);
	}
	else {
		++index;
		if (value->empty()) {
			value->push_back(t);
		}
		else {
			value->insert(value->begin() + index, t);
		}
	}
}