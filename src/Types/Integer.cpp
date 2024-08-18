	#include "Types/Integer.hpp"

std::shared_ptr<Value> Integer::BinaryOperation(OperatorType operatorType, std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
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

std::shared_ptr<Value> Integer::UnaryOperation(OperatorType operatorType, std::shared_ptr<Value> operand) {
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

std::shared_ptr<Value> Integer::Addition(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		return makeValue<int64_t>(lOperand->get<int64_t>() + rOperand->get<int64_t>());
	}
	else if (rOperand->type == L"float") {
		return makeValue<double>(lOperand->get<int64_t>() + rOperand->get<double>());
	}
	else if (rOperand->type == L"bool") {
		return makeValue<int64_t>(lOperand->get<int64_t>() + rOperand->get<bool>());
	}
	else if (rOperand->type == L"string") {
		auto rvalue = cast<double, std::wstring>(rOperand->get<std::wstring>());
		if (std::ceil(rvalue) == rvalue) {
			// value is integer
			return makeValue<int64_t>(lOperand->get<int64_t>() + rvalue);
		}
		// value is float
		return makeValue<double>(lOperand->get<int64_t>() + rvalue);
	}
		
	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> Integer::Subtraction(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		return makeValue<int64_t>(lOperand->get<int64_t>() - rOperand->get<int64_t>());
	}
	else if (rOperand->type == L"float") {
		return makeValue<double>(lOperand->get<int64_t>() - rOperand->get<double>());
	}
	else if (rOperand->type == L"bool") {
		return makeValue<int64_t>(lOperand->get<int64_t>() - rOperand->get<bool>());
	}
	else if (rOperand->type == L"string") {
		auto rvalue = cast<double, std::wstring>(rOperand->get<std::wstring>());
		if (std::ceil(rvalue) == rvalue) {
			// value is integer
			return makeValue<int64_t>(lOperand->get<int64_t>() - rvalue);
		}
		// value is float
		return makeValue<double>(lOperand->get<int64_t>() - rvalue);
	}
		
	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> Integer::Multiplication(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		return makeValue<int64_t>(lOperand->get<int64_t>() * rOperand->get<int64_t>());
	}
	else if (rOperand->type == L"float") {
		return makeValue<double>(lOperand->get<int64_t>() * rOperand->get<double>());
	}
	else if (rOperand->type == L"bool") {
		return makeValue<int64_t>(lOperand->get<int64_t>() * rOperand->get<bool>());
	}
	else if (rOperand->type == L"string") {
		auto rvalue = cast<double, std::wstring>(rOperand->get<std::wstring>());
		if (std::ceil(rvalue) == rvalue) {
			// value is integer
			return makeValue<int64_t>(lOperand->get<int64_t>() * rvalue);
		}
		// value is float
		return makeValue<double>(lOperand->get<int64_t>() - rvalue);
	}
		
	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> Integer::Division(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		auto rvalue = rOperand->get<int64_t>();
		if (rvalue == 0) {
			return makeValue<int64_t>(0);
		}
		return makeValue<int64_t>(lOperand->get<int64_t>() / rvalue);
	}
	else if (rOperand->type == L"float") {
		auto rvalue = rOperand->get<double>();
		if (rvalue == 0) {
			return makeValue<double>(0);
		}
		return makeValue<double>(lOperand->get<int64_t>() / rvalue);
	}
	else if (rOperand->type == L"bool") {
		auto rvalue = rOperand->get<bool>();
		if (rvalue == 0) {
			return makeValue<int64_t>(0);
		}
		return makeValue<int64_t>(lOperand->get<int64_t>() / rvalue);
	}
	else if (rOperand->type == L"string") {
		auto rvalue = cast<double, std::wstring>(rOperand->get<std::wstring>());
		if (std::ceil(rvalue) == rvalue) {
			// value is integer
			if (rvalue == 0) {
				return makeValue<int64_t>(0);
			}
			return makeValue<int64_t>(lOperand->get<int64_t>() / rvalue);
		}
		else {
			// value is float
			if (rvalue == 0) {
				return makeValue<double>(0);
			}
			return makeValue<double>(lOperand->get<int64_t>() / rvalue);
		}
	}
		
	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> Integer::Modulus(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		auto rvalue = rOperand->get<int64_t>();
		if (rvalue == 0) {
			return makeValue<int64_t>(lOperand->get<int64_t>());
		}
		return makeValue<int64_t>(lOperand->get<int64_t>() % rvalue);
	}
	else if (rOperand->type == L"float") {
		auto rvalue = rOperand->get<double>();
		if (rvalue == 0) {
			return makeValue<double>(lOperand->get<int64_t>());
		}
		return makeValue<double>(std::fmod(lOperand->get<int64_t>(), rvalue));
	}
	else if (rOperand->type == L"bool") {
		auto rvalue = rOperand->get<bool>();
		return makeValue<int64_t>(std::fmod(lOperand->get<int64_t>(), rvalue));
	}
	else if (rOperand->type == L"string") {
		auto rvalue = cast<double, std::wstring>(rOperand->get<std::wstring>());
		if (std::ceil(rvalue) == rvalue) {
			// value is integer
			if (rvalue == 0) {
				return makeValue<int64_t>(lOperand->get<int64_t>());
			}
			return makeValue<int64_t>(lOperand->get<int64_t>() % static_cast<int64_t>(rvalue));
		}
		else {
			// value is float
			if (rvalue == 0) {
				return makeValue<double>(lOperand->get<int64_t>());
			}
			return makeValue<double>(std::fmod(lOperand->get<int64_t>(), rvalue));
		}
	}
		
	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> Integer::Exponentiation(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		return makeValue<int64_t>(std::pow(lOperand->get<int64_t>(), rOperand->get<int64_t>()));
	}
	else if (rOperand->type == L"float") {
		return makeValue<double>(std::pow(lOperand->get<int64_t>(), rOperand->get<double>()));
	}
	else if (rOperand->type == L"bool") {
		return makeValue<int64_t>(std::pow(lOperand->get<int64_t>(), rOperand->get<bool>()));
	}
	else if (rOperand->type == L"string") {
		auto rvalue = cast<double, std::wstring>(rOperand->get<std::wstring>());
		if (std::ceil(rvalue) == rvalue) {
			// value is integer
			return makeValue<int64_t>(std::pow(lOperand->get<int64_t>(), rvalue));
		}
		// value is float
		return makeValue<double>(std::pow(lOperand->get<int64_t>(), rvalue));
	}
		
	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> Integer::EqualTo(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		return makeValue<bool>(lOperand->get<int64_t>() == rOperand->get<int64_t>());
	}
	else if (rOperand->type == L"float") {
		return makeValue<bool>(lOperand->get<int64_t>() == rOperand->get<double>());
	}
	else if (rOperand->type == L"bool") {
		return makeValue<bool>(lOperand->get<int64_t>() == rOperand->get<bool>());
	}
	else if (rOperand->type == L"string") {
		auto rvalue = cast<double, std::wstring>(rOperand->get<std::wstring>());
		return makeValue<bool>(lOperand->get<int64_t>() == rvalue);
	}
		
	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> Integer::NotEqualTo(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		return makeValue<bool>(lOperand->get<int64_t>() != rOperand->get<int64_t>());
	}
	else if (rOperand->type == L"float") {
		return makeValue<bool>(lOperand->get<int64_t>() != rOperand->get<double>());
	}
	else if (rOperand->type == L"bool") {
		return makeValue<bool>(lOperand->get<int64_t>() != rOperand->get<bool>());
	}
	else if (rOperand->type == L"string") {
		auto rvalue = cast<double, std::wstring>(rOperand->get<std::wstring>());
		return makeValue<bool>(lOperand->get<int64_t>() != rvalue);
	}
		
	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> Integer::Greater(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		return makeValue<bool>(lOperand->get<int64_t>() > rOperand->get<int64_t>());
	}
	else if (rOperand->type == L"float") {
		return makeValue<bool>(lOperand->get<int64_t>() > rOperand->get<double>());
	}
	else if (rOperand->type == L"bool") {
		return makeValue<bool>(lOperand->get<int64_t>() > rOperand->get<bool>());
	}
	else if (rOperand->type == L"string") {
		auto rvalue = cast<double, std::wstring>(rOperand->get<std::wstring>());
		return makeValue<bool>(lOperand->get<int64_t>() > rvalue);
	}
		
	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> Integer::Less(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		return makeValue<bool>(lOperand->get<int64_t>() < rOperand->get<int64_t>());
	}
	else if (rOperand->type == L"float") {
		return makeValue<bool>(lOperand->get<int64_t>() < rOperand->get<double>());
	}
	else if (rOperand->type == L"bool") {
		return makeValue<bool>(lOperand->get<int64_t>() < rOperand->get<bool>());
	}
	else if (rOperand->type == L"string") {
		auto rvalue = cast<double, std::wstring>(rOperand->get<std::wstring>());
		return makeValue<bool>(lOperand->get<int64_t>() < rvalue);
	}
		
	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> Integer::GreaterEqual(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		return makeValue<bool>(lOperand->get<int64_t>() >= rOperand->get<int64_t>());
	}
	else if (rOperand->type == L"float") {
		return makeValue<bool>(lOperand->get<int64_t>() >= rOperand->get<double>());
	}
	else if (rOperand->type == L"bool") {
		return makeValue<bool>(lOperand->get<int64_t>() >= rOperand->get<bool>());
	}
	else if (rOperand->type == L"string") {
		auto rvalue = cast<double, std::wstring>(rOperand->get<std::wstring>());
		return makeValue<bool>(lOperand->get<int64_t>() >= rvalue);
	}
		
	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> Integer::LessEqual(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		return makeValue<bool>(lOperand->get<int64_t>() <= rOperand->get<int64_t>());
	}
	else if (rOperand->type == L"float") {
		return makeValue<bool>(lOperand->get<int64_t>() <= rOperand->get<double>());
	}
	else if (rOperand->type == L"bool") {
		return makeValue<bool>(lOperand->get<int64_t>() <= rOperand->get<bool>());
	}
	else if (rOperand->type == L"string") {
		auto rvalue = cast<double, std::wstring>(rOperand->get<std::wstring>());
		return makeValue<bool>(lOperand->get<int64_t>() <= rvalue);
	}
		
	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> Integer::LogicalAnd(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		return makeValue<bool>(lOperand->get<int64_t>() && rOperand->get<int64_t>());
	}
	else if (rOperand->type == L"float") {
		return makeValue<bool>(lOperand->get<int64_t>() && rOperand->get<double>());
	}
	else if (rOperand->type == L"bool") {
		return makeValue<bool>(lOperand->get<int64_t>() && rOperand->get<bool>());
	}
	else if (rOperand->type == L"string") {
		auto rvalue = cast<double, std::wstring>(rOperand->get<std::wstring>());
		return makeValue<bool>(lOperand->get<int64_t>() && rvalue);
	}
		
	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> Integer::LogicalOr(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		return makeValue<bool>(lOperand->get<int64_t>() || rOperand->get<int64_t>());
	}
	else if (rOperand->type == L"float") {
		return makeValue<bool>(lOperand->get<int64_t>() || rOperand->get<double>());
	}
	else if (rOperand->type == L"bool") {
		return makeValue<bool>(lOperand->get<int64_t>() || rOperand->get<bool>());
	}
	else if (rOperand->type == L"string") {
		auto rvalue = cast<double, std::wstring>(rOperand->get<std::wstring>());
		return makeValue<bool>(lOperand->get<int64_t>() || rvalue);
	}
		
	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> Integer::BitwiseAnd(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		return makeValue<int64_t>(lOperand->get<int64_t>() & rOperand->get<int64_t>());
	}
	else if (rOperand->type == L"float") {
		throw std::runtime_error("Cannot apply bitwise and operation between type int and type float");
	}
	else if (rOperand->type == L"bool") {
		throw std::runtime_error("Cannot apply bitwise and operation between type int and type bool");
	}
	else if (rOperand->type == L"string") {
		auto rvalue = cast<double, std::wstring>(rOperand->get<std::wstring>());
		if (std::ceil(rvalue) == rvalue) {
			// value is integer
			return makeValue<int64_t>(lOperand->get<int64_t>() & static_cast<int64_t>(rvalue));
		}
		// value is float
		throw std::runtime_error("Cannot apply bitwise and operation between type int and type float");
	}
	
	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> Integer::BitwiseOr(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		return makeValue<int64_t>(lOperand->get<int64_t>() | rOperand->get<int64_t>());
	}
	else if (rOperand->type == L"float") {
		throw std::runtime_error("Cannot apply bitwise or operation between type int and type float");
	}
	else if (rOperand->type == L"bool") {
		throw std::runtime_error("Cannot apply bitwise or operation between type int and type bool");
	}
	else if (rOperand->type == L"string") {
		auto rvalue = cast<double, std::wstring>(rOperand->get<std::wstring>());
		if (std::ceil(rvalue) == rvalue) {
			// value is integer
			return makeValue<int64_t>(lOperand->get<int64_t>() | static_cast<int64_t>(rvalue));
		}
		// value is float
		throw std::runtime_error("Cannot apply bitwise or operation between type int and type float");
	}

	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> Integer::BitwiseXor(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		return makeValue<int64_t>(lOperand->get<int64_t>() ^ rOperand->get<int64_t>());
	}
	else if (rOperand->type == L"float") {
		throw std::runtime_error("Cannot apply bitwise xor operation between type int and type float");
	}
	else if (rOperand->type == L"bool") {
		throw std::runtime_error("Cannot apply bitwise xor operation between type int and type bool");
	}
	else if (rOperand->type == L"string") {
		auto rvalue = cast<double, std::wstring>(rOperand->get<std::wstring>());
		if (std::ceil(rvalue) == rvalue) {
			// value is integer
			return makeValue<int64_t>(lOperand->get<int64_t>() ^ static_cast<int64_t>(rvalue));
		}
		// value is float
		throw std::runtime_error("Cannot apply bitwise xor operation between type int and type float");
	}
		
	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> Integer::LeftShift(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		return makeValue<int64_t>(lOperand->get<int64_t>() << rOperand->get<int64_t>());
	}
	else if (rOperand->type == L"float") {
		throw std::runtime_error("Cannot apply leftshift operation between type int and type float");
	}
	else if (rOperand->type == L"bool") {
		throw std::runtime_error("Cannot apply leftshift operation between type int and type bool");
	}
	else if (rOperand->type == L"string") {
		auto rvalue = cast<double, std::wstring>(rOperand->get<std::wstring>());
		if (std::ceil(rvalue) == rvalue) {
			// value is integer
			return makeValue<int64_t>(lOperand->get<int64_t>() << static_cast<int64_t>(rvalue));
		}
		// value is float
		throw std::runtime_error("Cannot apply leftshift operation between type int and type float");
	}
		
	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> Integer::RightShift(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		return makeValue<int64_t>(lOperand->get<int64_t>() >> rOperand->get<int64_t>());
	}
	else if (rOperand->type == L"float") {
		throw std::runtime_error("Cannot apply rightshfit operation between type int and type float");
	}
	else if (rOperand->type == L"bool") {
		throw std::runtime_error("Cannot apply rightshift operation between type int and type bool");
	}
	else if (rOperand->type == L"string") {
		auto rvalue = cast<double, std::wstring>(rOperand->get<std::wstring>());
		if (std::ceil(rvalue) == rvalue) {
			// value is integer
			return makeValue<int64_t>(lOperand->get<int64_t>() >> static_cast<int64_t>(rvalue));
		}
		// value is float
		throw std::runtime_error("Cannot apply rightshift operation between type int and type float");
	}
		
	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> Integer::LeftShiftAssignment(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		return changeValue<int64_t>(lOperand, lOperand->get<int64_t>() << rOperand->get<int64_t>());
	}
	else if (rOperand->type == L"float") {
		throw std::runtime_error("Cannot apply leftshift operation between type int and type float");
	}
	else if (rOperand->type == L"bool") {
		throw std::runtime_error("Cannot apply leftshift operation between type int and type bool");
	}
	else if (rOperand->type == L"string") {
		auto rvalue = cast<double, std::wstring>(rOperand->get<std::wstring>());
		if (std::ceil(rvalue) == rvalue) {
			// value is integer
			return changeValue<int64_t>(lOperand, lOperand->get<int64_t>() << static_cast<int64_t>(rvalue));
		}
			
		// value is float
		throw std::runtime_error("Cannot apply bitwise xor operation between type int and type float");
	}
		
	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> Integer::RightShiftAssignment(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		return changeValue<int64_t>(lOperand, lOperand->get<int64_t>() >> rOperand->get<int64_t>());
	}
	else if (rOperand->type == L"float") {
		throw std::runtime_error("Cannot apply rightshift operation between type int and type float");
	}
	else if (rOperand->type == L"bool") {
		throw std::runtime_error("Cannot apply rightshift operation between type int and type bool");
	}
	else if (rOperand->type == L"string") {
		auto rvalue = cast<double, std::wstring>(rOperand->get<std::wstring>());
		if (std::ceil(rvalue) == rvalue) {
			// value is integer
			return changeValue<int64_t>(lOperand, lOperand->get<int64_t>() >> static_cast<int64_t>(rvalue));
		}
		// value is float
		throw std::runtime_error("Cannot apply bitwise xor operation between type int and type float");
	}
		
	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> Integer::Assignment(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		return changeValue<int64_t>(lOperand, rOperand->get<int64_t>());
	}
	else if (rOperand->type == L"float") {
		return changeValue<int64_t>(lOperand, rOperand->get<double>());
	}
	else if (rOperand->type == L"bool") {
		return changeValue<int64_t>(lOperand, rOperand->get<bool>());
	}
	else if (rOperand->type == L"string") {
		auto rvalue = cast<double, std::wstring>(rOperand->get<std::wstring>());
		return changeValue<int64_t>(lOperand, rvalue);
	}

	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> Integer::AdditionAssignment(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		return changeValue<int64_t>(lOperand, lOperand->get<int64_t>() + rOperand->get<int64_t>());
	}
	else if (rOperand->type == L"float") {
		return changeValue<int64_t>(lOperand, lOperand->get<int64_t>() + rOperand->get<double>());
	}
	else if (rOperand->type == L"bool") {
		return changeValue<int64_t>(lOperand, lOperand->get<int64_t>() + rOperand->get<bool>());
	}
	else if (rOperand->type == L"string") {
		auto rvalue = cast<double, std::wstring>(rOperand->get<std::wstring>());
		return changeValue<int64_t>(lOperand, lOperand->get<int64_t>() + rvalue);
	}

	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> Integer::SubtractionAssignment(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		return changeValue<int64_t>(lOperand, lOperand->get<int64_t>() - rOperand->get<int64_t>());
	}
	else if (rOperand->type == L"float") {
		return changeValue<int64_t>(lOperand, lOperand->get<int64_t>() - rOperand->get<double>());
	}
	else if (rOperand->type == L"bool") {
		return changeValue<int64_t>(lOperand, lOperand->get<int64_t>() - rOperand->get<bool>());
	}
	else if (rOperand->type == L"string") {
		auto rvalue = cast<double, std::wstring>(rOperand->get<std::wstring>());
		return changeValue<int64_t>(lOperand, lOperand->get<int64_t>() - rvalue);
	}

	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> Integer::MultiplicationAssignment(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		return changeValue<int64_t>(lOperand, lOperand->get<int64_t>() * rOperand->get<int64_t>());
	}
	else if (rOperand->type == L"float") {
		return changeValue<int64_t>(lOperand, lOperand->get<int64_t>() * rOperand->get<double>());
	}
	else if (rOperand->type == L"bool") {
		return changeValue<int64_t>(lOperand, lOperand->get<int64_t>() * rOperand->get<bool>());
	}
	else if (rOperand->type == L"string") {
		auto rvalue = cast<double, std::wstring>(rOperand->get<std::wstring>());
		return changeValue<int64_t>(lOperand, lOperand->get<int64_t>() * rvalue);
	}

	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> Integer::DivisionAssignment(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		auto rvalue = rOperand->get<int64_t>();
		if (rvalue == 0) {
			return changeValue<int64_t>(lOperand, 0);
		}
		return changeValue<int64_t>(lOperand, lOperand->get<int64_t>() / rvalue);
	}
	else if (rOperand->type == L"float") {
		auto rvalue = rOperand->get<double>();
		if (rvalue == 0) {
			return changeValue<int64_t>(lOperand, 0);
		}
		return changeValue<int64_t>(lOperand, lOperand->get<int64_t>() / rvalue);
	}
	else if (rOperand->type == L"bool") {
		auto rvalue = rOperand->get<bool>();
		if (rvalue == 0) {
			return changeValue<int64_t>(lOperand, 0);
		}
		return changeValue<int64_t>(lOperand, lOperand->get<int64_t>() / rvalue);
	}
	else if (rOperand->type == L"string") {
		auto rvalue = cast<double, std::wstring>(rOperand->get<std::wstring>());
		if (rvalue == 0) {
			return changeValue<int64_t>(lOperand, 0);
		}
		return changeValue<int64_t>(lOperand, lOperand->get<int64_t>() / rvalue);
	}

	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> Integer::ModulusAssignment(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		auto rvalue = rOperand->get<int64_t>();
		if (rvalue == 0) {
			return changeValue<int64_t>(lOperand, lOperand->get<int64_t>());
		}
		return changeValue<int64_t>(lOperand, lOperand->get<int64_t>() % rvalue);
	}
	else if (rOperand->type == L"float") {
		auto rvalue = rOperand->get<double>();
		if (rvalue == 0) {
			return changeValue<int64_t>(lOperand, lOperand->get<int64_t>());
		}
		return changeValue<int64_t>(lOperand, std::fmod(lOperand->get<int64_t>(), rvalue));
	}
	else if (rOperand->type == L"bool") {
		auto rvalue = rOperand->get<bool>();
		if (rvalue == 0) {
			return changeValue<int64_t>(lOperand, lOperand->get<int64_t>());
		}
		return changeValue<int64_t>(lOperand, std::fmod(lOperand->get<int64_t>(), rvalue));
	}
	else if (rOperand->type == L"string") {
		auto rvalue = cast<double, std::wstring>(rOperand->get<std::wstring>());
		if (rvalue == 0) {
			return changeValue<int64_t>(lOperand, lOperand->get<int64_t>());
		}
		return changeValue<int64_t>(lOperand, std::fmod(lOperand->get<int64_t>(), rvalue));
	}

	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> Integer::ExponentiationAssignment(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		auto rvalue = rOperand->get<int64_t>();
		if (rvalue == 0) {
			return changeValue<int64_t>(lOperand, lOperand->get<int64_t>());
		}
		return changeValue<int64_t>(lOperand, std::pow(lOperand->get<int64_t>(), rvalue));
	}
	else if (rOperand->type == L"float") {
		auto rvalue = rOperand->get<double>();
		if (rvalue == 0) {
			return changeValue<int64_t>(lOperand, lOperand->get<int64_t>());
		}
		return changeValue<int64_t>(lOperand, std::pow(lOperand->get<int64_t>(), rvalue));
	}
	else if (rOperand->type == L"bool") {
		auto rvalue = rOperand->get<bool>();
		if (rvalue == 0) {
			return changeValue<int64_t>(lOperand, lOperand->get<int64_t>());
		}
		return changeValue<int64_t>(lOperand, std::pow(lOperand->get<int64_t>(), rvalue));
	}
	else if (rOperand->type == L"string") {
		auto rvalue = cast<double, std::wstring>(rOperand->get<std::wstring>());
		if (rvalue == 0) {
			return changeValue<int64_t>(lOperand, lOperand->get<int64_t>());
		}
		return changeValue<int64_t>(lOperand, std::pow(lOperand->get<int64_t>(), rvalue));
	}

	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> Integer::BitwiseAndAssignment(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		auto rvalue = rOperand->get<int64_t>();
		return changeValue<int64_t>(lOperand, lOperand->get<int64_t>() & rvalue);
	}
	else if (rOperand->type == L"float") {
		throw std::runtime_error("Cannot apply bitwise and operation between type int and type float");
	}
	else if (rOperand->type == L"bool") {
		throw std::runtime_error("Cannot apply bitwise and operation between type int and type bool");
	}
	else if (rOperand->type == L"string") {
		auto rvalue = cast<double, std::wstring>(rOperand->get<std::wstring>());
		if (std::ceil(rvalue) == rvalue) {
			// value is integer
			return changeValue<int64_t>(lOperand, lOperand->get<int64_t>() & static_cast<int64_t>(rvalue));
		}
		throw std::runtime_error("Cannot apply bitwise and operation between type int and type float");
	}

	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> Integer::BitwiseOrAssignment(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		auto rvalue = rOperand->get<int64_t>();
		return changeValue<int64_t>(lOperand, lOperand->get<int64_t>() | rvalue);
	}
	else if (rOperand->type == L"float") {
		throw std::runtime_error("Cannot apply bitwise or operation between type int and type float");
	}
	else if (rOperand->type == L"bool") {
		throw std::runtime_error("Cannot apply bitwise or operation between type int and type bool");
	}
	else if (rOperand->type == L"string") {
		auto rvalue = cast<double, std::wstring>(rOperand->get<std::wstring>());
		if (std::ceil(rvalue) == rvalue) {
			// value is integer
			return changeValue<int64_t>(lOperand, lOperand->get<int64_t>() | static_cast<int64_t>(rvalue));
		}
		throw std::runtime_error("Cannot apply bitwise or operation between type int and type float");
	}

	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> Integer::BitwiseXorAssignment(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		auto rvalue = rOperand->get<int64_t>();
		return changeValue<int64_t>(lOperand, lOperand->get<int64_t>() ^ rvalue);
	}
	else if (rOperand->type == L"float") {
		throw std::runtime_error("Cannot apply bitwise xor operation between type int and type float");
	}
	else if (rOperand->type == L"bool") {
		throw std::runtime_error("Cannot apply bitwise xor operation between type int and type bool");
	}
	else if (rOperand->type == L"string") {
		auto rvalue = cast<double, std::wstring>(rOperand->get<std::wstring>());
		if (std::ceil(rvalue) == rvalue) {
			// value is integer
			return changeValue<int64_t>(lOperand, lOperand->get<int64_t>() ^ static_cast<int64_t>(rvalue));
		}
		throw std::runtime_error("Cannot apply bitwise xor operation between type int and type float");
	}

	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> Integer::LogicalAndAssignment(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		auto rvalue = rOperand->get<int64_t>();
		return changeValue<int64_t>(lOperand, lOperand->get<int64_t>() && rvalue);
	}
	else if (rOperand->type == L"float") {
		auto rvalue = rOperand->get<double>();
		return changeValue<int64_t>(lOperand, lOperand->get<int64_t>() && rvalue);
	}
	else if (rOperand->type == L"bool") {
		auto rvalue = rOperand->get<int64_t>();
		return changeValue<int64_t>(lOperand, lOperand->get<int64_t>() && rvalue);
	}
	else if (rOperand->type == L"string") {
		auto rvalue = cast<double, std::wstring>(rOperand->get<std::wstring>());
		return changeValue<int64_t>(lOperand, lOperand->get<int64_t>() && rvalue);
	}

	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> Integer::LogicalOrAssignment(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand) {
	if (rOperand->type == L"int") {
		auto rvalue = rOperand->get<int64_t>();
		return changeValue<int64_t>(lOperand, lOperand->get<int64_t>() || rvalue);
	}
	else if (rOperand->type == L"float") {
		auto rvalue = rOperand->get<double>();
		return changeValue<int64_t>(lOperand, lOperand->get<int64_t>() || rvalue);
	}
	else if (rOperand->type == L"bool") {
		auto rvalue = rOperand->get<int64_t>();
		return changeValue<int64_t>(lOperand, lOperand->get<int64_t>() || rvalue);
	}
	else if (rOperand->type == L"string") {
		auto rvalue = cast<double, std::wstring>(rOperand->get<std::wstring>());
		return changeValue<int64_t>(lOperand, lOperand->get<int64_t>() || rvalue);
	}

	throw std::runtime_error("Invalid type");
}

std::shared_ptr<Value> Integer::UnaryNegation(std::shared_ptr<Value> lOperand) {
	return makeValue<int64_t>(-lOperand->get<int64_t>());
}

std::shared_ptr<Value> Integer::UnaryPlus(std::shared_ptr<Value> lOperand) {
	return makeValue<int64_t>(std::llabs(lOperand->get<int64_t>()));
}

std::shared_ptr<Value> Integer::UnaryAbs(std::shared_ptr<Value> lOperand) {
	return makeValue<int64_t>(std::llabs(lOperand->get<int64_t>()));
}

std::shared_ptr<Value> Integer::LogicalNot(std::shared_ptr<Value> lOperand) {
	return makeValue<bool>(!lOperand->get<int64_t>());
}

std::shared_ptr<Value> Integer::BitwiseNot(std::shared_ptr<Value> lOperand) {
	return makeValue<bool>(~lOperand->get<int64_t>());
}

std::shared_ptr<Value> Integer::FrontIncrement(std::shared_ptr<Value> lOperand) {
	changeValue<int64_t>(lOperand, lOperand->get<int64_t>()+1);
	return makeValue<int64_t>(lOperand->get<int64_t>());
}

std::shared_ptr<Value> Integer::FrontDecrement(std::shared_ptr<Value> lOperand) {
	changeValue<int64_t>(lOperand, lOperand->get<int64_t>() - 1);
	return makeValue<int64_t>(lOperand->get<int64_t>());
}

std::shared_ptr<Value> Integer::EndIncrement(std::shared_ptr<Value> lOperand) {
	changeValue<int64_t>(lOperand, lOperand->get<int64_t>() + 1);
	return makeValue<int64_t>(lOperand->get<int64_t>() - 1);
}

std::shared_ptr<Value> Integer::EndDecrement(std::shared_ptr<Value> lOperand) {
	changeValue<int64_t>(lOperand, lOperand->get<int64_t>() - 1);
	return makeValue<int64_t>(lOperand->get<int64_t>() + 1);
}
