#include "Types/Boolean.hpp"

std::shared_ptr<Value> Boolean::BinaryOperation(OperatorType operatorType, std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
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

std::shared_ptr<Value> Boolean::UnaryOperation(OperatorType operatorType, std::shared_ptr<Value> operand) {
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
	//case OperatorType::Previous:
	//	return Previous(operand);
	//case OperatorType::Current:
	//	return Current(operand);
	}
}

std::shared_ptr<Value> Boolean::Addition(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		return makeValue<bool>(lOperand->get<bool>() + rOperand->get<int64_t>());
	}
	else if (rOperand->type == L"float") {
		return makeValue<bool>(lOperand->get<bool>() + rOperand->get<double>());
	}
	else if (rOperand->type == L"bool") {
		return makeValue<bool>(lOperand->get<bool>() + rOperand->get<bool>());
	}
	else if (rOperand->type == L"string") {
		auto rvalue = cast<double, std::wstring>(rOperand->get<std::wstring>());
		return makeValue<bool>(lOperand->get<bool>() + rvalue);
	}

	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> Boolean::Subtraction(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		return makeValue<bool>(lOperand->get<bool>() - rOperand->get<int64_t>());
	}
	else if (rOperand->type == L"float") {
		return makeValue<bool>(lOperand->get<bool>() - rOperand->get<double>());
	}
	else if (rOperand->type == L"bool") {
		return makeValue<bool>(lOperand->get<bool>() - rOperand->get<bool>());
	}
	else if (rOperand->type == L"string") {
		auto rvalue = cast<double, std::wstring>(rOperand->get<std::wstring>());
		return makeValue<bool>(lOperand->get<bool>() - rvalue);
	}

	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> Boolean::Multiplication(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		return makeValue<bool>(lOperand->get<bool>() * rOperand->get<int64_t>());
	}
	else if (rOperand->type == L"float") {
		return makeValue<bool>(lOperand->get<bool>() * rOperand->get<double>());
	}
	else if (rOperand->type == L"bool") {
		return makeValue<bool>(lOperand->get<bool>() * rOperand->get<bool>());
	}
	else if (rOperand->type == L"string") {
		auto rvalue = cast<double, std::wstring>(rOperand->get<std::wstring>());
		return makeValue<bool>(lOperand->get<bool>() - rvalue);
	}

	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> Boolean::Division(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		auto rvalue = rOperand->get<int64_t>();
		if (rvalue == 0) {
			return makeValue<bool>(0);
		}
		return makeValue<bool>(lOperand->get<bool>() / rvalue);
	}
	else if (rOperand->type == L"float") {
		auto rvalue = rOperand->get<double>();
		if (rvalue == 0) {
			return makeValue<bool>(0);
		}
		return makeValue<bool>(lOperand->get<bool>() / rvalue);
	}
	else if (rOperand->type == L"bool") {
		auto rvalue = rOperand->get<bool>();
		if (rvalue == 0) {
			return makeValue<bool>(0);
		}
		return makeValue<bool>(lOperand->get<bool>() / rvalue);
	}
	else if (rOperand->type == L"string") {
		auto rvalue = cast<double, std::wstring>(rOperand->get<std::wstring>());
		if (std::ceil(rvalue) == rvalue) {
			if (rvalue == 0) {
				return makeValue<bool>(0);
			}
			return makeValue<bool>(lOperand->get<bool>() / rvalue);
		}
	}

	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> Boolean::Modulus(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		throw std::runtime_error("Cannot apply modulo operation between type bool and type int");
	}
	else if (rOperand->type == L"float") {
		throw std::runtime_error("Cannot apply modulo operation between type bool and type float");
	}
	else if (rOperand->type == L"bool") {
		throw std::runtime_error("Cannot apply modulo operation between type bool and type bool");
	}
	else if (rOperand->type == L"string") {
		throw std::runtime_error("Cannot apply modulo operation between type bool and type string");
	}

	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> Boolean::Exponentiation(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		return makeValue<bool>(std::pow(lOperand->get<bool>(), rOperand->get<int64_t>()));
	}
	else if (rOperand->type == L"float") {
		return makeValue<bool>(std::pow(lOperand->get<bool>(), rOperand->get<double>()));
	}
	else if (rOperand->type == L"bool") {
		return makeValue<bool>(std::pow(lOperand->get<bool>(), rOperand->get<bool>()));
	}
	else if (rOperand->type == L"string") {
		auto rvalue = cast<double, std::wstring>(rOperand->get<std::wstring>());
		return makeValue<bool>(std::pow(lOperand->get<bool>(), rvalue));
	}

	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> Boolean::EqualTo(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		return makeValue<bool>(lOperand->get<bool>() == rOperand->get<int64_t>());
	}
	else if (rOperand->type == L"float") {
		return makeValue<bool>(lOperand->get<bool>() == rOperand->get<double>());
	}
	else if (rOperand->type == L"bool") {
		return makeValue<bool>(lOperand->get<bool>() == rOperand->get<bool>());
	}
	else if (rOperand->type == L"string") {
		auto rvalue = cast<double, std::wstring>(rOperand->get<std::wstring>());
		return makeValue<bool>(lOperand->get<bool>() == rvalue);
	}

	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> Boolean::NotEqualTo(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		return makeValue<bool>(lOperand->get<bool>() != rOperand->get<int64_t>());
	}
	else if (rOperand->type == L"float") {
		return makeValue<bool>(lOperand->get<bool>() != rOperand->get<double>());
	}
	else if (rOperand->type == L"bool") {
		return makeValue<bool>(lOperand->get<bool>() != rOperand->get<bool>());
	}
	else if (rOperand->type == L"string") {
		auto rvalue = cast<double, std::wstring>(rOperand->get<std::wstring>());
		return makeValue<bool>(lOperand->get<bool>() != rvalue);
	}

	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> Boolean::Greater(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		return makeValue<bool>(lOperand->get<bool>() > rOperand->get<int64_t>());
	}
	else if (rOperand->type == L"float") {
		return makeValue<bool>(lOperand->get<bool>() > rOperand->get<double>());
	}
	else if (rOperand->type == L"bool") {
		return makeValue<bool>(lOperand->get<bool>() > rOperand->get<bool>());
	}
	else if (rOperand->type == L"string") {
		auto rvalue = cast<double, std::wstring>(rOperand->get<std::wstring>());
		return makeValue<bool>(lOperand->get<bool>() > rvalue);
	}

	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> Boolean::Less(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		return makeValue<bool>(lOperand->get<bool>() < rOperand->get<int64_t>());
	}
	else if (rOperand->type == L"float") {
		return makeValue<bool>(lOperand->get<bool>() < rOperand->get<double>());
	}
	else if (rOperand->type == L"bool") {
		return makeValue<bool>(lOperand->get<bool>() < rOperand->get<bool>());
	}
	else if (rOperand->type == L"string") {
		auto rvalue = cast<double, std::wstring>(rOperand->get<std::wstring>());
		return makeValue<bool>(lOperand->get<bool>() < rvalue);
	}

	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> Boolean::GreaterEqual(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		return makeValue<bool>(lOperand->get<bool>() >= rOperand->get<int64_t>());
	}
	else if (rOperand->type == L"float") {
		return makeValue<bool>(lOperand->get<bool>() >= rOperand->get<double>());
	}
	else if (rOperand->type == L"bool") {
		return makeValue<bool>(lOperand->get<bool>() >= rOperand->get<bool>());
	}
	else if (rOperand->type == L"string") {
		auto rvalue = cast<double, std::wstring>(rOperand->get<std::wstring>());
		return makeValue<bool>(lOperand->get<bool>() >= rvalue);
	}

	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> Boolean::LessEqual(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		return makeValue<bool>(lOperand->get<bool>() <= rOperand->get<int64_t>());
	}
	else if (rOperand->type == L"float") {
		return makeValue<bool>(lOperand->get<bool>() <= rOperand->get<double>());
	}
	else if (rOperand->type == L"bool") {
		return makeValue<bool>(lOperand->get<bool>() <= rOperand->get<bool>());
	}
	else if (rOperand->type == L"string") {
		auto rvalue = cast<double, std::wstring>(rOperand->get<std::wstring>());
		return makeValue<bool>(lOperand->get<bool>() <= rvalue);
	}

	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> Boolean::LogicalAnd(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		return makeValue<bool>(lOperand->get<bool>() && rOperand->get<int64_t>());
	}
	else if (rOperand->type == L"float") {
		return makeValue<bool>(lOperand->get<bool>() && rOperand->get<double>());
	}
	else if (rOperand->type == L"bool") {
		return makeValue<bool>(lOperand->get<bool>() && rOperand->get<bool>());
	}
	else if (rOperand->type == L"string") {
		auto rvalue = cast<double, std::wstring>(rOperand->get<std::wstring>());
		return makeValue<bool>(lOperand->get<bool>() && rvalue);
	}

	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> Boolean::LogicalOr(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		return makeValue<bool>(lOperand->get<bool>() || rOperand->get<int64_t>());
	}
	else if (rOperand->type == L"float") {
		return makeValue<bool>(lOperand->get<bool>() || rOperand->get<double>());
	}
	else if (rOperand->type == L"bool") {
		return makeValue<bool>(lOperand->get<bool>() || rOperand->get<bool>());
	}
	else if (rOperand->type == L"string") {
		auto rvalue = cast<double, std::wstring>(rOperand->get<std::wstring>());
		return makeValue<bool>(lOperand->get<bool>() || rvalue);
	}

	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> Boolean::BitwiseAnd(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		throw std::runtime_error("Cannot apply bitwise and operation between type bool and type int");
	}
	else if (rOperand->type == L"float") {
		throw std::runtime_error("Cannot apply bitwise and operation between type bool and type float");
	}
	else if (rOperand->type == L"bool") {
		throw std::runtime_error("Cannot apply bitwise and operation between type bool and type bool");
	}
	else if (rOperand->type == L"string") {
		throw std::runtime_error("Cannot apply bitwise and operation between type bool and type string");
	}

	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> Boolean::BitwiseOr(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		throw std::runtime_error("Cannot apply bitwise or operation between type bool and type int");
	}
	else if (rOperand->type == L"float") {
		throw std::runtime_error("Cannot apply bitwise or operation between type bool and type float");
	}
	else if (rOperand->type == L"bool") {
		throw std::runtime_error("Cannot apply bitwise or operation between type bool and type bool");
	}
	else if (rOperand->type == L"string") {
		throw std::runtime_error("Cannot apply bitwise or operation between type bool and type string");
	}

	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> Boolean::BitwiseXor(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		throw std::runtime_error("Cannot apply bitwise xor operation between type bool and type int");
	}
	else if (rOperand->type == L"float") {
		throw std::runtime_error("Cannot apply bitwise xor operation between type bool and type float");
	}
	else if (rOperand->type == L"bool") {
		throw std::runtime_error("Cannot apply bitwise xor operation between type bool and type bool");
	}
	else if (rOperand->type == L"string") {
		throw std::runtime_error("Cannot apply bitwise xor operation between type bool and type string");
	}

	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> Boolean::LeftShift(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		throw std::runtime_error("Cannot apply leftshift operation between type bool and type int");
	}
	else if (rOperand->type == L"float") {
		throw std::runtime_error("Cannot apply leftshift operation between type bool and type float");
	}
	else if (rOperand->type == L"bool") {
		throw std::runtime_error("Cannot apply leftshift operation between type bool and type bool");
	}
	else if (rOperand->type == L"string") {
		throw std::runtime_error("Cannot apply leftshift operation between type bool and type string");
	}

	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> Boolean::RightShift(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		throw std::runtime_error("Cannot apply rightshift operation between type bool and type int");
	}
	else if (rOperand->type == L"float") {
		throw std::runtime_error("Cannot apply rightshift operation between type bool and type float");
	}
	else if (rOperand->type == L"bool") {
		throw std::runtime_error("Cannot apply rightshift operation between type bool and type bool");
	}
	else if (rOperand->type == L"string") {
		throw std::runtime_error("Cannot apply rightshift operation between type bool and type string");
	}

	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> Boolean::LeftShiftAssignment(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		throw std::runtime_error("Cannot apply leftshift operation between type bool and type int");
	}
	else if (rOperand->type == L"float") {
		throw std::runtime_error("Cannot apply leftshift operation between type bool and type float");
	}
	else if (rOperand->type == L"bool") {
		throw std::runtime_error("Cannot apply leftshift operation between type bool and type bool");
	}
	else if (rOperand->type == L"string") {
		throw std::runtime_error("Cannot apply leftshift operation between type bool and type string");
	}

	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> Boolean::RightShiftAssignment(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		throw std::runtime_error("Cannot apply rightshift operation between type bool and type int");
	}
	else if (rOperand->type == L"float") {
		throw std::runtime_error("Cannot apply rightshift operation between type bool and type float");
	}
	else if (rOperand->type == L"bool") {
		throw std::runtime_error("Cannot apply rightshift operation between type bool and type bool");
	}
	else if (rOperand->type == L"string") {
		throw std::runtime_error("Cannot apply rightshift operation between type bool and type string");
	}

	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> Boolean::Assignment(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		return changeValue<bool>(lOperand, rOperand->get<int64_t>());
	}
	else if (rOperand->type == L"float") {
		return changeValue<bool>(lOperand, rOperand->get<double>());
	}
	else if (rOperand->type == L"bool") {
		return changeValue<bool>(lOperand, rOperand->get<bool>());
	}
	else if (rOperand->type == L"string") {
		auto rvalue = cast<double, std::wstring>(rOperand->get<std::wstring>());
		return changeValue<bool>(lOperand, rvalue);
	}

	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> Boolean::AdditionAssignment(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		return changeValue<bool>(lOperand, lOperand->get<bool>() + rOperand->get<int64_t>());
	}
	else if (rOperand->type == L"float") {
		return changeValue<bool>(lOperand, lOperand->get<bool>() + rOperand->get<double>());
	}
	else if (rOperand->type == L"bool") {
		return changeValue<bool>(lOperand, lOperand->get<bool>() + rOperand->get<bool>());
	}
	else if (rOperand->type == L"string") {
		auto rvalue = cast<double, std::wstring>(rOperand->get<std::wstring>());
		return changeValue<bool>(lOperand, lOperand->get<bool>() + rvalue);
	}

	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> Boolean::SubtractionAssignment(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		return changeValue<bool>(lOperand, lOperand->get<bool>() - rOperand->get<int64_t>());
	}
	else if (rOperand->type == L"float") {
		return changeValue<bool>(lOperand, lOperand->get<bool>() - rOperand->get<double>());
	}
	else if (rOperand->type == L"bool") {
		return changeValue<bool>(lOperand, lOperand->get<bool>() - rOperand->get<bool>());
	}
	else if (rOperand->type == L"string") {
		auto rvalue = cast<double, std::wstring>(rOperand->get<std::wstring>());
		return changeValue<bool>(lOperand, lOperand->get<bool>() - rvalue);
	}

	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> Boolean::MultiplicationAssignment(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		return changeValue<bool>(lOperand, lOperand->get<bool>() * rOperand->get<int64_t>());
	}
	else if (rOperand->type == L"float") {
		return changeValue<bool>(lOperand, lOperand->get<bool>() * rOperand->get<double>());
	}
	else if (rOperand->type == L"bool") {
		return changeValue<bool>(lOperand, lOperand->get<bool>() * rOperand->get<bool>());
	}
	else if (rOperand->type == L"string") {
		auto rvalue = cast<double, std::wstring>(rOperand->get<std::wstring>());
		return changeValue<bool>(lOperand, lOperand->get<bool>() * rvalue);
	}

	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> Boolean::DivisionAssignment(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		auto rvalue = rOperand->get<int64_t>();
		if (rvalue == 0) {
			return changeValue<bool>(lOperand, 0);
		}
		return changeValue<bool>(lOperand, lOperand->get<bool>() / rvalue);
	}
	else if (rOperand->type == L"float") {
		auto rvalue = rOperand->get<double>();
		if (rvalue == 0) {
			return changeValue<bool>(lOperand, 0);
		}
		return changeValue<bool>(lOperand, lOperand->get<bool>() / rvalue);
	}
	else if (rOperand->type == L"bool") {
		auto rvalue = rOperand->get<bool>();
		if (rvalue == 0) {
			return changeValue<bool>(lOperand, 0);
		}
		return changeValue<bool>(lOperand, lOperand->get<bool>() / rvalue);
	}
	else if (rOperand->type == L"string") {
		auto rvalue = cast<double, std::wstring>(rOperand->get<std::wstring>());
		if (rvalue == 0) {
			return changeValue<bool>(lOperand, 0);
		}
		return changeValue<bool>(lOperand, lOperand->get<bool>() / rvalue);
	}

	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> Boolean::ModulusAssignment(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		throw std::runtime_error("Cannot apply modulo operation between type bool and type int");
	}
	else if (rOperand->type == L"float") {
		throw std::runtime_error("Cannot apply modulo operation between type bool and type float");
	}
	else if (rOperand->type == L"bool") {
		throw std::runtime_error("Cannot apply modulo operation between type bool and type bool");
	}
	else if (rOperand->type == L"string") {
		throw std::runtime_error("Cannot apply modulo operation between type bool and type string");
	}

	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> Boolean::ExponentiationAssignment(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		auto rvalue = rOperand->get<int64_t>();
		if (rvalue == 0) {
			return changeValue<bool>(lOperand, lOperand->get<bool>());
		}
		return changeValue<bool>(lOperand, std::pow(lOperand->get<bool>(), rvalue));
	}
	else if (rOperand->type == L"float") {
		auto rvalue = rOperand->get<double>();
		if (rvalue == 0) {
			return changeValue<bool>(lOperand, lOperand->get<bool>());
		}
		return changeValue<bool>(lOperand, std::pow(lOperand->get<bool>(), rvalue));
	}
	else if (rOperand->type == L"bool") {
		auto rvalue = rOperand->get<bool>();
		if (rvalue == 0) {
			return changeValue<bool>(lOperand, lOperand->get<bool>());
		}
		return changeValue<bool>(lOperand, std::pow(lOperand->get<bool>(), rvalue));
	}
	else if (rOperand->type == L"string") {
		auto rvalue = cast<double, std::wstring>(rOperand->get<std::wstring>());
		if (rvalue == 0) {
			return changeValue<bool>(lOperand, lOperand->get<bool>());
		}
		return changeValue<bool>(lOperand, std::pow(lOperand->get<bool>(), rvalue));
	}

	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> Boolean::BitwiseAndAssignment(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		throw std::runtime_error("Cannot apply bitwise and operation between type bool and type int");
	}
	else if (rOperand->type == L"float") {
		throw std::runtime_error("Cannot apply bitwise and operation between type bool and type float");
	}
	else if (rOperand->type == L"bool") {
		throw std::runtime_error("Cannot apply bitwise and operation between type bool and type bool");
	}
	else if (rOperand->type == L"string") {
		throw std::runtime_error("Cannot apply bitwise and operation between type bool and type string");
	}

	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> Boolean::BitwiseOrAssignment(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		throw std::runtime_error("Cannot apply bitwise or operation between type bool and type int");
	}
	else if (rOperand->type == L"float") {
		throw std::runtime_error("Cannot apply bitwise or operation between type bool and type float");
	}
	else if (rOperand->type == L"bool") {
		throw std::runtime_error("Cannot apply bitwise or operation between type bool and type bool");
	}
	else if (rOperand->type == L"string") {
		throw std::runtime_error("Cannot apply bitwise or operation between type bool and type string");
	}

	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> Boolean::BitwiseXorAssignment(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		throw std::runtime_error("Cannot apply bitwise xor operation between type bool and type int");
	}
	else if (rOperand->type == L"float") {
		throw std::runtime_error("Cannot apply bitwise xor operation between type bool and type float");
	}
	else if (rOperand->type == L"bool") {
		throw std::runtime_error("Cannot apply bitwise xor operation between type bool and type bool");
	}
	else if (rOperand->type == L"string") {
		throw std::runtime_error("Cannot apply bitwise xor operation between type bool and type string");
	}

	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> Boolean::LogicalAndAssignment(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		auto rvalue = rOperand->get<int64_t>();
		return changeValue<bool>(lOperand, lOperand->get<bool>() && rvalue);
	}
	else if (rOperand->type == L"float") {
		auto rvalue = rOperand->get<double>();
		return changeValue<bool>(lOperand, lOperand->get<bool>() && rvalue);
	}
	else if (rOperand->type == L"bool") {
		auto rvalue = rOperand->get<int64_t>();
		return changeValue<bool>(lOperand, lOperand->get<bool>() && rvalue);
	}
	else if (rOperand->type == L"string") {
		auto rvalue = cast<double, std::wstring>(rOperand->get<std::wstring>());
		return changeValue<bool>(lOperand, lOperand->get<bool>() && rvalue);
	}

	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> Boolean::LogicalOrAssignment(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		auto rvalue = rOperand->get<int64_t>();
		return changeValue<bool>(lOperand, lOperand->get<bool>() || rvalue);
	}
	else if (rOperand->type == L"float") {
		auto rvalue = rOperand->get<double>();
		return changeValue<bool>(lOperand, lOperand->get<bool>() || rvalue);
	}
	else if (rOperand->type == L"bool") {
		auto rvalue = rOperand->get<int64_t>();
		return changeValue<bool>(lOperand, lOperand->get<bool>() || rvalue);
	}
	else if (rOperand->type == L"string") {
		auto rvalue = cast<double, std::wstring>(rOperand->get<std::wstring>());
		return changeValue<bool>(lOperand, lOperand->get<bool>() || rvalue);
	}

	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> Boolean::UnaryNegation(std::shared_ptr<Value> lOperand) {
	return makeValue<bool>(-lOperand->get<bool>());
}

std::shared_ptr<Value> Boolean::UnaryPlus(std::shared_ptr<Value> lOperand) {
	return makeValue<bool>(std::llabs(lOperand->get<bool>()));
}

std::shared_ptr<Value> Boolean::UnaryAbs(std::shared_ptr<Value> lOperand) {
	return makeValue<bool>(std::llabs(lOperand->get<bool>()));
}

std::shared_ptr<Value> Boolean::LogicalNot(std::shared_ptr<Value> lOperand) {
	return makeValue<bool>(!lOperand->get<bool>());
}

std::shared_ptr<Value> Boolean::BitwiseNot(std::shared_ptr<Value> lOperand) {
	throw std::runtime_error("Cannot apply bitwise not operation on type float");
}

std::shared_ptr<Value> Boolean::FrontIncrement(std::shared_ptr<Value> lOperand) {
	changeValue<bool>(lOperand, lOperand->get<bool>() + 1);
	return makeValue<bool>(lOperand->get<bool>());
}

std::shared_ptr<Value> Boolean::FrontDecrement(std::shared_ptr<Value> lOperand) {
	changeValue<bool>(lOperand, lOperand->get<bool>() - 1);
	return makeValue<bool>(lOperand->get<bool>());
}

std::shared_ptr<Value> Boolean::EndIncrement(std::shared_ptr<Value> lOperand) {
	changeValue<bool>(lOperand, lOperand->get<bool>() + 1);
	return makeValue<bool>(lOperand->get<bool>() - 1);
}

std::shared_ptr<Value> Boolean::EndDecrement(std::shared_ptr<Value> lOperand) {
	changeValue<bool>(lOperand, lOperand->get<bool>() - 1);
	return makeValue<bool>(lOperand->get<bool>() + 1);
}
