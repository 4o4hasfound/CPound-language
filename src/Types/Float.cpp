#include "Types/Float.hpp"

std::shared_ptr<Value> Float::BinaryOperation(OperatorType operatorType, std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
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

std::shared_ptr<Value> Float::UnaryOperation(OperatorType operatorType, std::shared_ptr<Value> operand) {
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

std::shared_ptr<Value> Float::Addition(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		return makeValue<double>(lOperand->get<double>() + rOperand->get<int64_t>());
	}
	else if (rOperand->type == L"float") {
		return makeValue<double>(lOperand->get<double>() + rOperand->get<double>());
	}
	else if (rOperand->type == L"bool") {
		return makeValue<double>(lOperand->get<double>() + rOperand->get<bool>());
	}
	else if (rOperand->type == L"string") {
		auto rvalue = cast<double, std::wstring>(rOperand->get<std::wstring>());
		return makeValue<double>(lOperand->get<double>() + rvalue);
	}

	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> Float::Subtraction(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		return makeValue<double>(lOperand->get<double>() - rOperand->get<int64_t>());
	}
	else if (rOperand->type == L"float") {
		return makeValue<double>(lOperand->get<double>() - rOperand->get<double>());
	}
	else if (rOperand->type == L"bool") {
		return makeValue<double>(lOperand->get<double>() - rOperand->get<bool>());
	}
	else if (rOperand->type == L"string") {
		auto rvalue = cast<double, std::wstring>(rOperand->get<std::wstring>());
		return makeValue<double>(lOperand->get<double>() - rvalue);
	}

	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> Float::Multiplication(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		return makeValue<double>(lOperand->get<double>() * rOperand->get<int64_t>());
	}
	else if (rOperand->type == L"float") {
		return makeValue<double>(lOperand->get<double>() * rOperand->get<double>());
	}
	else if (rOperand->type == L"bool") {
		return makeValue<double>(lOperand->get<double>() * rOperand->get<bool>());
	}
	else if (rOperand->type == L"string") {
		auto rvalue = cast<double, std::wstring>(rOperand->get<std::wstring>());
		return makeValue<double>(lOperand->get<double>() - rvalue);
	}

	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> Float::Division(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		auto rvalue = rOperand->get<int64_t>();
		if (rvalue == 0) {
			return makeValue<double>(0);
		}
		return makeValue<double>(lOperand->get<double>() / rvalue);
	}
	else if (rOperand->type == L"float") {
		auto rvalue = rOperand->get<double>();
		if (rvalue == 0) {
			return makeValue<double>(0);
		}
		return makeValue<double>(lOperand->get<double>() / rvalue);
	}
	else if (rOperand->type == L"bool") {
		auto rvalue = rOperand->get<bool>();
		if (rvalue == 0) {
			return makeValue<double>(0);
		}
		return makeValue<double>(lOperand->get<double>() / rvalue);
	}
	else if (rOperand->type == L"string") {
		auto rvalue = cast<double, std::wstring>(rOperand->get<std::wstring>());
		if (std::ceil(rvalue) == rvalue) {
			if (rvalue == 0) {
				return makeValue<double>(0);
			}
			return makeValue<double>(lOperand->get<double>() / rvalue);
		}
	}

	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> Float::Modulus(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		throw std::runtime_error("Cannot apply modulo operation between type float and type int");
	}
	else if (rOperand->type == L"float") {
		throw std::runtime_error("Cannot apply modulo operation between type float and type float");
	}
	else if (rOperand->type == L"bool") {
		throw std::runtime_error("Cannot apply modulo operation between type float and type bool");
	}
	else if (rOperand->type == L"string") {
		throw std::runtime_error("Cannot apply modulo operation between type float and type string");
	}

	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> Float::Exponentiation(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		return makeValue<double>(std::pow(lOperand->get<double>(), rOperand->get<int64_t>()));
	}
	else if (rOperand->type == L"float") {
		return makeValue<double>(std::pow(lOperand->get<double>(), rOperand->get<double>()));
	}
	else if (rOperand->type == L"bool") {
		return makeValue<double>(std::pow(lOperand->get<double>(), rOperand->get<bool>()));
	}
	else if (rOperand->type == L"string") {
		auto rvalue = cast<double, std::wstring>(rOperand->get<std::wstring>());
		return makeValue<double>(std::pow(lOperand->get<double>(), rvalue));
	}

	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> Float::EqualTo(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		return makeValue<bool>(lOperand->get<double>() == rOperand->get<int64_t>());
	}
	else if (rOperand->type == L"float") {
		return makeValue<bool>(lOperand->get<double>() == rOperand->get<double>());
	}
	else if (rOperand->type == L"bool") {
		return makeValue<bool>(lOperand->get<double>() == rOperand->get<bool>());
	}
	else if (rOperand->type == L"string") {
		auto rvalue = cast<double, std::wstring>(rOperand->get<std::wstring>());
		return makeValue<bool>(lOperand->get<double>() == rvalue);
	}

	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> Float::NotEqualTo(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		return makeValue<bool>(lOperand->get<double>() != rOperand->get<int64_t>());
	}
	else if (rOperand->type == L"float") {
		return makeValue<bool>(lOperand->get<double>() != rOperand->get<double>());
	}
	else if (rOperand->type == L"bool") {
		return makeValue<bool>(lOperand->get<double>() != rOperand->get<bool>());
	}
	else if (rOperand->type == L"string") {
		auto rvalue = cast<double, std::wstring>(rOperand->get<std::wstring>());
		return makeValue<bool>(lOperand->get<double>() != rvalue);
	}

	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> Float::Greater(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		return makeValue<bool>(lOperand->get<double>() > rOperand->get<int64_t>());
	}
	else if (rOperand->type == L"float") {
		return makeValue<bool>(lOperand->get<double>() > rOperand->get<double>());
	}
	else if (rOperand->type == L"bool") {
		return makeValue<bool>(lOperand->get<double>() > rOperand->get<bool>());
	}
	else if (rOperand->type == L"string") {
		auto rvalue = cast<double, std::wstring>(rOperand->get<std::wstring>());
		return makeValue<bool>(lOperand->get<double>() > rvalue);
	}

	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> Float::Less(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		return makeValue<bool>(lOperand->get<double>() < rOperand->get<int64_t>());
	}
	else if (rOperand->type == L"float") {
		return makeValue<bool>(lOperand->get<double>() < rOperand->get<double>());
	}
	else if (rOperand->type == L"bool") {
		return makeValue<bool>(lOperand->get<double>() < rOperand->get<bool>());
	}
	else if (rOperand->type == L"string") {
		auto rvalue = cast<double, std::wstring>(rOperand->get<std::wstring>());
		return makeValue<bool>(lOperand->get<double>() < rvalue);
	}

	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> Float::GreaterEqual(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		return makeValue<bool>(lOperand->get<double>() >= rOperand->get<int64_t>());
	}
	else if (rOperand->type == L"float") {
		return makeValue<bool>(lOperand->get<double>() >= rOperand->get<double>());
	}
	else if (rOperand->type == L"bool") {
		return makeValue<bool>(lOperand->get<double>() >= rOperand->get<bool>());
	}
	else if (rOperand->type == L"string") {
		auto rvalue = cast<double, std::wstring>(rOperand->get<std::wstring>());
		return makeValue<bool>(lOperand->get<double>() >= rvalue);
	}

	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> Float::LessEqual(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		return makeValue<bool>(lOperand->get<double>() <= rOperand->get<int64_t>());
	}
	else if (rOperand->type == L"float") {
		return makeValue<bool>(lOperand->get<double>() <= rOperand->get<double>());
	}
	else if (rOperand->type == L"bool") {
		return makeValue<bool>(lOperand->get<double>() <= rOperand->get<bool>());
	}
	else if (rOperand->type == L"string") {
		auto rvalue = cast<double, std::wstring>(rOperand->get<std::wstring>());
		return makeValue<bool>(lOperand->get<double>() <= rvalue);
	}

	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> Float::LogicalAnd(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		return makeValue<bool>(lOperand->get<double>() && rOperand->get<int64_t>());
	}
	else if (rOperand->type == L"float") {
		return makeValue<bool>(lOperand->get<double>() && rOperand->get<double>());
	}
	else if (rOperand->type == L"bool") {
		return makeValue<bool>(lOperand->get<double>() && rOperand->get<bool>());
	}
	else if (rOperand->type == L"string") {
		auto rvalue = cast<double, std::wstring>(rOperand->get<std::wstring>());
		return makeValue<bool>(lOperand->get<double>() && rvalue);
	}

	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> Float::LogicalOr(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		return makeValue<bool>(lOperand->get<double>() || rOperand->get<int64_t>());
	}
	else if (rOperand->type == L"float") {
		return makeValue<bool>(lOperand->get<double>() || rOperand->get<double>());
	}
	else if (rOperand->type == L"bool") {
		return makeValue<bool>(lOperand->get<double>() || rOperand->get<bool>());
	}
	else if (rOperand->type == L"string") {
		auto rvalue = cast<double, std::wstring>(rOperand->get<std::wstring>());
		return makeValue<bool>(lOperand->get<double>() || rvalue);
	}

	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> Float::BitwiseAnd(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		throw std::runtime_error("Cannot apply bitwise and operation between type float and type int");
	}
	else if (rOperand->type == L"float") {
		throw std::runtime_error("Cannot apply bitwise and operation between type float and type float");
	}
	else if (rOperand->type == L"bool") {
		throw std::runtime_error("Cannot apply bitwise and operation between type float and type bool");
	}
	else if (rOperand->type == L"string") {
		throw std::runtime_error("Cannot apply bitwise and operation between type float and type string");
	}

	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> Float::BitwiseOr(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		throw std::runtime_error("Cannot apply bitwise or operation between type float and type int");
	}
	else if (rOperand->type == L"float") {
		throw std::runtime_error("Cannot apply bitwise or operation between type float and type float");
	}
	else if (rOperand->type == L"bool") {
		throw std::runtime_error("Cannot apply bitwise or operation between type float and type bool");
	}
	else if (rOperand->type == L"string") {
		throw std::runtime_error("Cannot apply bitwise or operation between type float and type string");
	}

	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> Float::BitwiseXor(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		throw std::runtime_error("Cannot apply bitwise xor operation between type float and type int");
	}
	else if (rOperand->type == L"float") {
		throw std::runtime_error("Cannot apply bitwise xor operation between type float and type float");
	}
	else if (rOperand->type == L"bool") {
		throw std::runtime_error("Cannot apply bitwise xor operation between type float and type bool");
	}
	else if (rOperand->type == L"string") {
		throw std::runtime_error("Cannot apply bitwise xor operation between type float and type string");
	}

	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> Float::LeftShift(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		throw std::runtime_error("Cannot apply leftshift operation between type float and type int");
	}
	else if (rOperand->type == L"float") {
		throw std::runtime_error("Cannot apply leftshift operation between type float and type float");
	}
	else if (rOperand->type == L"bool") {
		throw std::runtime_error("Cannot apply leftshift operation between type float and type bool");
	}
	else if (rOperand->type == L"string") {
		throw std::runtime_error("Cannot apply leftshift operation between type float and type string");
	}

	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> Float::RightShift(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		throw std::runtime_error("Cannot apply rightshift operation between type float and type int");
	}
	else if (rOperand->type == L"float") {
		throw std::runtime_error("Cannot apply rightshift operation between type float and type float");
	}
	else if (rOperand->type == L"bool") {
		throw std::runtime_error("Cannot apply rightshift operation between type float and type bool");
	}
	else if (rOperand->type == L"string") {
		throw std::runtime_error("Cannot apply rightshift operation between type float and type string");
	}

	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> Float::LeftShiftAssignment(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		throw std::runtime_error("Cannot apply leftshift operation between type float and type int");
	}
	else if (rOperand->type == L"float") {
		throw std::runtime_error("Cannot apply leftshift operation between type float and type float");
	}
	else if (rOperand->type == L"bool") {
		throw std::runtime_error("Cannot apply leftshift operation between type float and type bool");
	}
	else if (rOperand->type == L"string") {
		throw std::runtime_error("Cannot apply leftshift operation between type float and type string");
	}

	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> Float::RightShiftAssignment(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		throw std::runtime_error("Cannot apply rightshift operation between type float and type int");
	}
	else if (rOperand->type == L"float") {
		throw std::runtime_error("Cannot apply rightshift operation between type float and type float");
	}
	else if (rOperand->type == L"bool") {
		throw std::runtime_error("Cannot apply rightshift operation between type float and type bool");
	}
	else if (rOperand->type == L"string") {
		throw std::runtime_error("Cannot apply rightshift operation between type float and type string");
	}

	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> Float::Assignment(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		return changeValue<double>(lOperand, rOperand->get<int64_t>());
	}
	else if (rOperand->type == L"float") {
		return changeValue<double>(lOperand, rOperand->get<double>());
	}
	else if (rOperand->type == L"bool") {
		return changeValue<double>(lOperand, rOperand->get<bool>());
	}
	else if (rOperand->type == L"string") {
		auto rvalue = cast<double, std::wstring>(rOperand->get<std::wstring>());
		return changeValue<double>(lOperand, rvalue);
	}

	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> Float::AdditionAssignment(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		return changeValue<double>(lOperand, lOperand->get<double>() + rOperand->get<int64_t>());
	}
	else if (rOperand->type == L"float") {
		return changeValue<double>(lOperand, lOperand->get<double>() + rOperand->get<double>());
	}
	else if (rOperand->type == L"bool") {
		return changeValue<double>(lOperand, lOperand->get<double>() + rOperand->get<bool>());
	}
	else if (rOperand->type == L"string") {
		auto rvalue = cast<double, std::wstring>(rOperand->get<std::wstring>());
		return changeValue<double>(lOperand, lOperand->get<double>() + rvalue);
	}

	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> Float::SubtractionAssignment(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		return changeValue<double>(lOperand, lOperand->get<double>() - rOperand->get<int64_t>());
	}
	else if (rOperand->type == L"float") {
		return changeValue<double>(lOperand, lOperand->get<double>() - rOperand->get<double>());
	}
	else if (rOperand->type == L"bool") {
		return changeValue<double>(lOperand, lOperand->get<double>() - rOperand->get<bool>());
	}
	else if (rOperand->type == L"string") {
		auto rvalue = cast<double, std::wstring>(rOperand->get<std::wstring>());
		return changeValue<double>(lOperand, lOperand->get<double>() - rvalue);
	}

	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> Float::MultiplicationAssignment(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		return changeValue<double>(lOperand, lOperand->get<double>() * rOperand->get<int64_t>());
	}
	else if (rOperand->type == L"float") {
		return changeValue<double>(lOperand, lOperand->get<double>() * rOperand->get<double>());
	}
	else if (rOperand->type == L"bool") {
		return changeValue<double>(lOperand, lOperand->get<double>() * rOperand->get<bool>());
	}
	else if (rOperand->type == L"string") {
		auto rvalue = cast<double, std::wstring>(rOperand->get<std::wstring>());
		return changeValue<double>(lOperand, lOperand->get<double>() * rvalue);
	}

	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> Float::DivisionAssignment(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		auto rvalue = rOperand->get<int64_t>();
		if (rvalue == 0) {
			return changeValue<double>(lOperand, 0);
		}
		return changeValue<double>(lOperand, lOperand->get<double>() / rvalue);
	}
	else if (rOperand->type == L"float") {
		auto rvalue = rOperand->get<double>();
		if (rvalue == 0) {
			return changeValue<double>(lOperand, 0);
		}
		return changeValue<double>(lOperand, lOperand->get<double>() / rvalue);
	}
	else if (rOperand->type == L"bool") {
		auto rvalue = rOperand->get<bool>();
		if (rvalue == 0) {
			return changeValue<double>(lOperand, 0);
		}
		return changeValue<double>(lOperand, lOperand->get<double>() / rvalue);
	}
	else if (rOperand->type == L"string") {
		auto rvalue = cast<double, std::wstring>(rOperand->get<std::wstring>());
		if (rvalue == 0) {
			return changeValue<double>(lOperand, 0);
		}
		return changeValue<double>(lOperand, lOperand->get<double>() / rvalue);
	}

	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> Float::ModulusAssignment(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		throw std::runtime_error("Cannot apply modulo operation between type float and type int");
	}
	else if (rOperand->type == L"float") {
		throw std::runtime_error("Cannot apply modulo operation between type float and type float");
	}
	else if (rOperand->type == L"bool") {
		throw std::runtime_error("Cannot apply modulo operation between type float and type bool");
	}
	else if (rOperand->type == L"string") {
		throw std::runtime_error("Cannot apply modulo operation between type float and type string");
	}

	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> Float::ExponentiationAssignment(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		auto rvalue = rOperand->get<int64_t>();
		if (rvalue == 0) {
			return changeValue<double>(lOperand, lOperand->get<double>());
		}
		return changeValue<double>(lOperand, std::pow(lOperand->get<double>(), rvalue));
	}
	else if (rOperand->type == L"float") {
		auto rvalue = rOperand->get<double>();
		if (rvalue == 0) {
			return changeValue<double>(lOperand, lOperand->get<double>());
		}
		return changeValue<double>(lOperand, std::pow(lOperand->get<double>(), rvalue));
	}
	else if (rOperand->type == L"bool") {
		auto rvalue = rOperand->get<bool>();
		if (rvalue == 0) {
			return changeValue<double>(lOperand, lOperand->get<double>());
		}
		return changeValue<double>(lOperand, std::pow(lOperand->get<double>(), rvalue));
	}
	else if (rOperand->type == L"string") {
		auto rvalue = cast<double, std::wstring>(rOperand->get<std::wstring>());
		if (rvalue == 0) {
			return changeValue<double>(lOperand, lOperand->get<double>());
		}
		return changeValue<double>(lOperand, std::pow(lOperand->get<double>(), rvalue));
	}

	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> Float::BitwiseAndAssignment(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		throw std::runtime_error("Cannot apply bitwise and operation between type float and type int");
	}
	else if (rOperand->type == L"float") {
		throw std::runtime_error("Cannot apply bitwise and operation between type float and type float");
	}
	else if (rOperand->type == L"bool") {
		throw std::runtime_error("Cannot apply bitwise and operation between type float and type bool");
	}
	else if (rOperand->type == L"string") {
		throw std::runtime_error("Cannot apply bitwise and operation between type float and type string");
	}

	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> Float::BitwiseOrAssignment(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		throw std::runtime_error("Cannot apply bitwise or operation between type float and type int");
	}
	else if (rOperand->type == L"float") {
		throw std::runtime_error("Cannot apply bitwise or operation between type float and type float");
	}
	else if (rOperand->type == L"bool") {
		throw std::runtime_error("Cannot apply bitwise or operation between type float and type bool");
	}
	else if (rOperand->type == L"string") {
		throw std::runtime_error("Cannot apply bitwise or operation between type float and type string");
	}

	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> Float::BitwiseXorAssignment(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		throw std::runtime_error("Cannot apply bitwise xor operation between type float and type int");
	}
	else if (rOperand->type == L"float") {
		throw std::runtime_error("Cannot apply bitwise xor operation between type float and type float");
	}
	else if (rOperand->type == L"bool") {
		throw std::runtime_error("Cannot apply bitwise xor operation between type float and type bool");
	}
	else if (rOperand->type == L"string") {
		throw std::runtime_error("Cannot apply bitwise xor operation between type float and type string");
	}

	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> Float::LogicalAndAssignment(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		auto rvalue = rOperand->get<int64_t>();
		return changeValue<double>(lOperand, lOperand->get<double>() && rvalue);
	}
	else if (rOperand->type == L"float") {
		auto rvalue = rOperand->get<double>();
		return changeValue<double>(lOperand, lOperand->get<double>() && rvalue);
	}
	else if (rOperand->type == L"bool") {
		auto rvalue = rOperand->get<int64_t>();
		return changeValue<double>(lOperand, lOperand->get<double>() && rvalue);
	}
	else if (rOperand->type == L"string") {
		auto rvalue = cast<double, std::wstring>(rOperand->get<std::wstring>());
		return changeValue<double>(lOperand, lOperand->get<double>() && rvalue);
	}

	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> Float::LogicalOrAssignment(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		auto rvalue = rOperand->get<int64_t>();
		return changeValue<double>(lOperand, lOperand->get<double>() || rvalue);
	}
	else if (rOperand->type == L"float") {
		auto rvalue = rOperand->get<double>();
		return changeValue<double>(lOperand, lOperand->get<double>() || rvalue);
	}
	else if (rOperand->type == L"bool") {
		auto rvalue = rOperand->get<int64_t>();
		return changeValue<double>(lOperand, lOperand->get<double>() || rvalue);
	}
	else if (rOperand->type == L"string") {
		auto rvalue = cast<double, std::wstring>(rOperand->get<std::wstring>());
		return changeValue<double>(lOperand, lOperand->get<double>() || rvalue);
	}

	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> Float::UnaryNegation(std::shared_ptr<Value> lOperand) {
	return makeValue<double>(-lOperand->get<double>());
}

std::shared_ptr<Value> Float::UnaryPlus(std::shared_ptr<Value> lOperand) {
	return makeValue<double>(std::llabs(lOperand->get<double>()));
}

std::shared_ptr<Value> Float::UnaryAbs(std::shared_ptr<Value> lOperand) {
	return makeValue<double>(std::llabs(lOperand->get<double>()));
}

std::shared_ptr<Value> Float::LogicalNot(std::shared_ptr<Value> lOperand) {
	return makeValue<bool>(!lOperand->get<double>());
}

std::shared_ptr<Value> Float::BitwiseNot(std::shared_ptr<Value> lOperand) {
	throw std::runtime_error("Cannot apply bitwise not operation on type float");
}

std::shared_ptr<Value> Float::FrontIncrement(std::shared_ptr<Value> lOperand) {
	changeValue<double>(lOperand, lOperand->get<double>() + 1);
	return makeValue<double>(lOperand->get<double>());
}

std::shared_ptr<Value> Float::FrontDecrement(std::shared_ptr<Value> lOperand) {
	changeValue<double>(lOperand, lOperand->get<double>() - 1);
	return makeValue<double>(lOperand->get<double>());
}

std::shared_ptr<Value> Float::EndIncrement(std::shared_ptr<Value> lOperand) {
	changeValue<double>(lOperand, lOperand->get<double>() + 1);
	return makeValue<double>(lOperand->get<double>() - 1);
}

std::shared_ptr<Value> Float::EndDecrement(std::shared_ptr<Value> lOperand) {
	changeValue<double>(lOperand, lOperand->get<double>() - 1);
	return makeValue<double>(lOperand->get<double>() + 1);
}
