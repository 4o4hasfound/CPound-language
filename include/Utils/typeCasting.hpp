#pragma once
#include <memory>
#include <string>
#include <cstdint>

#include "Error.hpp"
#include "Value.hpp"

template<typename MainT, typename T>
MainT cast(const T& value);

template<typename T>
T cast(const std::shared_ptr<Value>& value);

template<>
int64_t cast<int64_t>(const std::shared_ptr<Value>& value);
template<>
double cast<double>(const std::shared_ptr<Value>& value);
template<>
bool cast<bool>(const std::shared_ptr<Value>& value);
template<>
std::wstring cast<std::wstring>(const std::shared_ptr<Value>& value);

// ------------------- Interger --------------------

template<>
int64_t cast<int64_t, int64_t>(const int64_t& value);
template<>
int64_t cast<int64_t, double>(const double& value);
template<>
int64_t cast<int64_t, bool>(const bool& value);
template<>
int64_t cast<int64_t, std::wstring>(const std::wstring& value);

// ------------------- Float --------------------

template<>
double cast<double, int64_t>(const int64_t& value);
template<>
double cast<double, double>(const double& value);
template<>
double cast<double, bool>(const bool& value);
template<>
double cast<double, std::wstring>(const std::wstring& value);


// ------------------- Bool --------------------

template<>
bool cast<bool, int64_t>(const int64_t& value);
template<>
bool cast<bool, double>(const double& value);
template<>
bool cast<bool, bool>(const bool& value);
template<>
bool cast<bool, std::wstring>(const std::wstring& value);


// ------------------- String --------------------

template<>
std::wstring cast<std::wstring, int64_t>(const int64_t& value);
template<>
std::wstring cast<std::wstring, double>(const double& value);
template<>
std::wstring cast<std::wstring, bool>(const bool& value);
template<>
std::wstring cast<std::wstring, std::wstring>(const std::wstring& value);


std::shared_ptr<Value> convertValue(const std::shared_ptr<Value>& value, const std::wstring& type);

bool canConvert(const std::shared_ptr<Value>& value, const std::wstring& type);