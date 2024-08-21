#include "Utils/toString.hpp"

BiUnorderedMap<std::wstring, OperatorType, lowerCaseCompare> operatorTypeStringMap{ {
	{L"[[positive]]"	,	OperatorType::UnaryPlus},
	{L"positive"		,	OperatorType::UnaryPlus},
	{L"[[negative]]"	,	OperatorType::UnaryNegation},
	{L"negative"		,	OperatorType::UnaryNegation},
	{L"[[absolute]]"	,	OperatorType::UnaryAbs},
	{L"absolute"		,	OperatorType::UnaryAbs},
	{L"===="			,	OperatorType::ReferenceEqualTo},
	{L"==="	,	OperatorType::ReferenceAssignment},
	{L";=="	,	OperatorType::ReferenceNotEqual},
	{L"**="	,	OperatorType::ExponentiationAssignment},
	{L"+++"	,	OperatorType::FrontIncrement},
	{L"++"	,	OperatorType::EndIncrement},
	{L"---"	,	OperatorType::FrontDecrement},
	{L"--"	,	OperatorType::EndDecrement},
	{L"<<="	,	OperatorType::LeftShiftAssignment},
	{L">>="	,	OperatorType::RightShiftAssignment},
	{L";="	,	OperatorType::NotEqualTo},
	{L"&&="	,	OperatorType::LogicalAndAssignment},
	{L"||="	,	OperatorType::LogicalOrAssignment},
	{L"**"	,	OperatorType::Exponentiation},
	{L"=="	,	OperatorType::EqualTo},
	{L">="	,	OperatorType::GreaterEqual},
	{L"<="	,	OperatorType::LessEqual},
	{L"&&"	,	OperatorType::LogicalAnd},
	{L"||"	,	OperatorType::LogicalOr},
	{L"<<"	,	OperatorType::LeftShift},
	{L">>"	,	OperatorType::RightShift},
	{L"+="	,	OperatorType::AdditionAssignment},
	{L"-="	,	OperatorType::SubtractionAssignment},
	{L"*="	,	OperatorType::MultiplicationAssignment},
	{L"/="	,	OperatorType::DivisionAssignment},
	{L"%="	,	OperatorType::ModulusAssignment},
	{L"&="	,	OperatorType::BitwiseAndAssignment},
	{L"|="	,	OperatorType::BitwiseOrAssignment},
	{L"^="	,	OperatorType::BitwiseXorAssignment},
	{L"~="	,	OperatorType::BitwiseNotAssignment},
	{L"="	,	OperatorType::Assignment},
	{L"+"	,	OperatorType::Addition},
	{L"-"	,	OperatorType::Subtraction},
	{L"*"	,	OperatorType::Multiplication},
	{L"/"	,	OperatorType::Division},
	{L"%"	,	OperatorType::Modulus},
	{L";"	,	OperatorType::LogicalNot},
	{L"&"	,	OperatorType::BitwiseAnd},
	{L"|"	,	OperatorType::BitwiseOr},
	{L"^"	,	OperatorType::BitwiseXor},
	{L"~"	,	OperatorType::BitwiseNot},
	{L">"	,	OperatorType::Greater},
	{L"<"	,	OperatorType::Less},
} };
BiUnorderedMap<std::wstring, BooleanType, lowerCaseCompare> booleanTypeStringMap{ {
	{L"true", BooleanType::True},
	{L"maybe", BooleanType::Maybe},
	{L"false", BooleanType::False}
} };
BiUnorderedMap<std::wstring, KeywordType, lowerCaseCompare> KeywordTypeStringMap{ {
	{L"var"					,	KeywordType::VarVarVar},
	{L"var var"				,	KeywordType::VarVarVar},
	{L"var const"			,	KeywordType::VarConstConst},
	{L"var var var"			,	KeywordType::VarVarVar},
	{L"var var const"		,	KeywordType::VarVarConst},
	{L"var const var"		,	KeywordType::VarConstVar},
	{L"var const const"		,	KeywordType::VarConstConst},
	{L"const"				,	KeywordType::ConstConstConst},
	{L"const var"			,	KeywordType::ConstVarVar},
	{L"const const"			,	KeywordType::ConstConstConst},
	{L"const var var"		,	KeywordType::ConstVarVar},
	{L"const var const"		,	KeywordType::ConstVarConst},
	{L"const const var"		,	KeywordType::ConstConstVar},
	{L"const const const"	,	KeywordType::ConstConstConst},
	{L"class"			,	KeywordType::Class},
	{L"public"			,	KeywordType::Public},
	{L"private"			,	KeywordType::Private},
	{L"evaluate"		,	KeywordType::Evaluate},
	{L"operator"		,	KeywordType::Operator},
	{L"typecast"		,	KeywordType::Typecast},
	{L"inherit"			,	KeywordType::Inherit},
	{L"reference"		,	KeywordType::Reference},
	{L"if"				,	KeywordType::If},
	{L"else"			,	KeywordType::Else},
	{L"yoink"			,	KeywordType::Return},
	{L"function"		,	KeywordType::Function},
	{L"reverse"			,	KeywordType::Reverse},
	{L"noop"			,	KeywordType::Noop},
	{L"check this out"	,	KeywordType::Print},
	{L"what is"			,	KeywordType::Input},
	{L"past"			,	KeywordType::Past},
	{L"future"			,	KeywordType::Future},
	{L"timeline length"	,	KeywordType::Length},
	{L"timeline index"	,	KeywordType::Index},
	{L"timeline prune"	,	KeywordType::Prune},
	{L"timeline insert"	,	KeywordType::Insert},
	{L"timeline begin"	,	KeywordType::Begin},
	{L"timeline end"	,	KeywordType::End}
} };
BiUnorderedMap<std::wstring, DelimiterType, lowerCaseCompare> delimiterTypeStringMap{ {
	{L"(", DelimiterType::LParen},
	{L")", DelimiterType::RParen},
	{L"[", DelimiterType::LBracket},
	{L"]", DelimiterType::RBracket},
	{L"{", DelimiterType::LCurlyBracket},
	{L"}", DelimiterType::RCurlyBracket},
	{L",", DelimiterType::Comma},
} };
BiUnorderedMap<std::wstring, LifetimeType, lowerCaseCompare> lifetimeTypeStringMap{ {
	{L"forward line"		,	LifetimeType::ForwardLine},
	{L"backward line"		,	LifetimeType::ForwardLine},
	{L"second"	,	LifetimeType::Time},
	{L"scope"	,	LifetimeType::Scope}
} };
BiUnorderedMap<std::wstring, NumericLiteralType, lowerCaseCompare> numericLiteralTypeStringMap{ {
	{L"int", NumericLiteralType::Integer},
	{L"float", NumericLiteralType::Float}
} };
BiUnorderedMap<std::wstring, TerminatorType, lowerCaseCompare> terminatorTypeStringMap{{
	{L"!", TerminatorType::ExclamationMark},
	{L"?", TerminatorType::QuestionMark}
} };
