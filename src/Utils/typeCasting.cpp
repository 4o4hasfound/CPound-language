#include "Utils/typeCasting.hpp"

template<>
int64_t cast(const std::shared_ptr<Value>& value) {
	if (value->type == L"int") {
		return cast<int64_t, int64_t>(value->get<int64_t>());
	}
	else if (value->type == L"float") {
		return cast<int64_t, double>(value->get<double>());
	}
	else if (value->type == L"bool") {
		return cast<int64_t, bool>(value->get<bool>());
	}
	else if (value->type == L"string") {
		return cast<int64_t, std::wstring>(value->get<std::wstring>());
	}
}
template<>
double cast(const std::shared_ptr<Value>& value) {
	if (value->type == L"int") {
		return cast<double, int64_t>(value->get<int64_t>());
	}
	else if (value->type == L"float") {
		return cast<double, double>(value->get<double>());
	}
	else if (value->type == L"bool") {
		return cast<double, bool>(value->get<bool>());
	}
	else if (value->type == L"string") {
		return cast<double, std::wstring>(value->get<std::wstring>());
	}
}
template<>
bool cast(const std::shared_ptr<Value>& value) {
	if (value->type == L"int") {
		return cast<bool, int64_t>(value->get<int64_t>());
	}
	else if (value->type == L"float") {
		return cast<bool, double>(value->get<double>());
	}
	else if (value->type == L"bool") {
		return cast<bool, bool>(value->get<bool>());
	}
	else if (value->type == L"string") {
		return cast<bool, std::wstring>(value->get<std::wstring>());
	}
}
template<>
std::wstring cast(const std::shared_ptr<Value>& value) {
	if (value->type == L"int") {
		return cast<std::wstring, int64_t>(value->get<int64_t>());
	}
	else if (value->type == L"float") {
		return cast<std::wstring, double>(value->get<double>());
	}
	else if (value->type == L"bool") {
		return cast<std::wstring, bool>(value->get<bool>());
	}
	else if (value->type == L"string") {
		return cast<std::wstring, std::wstring>(value->get<std::wstring>());
	}
}

// ------------------- Interger --------------------

template<>
int64_t cast<int64_t, int64_t>(const int64_t& value) {
	return value;
}
template<>
int64_t cast<int64_t, double>(const double& value) {
	return static_cast<double>(value);
}
template<>
int64_t cast<int64_t, bool>(const bool& value) {
	return static_cast<int64_t>(value);
}
template<>
int64_t cast<int64_t, std::wstring>(const std::wstring& value) {
	return static_cast<int64_t>(std::stoll(value));
}

// ------------------- Float --------------------

template<>
double cast<double, int64_t>(const int64_t& value) {
	return static_cast<double>(value);
}
template<>
double cast<double, double>(const double& value) {
	return value;
}
template<>
double cast<double, bool>(const bool& value) {
	return static_cast<double>(value);
}
template<>
double cast<double, std::wstring>(const std::wstring& value) {
	return static_cast<double>(std::stod(value));
}


// ------------------- Bool --------------------

template<>
bool cast<bool, int64_t>(const int64_t& value) {
	return static_cast<bool>(value);
}
template<>
bool cast<bool, double>(const double& value) {
	return static_cast<bool>(value);
}
template<>
bool cast<bool, bool>(const bool& value) {
	return value;
}
template<>
bool cast<bool, std::wstring>(const std::wstring& value) {
	return !value.empty();
}

template<>
bool cast<bool>(const std::vector<std::shared_ptr<Value>>& value) {
	return !value.empty();
}
// ------------------- String --------------------

template<>
std::wstring cast<std::wstring, int64_t>(const int64_t& value) {
	return std::to_wstring(value);
}
template<>
std::wstring cast<std::wstring, double>(const double& value) {
	return std::to_wstring(value);
}
template<>
std::wstring cast<std::wstring, bool>(const bool& value) {
	return std::to_wstring(value);
}
template<>
std::wstring cast<std::wstring, std::wstring>(const std::wstring& value) {
	return value;
}

template<>
std::wstring cast<std::wstring>(const std::vector<std::shared_ptr<Value>>& value) {
	std::wstringstream ret;
	for (int i = 0; i < value.size(); ++i) {
		ret << cast<std::wstring>(value[i]);
		if (i != value.size() - 1) {
			ret << ", ";
		}
	}
	return ret.str();
}

std::shared_ptr<Value> convertValue(const std::shared_ptr<Value>& value, const std::wstring& type) {
	std::shared_ptr<Value> ret = value->copy();
	ret->type = type;
	if (value->type == L"int") {
		if (type == L"int") {

		}
		else if (type == L"float") {
			ret->set<double>(cast<double, int64_t>(value->get<int64_t>()));
		}
		else if (type == L"bool") {
			ret->set<bool>(cast<bool, int64_t>(value->get<int64_t>()));
		}
		else if (type == L"string") {
			ret->set<std::wstring>(cast<std::wstring, int64_t>(value->get<int64_t>()));
		}
	}
	else if (value->type == L"float") {
		if (type == L"int") {
			ret->set<int64_t>(cast<int64_t, double>(value->get<double>()));
		}
		else if (type == L"float") {

		}
		else if (type == L"bool") {
			ret->set<bool>(cast<bool, double>(value->get<double>()));
		}
		else if (type == L"string") {
			ret->set<std::wstring>(cast<std::wstring, double>(value->get<double>()));
		}
	}
	else if (value->type == L"bool") {
		if (type == L"int") {
			ret->set<int64_t>(cast<int64_t, bool>(value->get<bool>()));
		}
		else if (type == L"float") {
			ret->set<double>(cast<double, bool>(value->get<bool>()));
		}
		else if (type == L"bool") {

		}
		else if (type == L"string") {
			ret->set<std::wstring>(cast<std::wstring, bool>(value->get<bool>()));
		}
	}
	else if (value->type == L"string") {
		if (type == L"int") {
			ret->set<int64_t>(cast<int64_t, std::wstring>(value->get<std::wstring>()));
		}
		else if (type == L"float") {
			ret->set<double>(cast<double, std::wstring>(value->get<std::wstring>()));
		}
		else if (type == L"bool") {
			ret->set<bool>(cast<bool, std::wstring>(value->get<std::wstring>()));
		}
		else if (type == L"string") {

		}
	}
	return ret;
}

bool canConvert(const std::shared_ptr<Value>& value, const std::wstring& type) {
	try {
		if (value->type == L"string") {
			if (type == L"int") {
				cast<std::wstring, std::wstring>(value->get<std::wstring>());
			}
			else if (type == L"float") {
				cast<std::wstring, std::wstring>(value->get<std::wstring>());
			}
			else if (type == L"bool") {
				cast<std::wstring, std::wstring>(value->get<std::wstring>());
			}
		}
	}
	catch (const std::exception& e) {
		return false;
	}
	return true;
}
