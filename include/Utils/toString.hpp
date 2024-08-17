#pragma once
#include <string>

#include "Types.hpp"
#include "Utils/lowerCaseString.hpp"
#include "Container/BiUnorderedMap.hpp"

extern BiUnorderedMap<std::wstring, OperatorType, lowerCaseCompare> operatorTypeStringMap;
extern BiUnorderedMap<std::wstring, BooleanType, lowerCaseCompare> booleanTypeStringMap;
extern BiUnorderedMap<std::wstring, KeywordType, lowerCaseCompare> KeywordTypeStringMap;
extern BiUnorderedMap<std::wstring, DelimiterType, lowerCaseCompare> delimiterTypeStringMap;
extern BiUnorderedMap<std::wstring, LifetimeType, lowerCaseCompare> lifetimeTypeStringMap;
extern BiUnorderedMap<std::wstring, NumericLiteralType, lowerCaseCompare> numericLiteralTypeStringMap;
extern BiUnorderedMap<std::wstring, TerminatorType, lowerCaseCompare> terminatorTypeStringMap;
