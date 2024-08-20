#include "Types/String.hpp"

std::shared_ptr<Value> String::BinaryOperation(OperatorType operatorType, std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	switch (operatorType) {
	case OperatorType::Addition:
		return Addition(lOperand, rOperand);
	case OperatorType::Subtraction:
		return Subtraction(lOperand, rOperand);
	case OperatorType::Multiplication:
		return Multiplication(lOperand, rOperand);
	case OperatorType::Division:
		return Division(lOperand, rOperand);
	case OperatorType::Modulus:
		return Modulus(lOperand, rOperand);
	case OperatorType::Exponentiation:
		return Exponentiation(lOperand, rOperand);
	case OperatorType::EqualTo:
		return EqualTo(lOperand, rOperand);
	case OperatorType::NotEqualTo:
		return NotEqualTo(lOperand, rOperand);
	case OperatorType::Greater:
		return Greater(lOperand, rOperand);
	case OperatorType::Less:
		return Less(lOperand, rOperand);
	case OperatorType::GreaterEqual:
		return GreaterEqual(lOperand, rOperand);
	case OperatorType::LessEqual:
		return LessEqual(lOperand, rOperand);
	case OperatorType::LogicalAnd:
		return LogicalAnd(lOperand, rOperand);
	case OperatorType::LogicalOr:
		return LogicalOr(lOperand, rOperand);
	case OperatorType::BitwiseAnd:
		return BitwiseAnd(lOperand, rOperand);
	case OperatorType::BitwiseOr:
		return BitwiseOr(lOperand, rOperand);
	case OperatorType::BitwiseXor:
		return BitwiseXor(lOperand, rOperand);
	case OperatorType::LeftShift:
		return LeftShift(lOperand, rOperand);
	case OperatorType::RightShift:
		return RightShift(lOperand, rOperand);
	case OperatorType::LeftShiftAssignment:
		return LeftShiftAssignment(lOperand, rOperand);
	case OperatorType::RightShiftAssignment:
		return RightShiftAssignment(lOperand, rOperand);
	case OperatorType::Assignment:
		return Assignment(lOperand, rOperand);
	case OperatorType::AdditionAssignment:
		return AdditionAssignment(lOperand, rOperand);
	case OperatorType::SubtractionAssignment:
		return SubtractionAssignment(lOperand, rOperand);
	case OperatorType::MultiplicationAssignment:
		return MultiplicationAssignment(lOperand, rOperand);
	case OperatorType::DivisionAssignment:
		return DivisionAssignment(lOperand, rOperand);
	case OperatorType::ModulusAssignment:
		return ModulusAssignment(lOperand, rOperand);
	case OperatorType::ExponentiationAssignment:
		return ExponentiationAssignment(lOperand, rOperand);
	case OperatorType::BitwiseAndAssignment:
		return BitwiseAndAssignment(lOperand, rOperand);
	case OperatorType::BitwiseOrAssignment:
		return BitwiseOrAssignment(lOperand, rOperand);
	case OperatorType::BitwiseXorAssignment:
		return BitwiseXorAssignment(lOperand, rOperand);
	case OperatorType::LogicalAndAssignment:
		return LogicalAndAssignment(lOperand, rOperand);
	case OperatorType::LogicalOrAssignment:
		return LogicalOrAssignment(lOperand, rOperand);
	}
}

std::shared_ptr<Value> String::UnaryOperation(OperatorType operatorType, std::shared_ptr<Value> operand) {
	switch (operatorType) {
	case OperatorType::UnaryNegation:
		return UnaryNegation(operand);
	case OperatorType::UnaryPlus:
		return UnaryPlus(operand);
	case OperatorType::UnaryAbs:
		return UnaryAbs(operand);
	case OperatorType::LogicalNot:
		return LogicalNot(operand);
	case OperatorType::BitwiseNot:
		return BitwiseNot(operand);
	case OperatorType::FrontIncrement:
		return FrontIncrement(operand);
	case OperatorType::EndIncrement:
		return EndIncrement(operand);
	case OperatorType::FrontDecrement:
		return FrontDecrement(operand);
	case OperatorType::EndDecrement:
		return EndDecrement(operand);
	//case OperatorType::Past:
	//	return Past(operand);
	//case OperatorType::Current:
	//	return Current(operand);
	}
}

std::shared_ptr<Value> String::Addition(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		auto rvalue = cast<std::wstring>(rOperand->get<int64_t>());
		return makeValue<std::wstring>(lOperand->get<std::wstring>() + rvalue);
	}
	else if (rOperand->type == L"float") {
		auto rvalue = cast<std::wstring>(rOperand->get<double>());
		return makeValue<std::wstring>(lOperand->get<std::wstring>() + rvalue);
	}
	else if (rOperand->type == L"bool") {
		auto rvalue = cast<std::wstring>(rOperand->get<bool>());
		return makeValue<std::wstring>(lOperand->get<std::wstring>() + rvalue);
	}
	else if (rOperand->type == L"string") {
		auto rvalue = rOperand->get<std::wstring>();
		return makeValue<std::wstring>(lOperand->get<std::wstring>() + rvalue);
	}

	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> String::Subtraction(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		throw std::runtime_error("Cannot apply subtraction operation between type string and type int");
	}
	else if (rOperand->type == L"float") {
		throw std::runtime_error("Cannot apply subtraction operation between type string and type float");
	}
	else if (rOperand->type == L"bool") {
		throw std::runtime_error("Cannot apply subtraction operation between type string and type bool");
	}
	else if (rOperand->type == L"string") {
		throw std::runtime_error("Cannot apply subtraction operation between type string and type string");
	}

	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> String::Multiplication(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		throw std::runtime_error("Cannot apply multiplication operation between type string and type int");
	}
	else if (rOperand->type == L"float") {
		throw std::runtime_error("Cannot apply multiplication operation between type string and type float");
	}
	else if (rOperand->type == L"bool") {
		throw std::runtime_error("Cannot apply multiplication operation between type string and type bool");
	}
	else if (rOperand->type == L"string") {
		throw std::runtime_error("Cannot apply multiplication operation between type string and type string");
	}

	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> String::Division(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		throw std::runtime_error("Cannot apply division operation between type string and type int");
	}
	else if (rOperand->type == L"float") {
		throw std::runtime_error("Cannot apply division operation between type string and type float");
	}
	else if (rOperand->type == L"bool") {
		throw std::runtime_error("Cannot apply division operation between type string and type bool");
	}
	else if (rOperand->type == L"string") {
		throw std::runtime_error("Cannot apply division operation between type string and type string");
	}

	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> String::Modulus(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		throw std::runtime_error("Cannot apply modulo operation between type string and type int");
	}
	else if (rOperand->type == L"float") {
		throw std::runtime_error("Cannot apply modulo operation between type string and type float");
	}
	else if (rOperand->type == L"bool") {
		throw std::runtime_error("Cannot apply modulo operation between type string and type bool");
	}
	else if (rOperand->type == L"string") {
		throw std::runtime_error("Cannot apply modulo operation between type string and type string");
	}

	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> String::Exponentiation(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		throw std::runtime_error("Cannot apply exponentiation operation between type string and type int");
	}
	else if (rOperand->type == L"float") {
		throw std::runtime_error("Cannot apply exponentiation operation between type string and type float");
	}
	else if (rOperand->type == L"bool") {
		throw std::runtime_error("Cannot apply exponentiation operation between type string and type bool");
	}
	else if (rOperand->type == L"string") {
		throw std::runtime_error("Cannot apply exponentiation operation between type string and type string");
	}

	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> String::EqualTo(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		throw std::runtime_error("Cannot apply equal to operation between type string and type int");
	}
	else if (rOperand->type == L"float") {
		throw std::runtime_error("Cannot apply equal to operation between type string and type float");
	}
	else if (rOperand->type == L"bool") {
		throw std::runtime_error("Cannot apply equal to operation between type string and type bool");
	}
	else if (rOperand->type == L"string") {
		auto rvalue = rOperand->get<std::wstring>();
		return makeValue<bool>(lOperand->get<std::wstring>() == rvalue);
	}

	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> String::NotEqualTo(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		throw std::runtime_error("Cannot apply not equal to operation between type string and type int");
	}
	else if (rOperand->type == L"float") {
		throw std::runtime_error("Cannot apply not equal to operation between type string and type float");
	}
	else if (rOperand->type == L"bool") {
		throw std::runtime_error("Cannot apply not equal to operation between type string and type bool");
	}
	else if (rOperand->type == L"string") {
		auto rvalue = rOperand->get<std::wstring>();
		return makeValue<bool>(lOperand->get<std::wstring>() != rvalue);
	}

	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> String::Greater(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		throw std::runtime_error("Cannot apply greater operation between type string and type int");
	}
	else if (rOperand->type == L"float") {
		throw std::runtime_error("Cannot apply greater operation between type string and type float");
	}
	else if (rOperand->type == L"bool") {
		throw std::runtime_error("Cannot apply greater operation between type string and type bool");
	}
	else if (rOperand->type == L"string") {
		auto rvalue = rOperand->get<std::wstring>();
		return makeValue<bool>(lOperand->get<std::wstring>() > rvalue);
	}

	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> String::Less(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		throw std::runtime_error("Cannot apply less operation between type string and type int");
	}
	else if (rOperand->type == L"float") {
		throw std::runtime_error("Cannot apply less operation between type string and type float");
	}
	else if (rOperand->type == L"bool") {
		throw std::runtime_error("Cannot apply less operation between type string and type bool");
	}
	else if (rOperand->type == L"string") {
		auto rvalue = rOperand->get<std::wstring>();
		return makeValue<bool>(lOperand->get<std::wstring>() < rvalue);
	}

	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> String::GreaterEqual(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		throw std::runtime_error("Cannot apply greater equal operation between type string and type int");
	}
	else if (rOperand->type == L"float") {
		throw std::runtime_error("Cannot apply greater equal operation between type string and type float");
	}
	else if (rOperand->type == L"bool") {
		throw std::runtime_error("Cannot apply greater equal operation between type string and type bool");
	}
	else if (rOperand->type == L"string") {
		auto rvalue = rOperand->get<std::wstring>();
		return makeValue<bool>(lOperand->get<std::wstring>() >= rvalue);
	}

	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> String::LessEqual(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		throw std::runtime_error("Cannot apply less equal operation between type string and type int");
	}
	else if (rOperand->type == L"float") {
		throw std::runtime_error("Cannot apply less equal operation between type string and type float");
	}
	else if (rOperand->type == L"bool") {
		throw std::runtime_error("Cannot apply less equal operation between type string and type bool");
	}
	else if (rOperand->type == L"string") {
		auto rvalue = rOperand->get<std::wstring>();
		return makeValue<bool>(lOperand->get<std::wstring>() <= rvalue);
	}

	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> String::LogicalAnd(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		auto rvalue = rOperand->get<int64_t>();
		return makeValue<bool>(!lOperand->get<std::wstring>().empty() && rvalue);
	}
	else if (rOperand->type == L"float") {
		auto rvalue = rOperand->get<double>();
		return makeValue<bool>(!lOperand->get<std::wstring>().empty() && rvalue);
	}
	else if (rOperand->type == L"bool") {
		auto rvalue = rOperand->get<bool>();
		return makeValue<bool>(!lOperand->get<std::wstring>().empty() && rvalue);
	}
	else if (rOperand->type == L"string") {
		auto rvalue = rOperand->get<std::wstring>();
		return makeValue<bool>(!lOperand->get<std::wstring>().empty() && !rvalue.empty());
	}

	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> String::LogicalOr(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		auto rvalue = rOperand->get<int64_t>();
		return makeValue<bool>(!lOperand->get<std::wstring>().empty() || rvalue);
	}
	else if (rOperand->type == L"float") {
		auto rvalue = rOperand->get<double>();
		return makeValue<bool>(!lOperand->get<std::wstring>().empty() || rvalue);
	}
	else if (rOperand->type == L"bool") {
		auto rvalue = rOperand->get<bool>();
		return makeValue<bool>(!lOperand->get<std::wstring>().empty() || rvalue);
	}
	else if (rOperand->type == L"string") {
		auto rvalue = rOperand->get<std::wstring>();
		return makeValue<bool>(!lOperand->get<std::wstring>().empty() || !rvalue.empty());
	}

	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> String::BitwiseAnd(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		throw std::runtime_error("Cannot apply bitwise and operation between type string and type int");
	}
	else if (rOperand->type == L"float") {
		throw std::runtime_error("Cannot apply bitwise and operation between type string and type float");
	}
	else if (rOperand->type == L"bool") {
		throw std::runtime_error("Cannot apply bitwise and operation between type string and type bool");
	}
	else if (rOperand->type == L"string") {
		throw std::runtime_error("Cannot apply bitwise and operation between type string and type string");
	}

	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> String::BitwiseOr(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		throw std::runtime_error("Cannot apply bitwise or operation between type string and type int");
	}
	else if (rOperand->type == L"float") {
		throw std::runtime_error("Cannot apply bitwise or operation between type string and type float");
	}
	else if (rOperand->type == L"bool") {
		throw std::runtime_error("Cannot apply bitwise or operation between type string and type bool");
	}
	else if (rOperand->type == L"string") {
		throw std::runtime_error("Cannot apply bitwise or operation between type string and type string");
	}

	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> String::BitwiseXor(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		throw std::runtime_error("Cannot apply bitwise xor operation between type string and type int");
	}
	else if (rOperand->type == L"float") {
		throw std::runtime_error("Cannot apply bitwise xor operation between type string and type float");
	}
	else if (rOperand->type == L"bool") {
		throw std::runtime_error("Cannot apply bitwise xor operation between type string and type bool");
	}
	else if (rOperand->type == L"string") {
		throw std::runtime_error("Cannot apply bitwise xor operation between type string and type string");
	}

	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> String::LeftShift(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		throw std::runtime_error("Cannot apply leftshift operation between type string and type int");
	}
	else if (rOperand->type == L"float") {
		throw std::runtime_error("Cannot apply leftshift operation between type string and type float");
	}
	else if (rOperand->type == L"bool") {
		throw std::runtime_error("Cannot apply leftshift operation between type string and type bool");
	}
	else if (rOperand->type == L"string") {
		throw std::runtime_error("Cannot apply leftshift operation between type string and type string");
	}

	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> String::RightShift(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		throw std::runtime_error("Cannot apply rightshift operation between type string and type int");
	}
	else if (rOperand->type == L"float") {
		throw std::runtime_error("Cannot apply rightshift operation between type string and type float");
	}
	else if (rOperand->type == L"bool") {
		throw std::runtime_error("Cannot apply rightshift operation between type string and type bool");
	}
	else if (rOperand->type == L"string") {
		throw std::runtime_error("Cannot apply rightshift operation between type string and type string");
	}

	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> String::LeftShiftAssignment(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		throw std::runtime_error("Cannot apply leftshift operation between type string and type int");
	}
	else if (rOperand->type == L"float") {
		throw std::runtime_error("Cannot apply leftshift operation between type string and type float");
	}
	else if (rOperand->type == L"bool") {
		throw std::runtime_error("Cannot apply leftshift operation between type string and type bool");
	}
	else if (rOperand->type == L"string") {
		throw std::runtime_error("Cannot apply leftshift operation between type string and type string");
	}

	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> String::RightShiftAssignment(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		throw std::runtime_error("Cannot apply rightshift operation between type string and type int");
	}
	else if (rOperand->type == L"float") {
		throw std::runtime_error("Cannot apply rightshift operation between type string and type float");
	}
	else if (rOperand->type == L"bool") {
		throw std::runtime_error("Cannot apply rightshift operation between type string and type bool");
	}
	else if (rOperand->type == L"string") {
		throw std::runtime_error("Cannot apply rightshift operation between type string and type string");
	}

	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> String::Assignment(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		auto rvalue = cast<std::wstring>(rOperand->get<int64_t>());
		return changeValue<std::wstring>(lOperand, rvalue);
	}
	else if (rOperand->type == L"float") {
		auto rvalue = cast<std::wstring>(rOperand->get<double>());
		return changeValue<std::wstring>(lOperand, rvalue);
	}
	else if (rOperand->type == L"bool") {
		auto rvalue = cast<std::wstring>(rOperand->get<bool>());
		return changeValue<std::wstring>(lOperand, rvalue);
	}
	else if (rOperand->type == L"string") {
		auto rvalue = rOperand->get<std::wstring>();
		return changeValue<std::wstring>(lOperand, rvalue);
	}

	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> String::AdditionAssignment(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		auto rvalue = cast<std::wstring>(rOperand->get<int64_t>());
		return changeValue<std::wstring>(lOperand, lOperand->get<std::wstring>() + rvalue);
	}
	else if (rOperand->type == L"float") {
		auto rvalue = cast<std::wstring>(rOperand->get<double>());
		return changeValue<std::wstring>(lOperand, lOperand->get<std::wstring>() + rvalue);
	}
	else if (rOperand->type == L"bool") {
		auto rvalue = cast<std::wstring>(rOperand->get<bool>());
		return changeValue<std::wstring>(lOperand, lOperand->get<std::wstring>() + rvalue);
	}
	else if (rOperand->type == L"string") {
		auto rvalue = rOperand->get<std::wstring>();
		return changeValue<std::wstring>(lOperand, lOperand->get<std::wstring>() + rvalue);
	}

	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> String::SubtractionAssignment(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		throw std::runtime_error("Cannot apply subtraction operation between type string and type int");
	}
	else if (rOperand->type == L"float") {
		throw std::runtime_error("Cannot apply subtraction operation between type string and type float");
	}
	else if (rOperand->type == L"bool") {
		throw std::runtime_error("Cannot apply subtraction operation between type string and type bool");
	}
	else if (rOperand->type == L"string") {
		throw std::runtime_error("Cannot apply subtraction operation between type string and type string");
	}

	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> String::MultiplicationAssignment(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		throw std::runtime_error("Cannot apply multiplication operation between type string and type int");
	}
	else if (rOperand->type == L"float") {
		throw std::runtime_error("Cannot apply multiplication operation between type string and type float");
	}
	else if (rOperand->type == L"bool") {
		throw std::runtime_error("Cannot apply multiplication operation between type string and type bool");
	}
	else if (rOperand->type == L"string") {
		throw std::runtime_error("Cannot apply multiplication operation between type string and type string");
	}

	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> String::DivisionAssignment(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		throw std::runtime_error("Cannot apply division operation between type string and type int");
	}
	else if (rOperand->type == L"float") {
		throw std::runtime_error("Cannot apply division operation between type string and type float");
	}
	else if (rOperand->type == L"bool") {
		throw std::runtime_error("Cannot apply division operation between type string and type bool");
	}
	else if (rOperand->type == L"string") {
		throw std::runtime_error("Cannot apply division operation between type string and type string");
	}

	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> String::ModulusAssignment(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		throw std::runtime_error("Cannot apply modulo operation between type string and type int");
	}
	else if (rOperand->type == L"float") {
		throw std::runtime_error("Cannot apply modulo operation between type string and type float");
	}
	else if (rOperand->type == L"bool") {
		throw std::runtime_error("Cannot apply modulo operation between type string and type bool");
	}
	else if (rOperand->type == L"string") {
		throw std::runtime_error("Cannot apply modulo operation between type string and type string");
	}

	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> String::ExponentiationAssignment(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		throw std::runtime_error("Cannot apply exponentiation operation between type string and type int");
	}
	else if (rOperand->type == L"float") {
		throw std::runtime_error("Cannot apply exponentiation operation between type string and type float");
	}
	else if (rOperand->type == L"bool") {
		throw std::runtime_error("Cannot apply exponentiation operation between type string and type bool");
	}
	else if (rOperand->type == L"string") {
		throw std::runtime_error("Cannot apply exponentiation operation between type string and type string");
	}

	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> String::BitwiseAndAssignment(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		throw std::runtime_error("Cannot apply bitwise and operation between type string and type int");
	}
	else if (rOperand->type == L"float") {
		throw std::runtime_error("Cannot apply bitwise and operation between type string and type float");
	}
	else if (rOperand->type == L"bool") {
		throw std::runtime_error("Cannot apply bitwise and operation between type string and type bool");
	}
	else if (rOperand->type == L"string") {
		throw std::runtime_error("Cannot apply bitwise and operation between type string and type string");
	}

	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> String::BitwiseOrAssignment(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		throw std::runtime_error("Cannot apply bitwise or operation between type string and type int");
	}
	else if (rOperand->type == L"float") {
		throw std::runtime_error("Cannot apply bitwise or operation between type string and type float");
	}
	else if (rOperand->type == L"bool") {
		throw std::runtime_error("Cannot apply bitwise or operation between type string and type bool");
	}
	else if (rOperand->type == L"string") {
		throw std::runtime_error("Cannot apply bitwise or operation between type string and type string");
	}

	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> String::BitwiseXorAssignment(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		throw std::runtime_error("Cannot apply bitwise xor operation between type string and type int");
	}
	else if (rOperand->type == L"float") {
		throw std::runtime_error("Cannot apply bitwise xor operation between type string and type float");
	}
	else if (rOperand->type == L"bool") {
		throw std::runtime_error("Cannot apply bitwise xor operation between type string and type bool");
	}
	else if (rOperand->type == L"string") {
		throw std::runtime_error("Cannot apply bitwise xor operation between type string and type string");
	}

	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> String::LogicalAndAssignment(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		auto rvalue = rOperand->get<int64_t>();
		return changeValue<bool>(lOperand, !lOperand->get<std::wstring>().empty() && rvalue);
	}
	else if (rOperand->type == L"float") {
		auto rvalue = rOperand->get<double>();
		return changeValue<bool>(lOperand, !lOperand->get<std::wstring>().empty() && rvalue);
	}
	else if (rOperand->type == L"bool") {
		auto rvalue = rOperand->get<int64_t>();
		return changeValue<bool>(lOperand, !lOperand->get<std::wstring>().empty() && rvalue);
	}
	else if (rOperand->type == L"string") {
		auto rvalue = rOperand->get<std::wstring>();
		return changeValue<bool>(lOperand, !lOperand->get<std::wstring>().empty() && !rvalue.empty());
	}

	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> String::LogicalOrAssignment(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		auto rvalue = rOperand->get<int64_t>();
		return changeValue<bool>(lOperand, !lOperand->get<std::wstring>().empty() || rvalue);
	}
	else if (rOperand->type == L"float") {
		auto rvalue = rOperand->get<double>();
		return changeValue<bool>(lOperand, !lOperand->get<std::wstring>().empty() || rvalue);
	}
	else if (rOperand->type == L"bool") {
		auto rvalue = rOperand->get<int64_t>();
		return changeValue<bool>(lOperand, !lOperand->get<std::wstring>().empty() || rvalue);
	}
	else if (rOperand->type == L"string") {
		auto rvalue = rOperand->get<std::wstring>();
		return changeValue<bool>(lOperand, !lOperand->get<std::wstring>().empty() || !rvalue.empty());
	}

	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> String::UnaryNegation(std::shared_ptr<Value> lOperand) {
	throw std::runtime_error("Cannot apply negation operation on type float");
}

std::shared_ptr<Value> String::UnaryPlus(std::shared_ptr<Value> lOperand) {
	throw std::runtime_error("Cannot apply plus operation on type float");
}

std::shared_ptr<Value> String::UnaryAbs(std::shared_ptr<Value> lOperand) {
	throw std::runtime_error("Cannot apply absolute operation on type float");
}

std::shared_ptr<Value> String::LogicalNot(std::shared_ptr<Value> lOperand) {
	return makeValue<bool>(lOperand->get<std::wstring>().empty());
}

std::shared_ptr<Value> String::BitwiseNot(std::shared_ptr<Value> lOperand) {
	throw std::runtime_error("Cannot apply bitwise not operation on type float");
}

std::shared_ptr<Value> String::FrontIncrement(std::shared_ptr<Value> lOperand) {
	throw std::runtime_error("Cannot apply front increment operation on type float");
}

std::shared_ptr<Value> String::FrontDecrement(std::shared_ptr<Value> lOperand) {
	throw std::runtime_error("Cannot apply front decrement operation on type float");
}

std::shared_ptr<Value> String::EndIncrement(std::shared_ptr<Value> lOperand) {
	throw std::runtime_error("Cannot apply end increment operation on type float");
}

std::shared_ptr<Value> String::EndDecrement(std::shared_ptr<Value> lOperand) {
	throw std::runtime_error("Cannot apply end decrement operation on type float");
}
