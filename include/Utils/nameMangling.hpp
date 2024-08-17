#pragma once
#include <vector>
#include <string>
#include <sstream>

#include "Value.hpp"

std::wstring mangleName(const std::wstring& symbol, const std::vector<std::shared_ptr<Value>>& params);