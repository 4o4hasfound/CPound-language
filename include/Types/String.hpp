#pragma once
#include <string>
#include <memory>
#include <sstream>

#include "Types.hpp"
#include "Value.hpp"
#include "Error.hpp"

#include "Utils/typeCasting.hpp"

class String {
public:
	static std::shared_ptr<Value> BinaryOperation(OperatorType operatorType, std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand);
	static std::shared_ptr<Value> UnaryOperation(OperatorType operatorType, std::shared_ptr<Value> lOperand);

	// Binary operation
	static std::shared_ptr<Value> Addition(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand);
	static std::shared_ptr<Value> Subtraction(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand);
	static std::shared_ptr<Value> Multiplication(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand);
	static std::shared_ptr<Value> Division(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand);
	static std::shared_ptr<Value> Modulus(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand);
	static std::shared_ptr<Value> Exponentiation(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand);
	static std::shared_ptr<Value> EqualTo(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand);
	static std::shared_ptr<Value> NotEqualTo(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand);
	static std::shared_ptr<Value> Greater(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand);
	static std::shared_ptr<Value> Less(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand);
	static std::shared_ptr<Value> GreaterEqual(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand);
	static std::shared_ptr<Value> LessEqual(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand);
	static std::shared_ptr<Value> LogicalAnd(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand);
	static std::shared_ptr<Value> LogicalOr(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand);
	static std::shared_ptr<Value> BitwiseAnd(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand);
	static std::shared_ptr<Value> BitwiseOr(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand);
	static std::shared_ptr<Value> BitwiseXor(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand);
	static std::shared_ptr<Value> LeftShift(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand);
	static std::shared_ptr<Value> RightShift(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand);
	static std::shared_ptr<Value> LeftShiftAssignment(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand);
	static std::shared_ptr<Value> RightShiftAssignment(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand);
	static std::shared_ptr<Value> Assignment(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand);
	static std::shared_ptr<Value> AdditionAssignment(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand);
	static std::shared_ptr<Value> SubtractionAssignment(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand);
	static std::shared_ptr<Value> MultiplicationAssignment(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand);
	static std::shared_ptr<Value> DivisionAssignment(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand);
	static std::shared_ptr<Value> ModulusAssignment(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand);
	static std::shared_ptr<Value> ExponentiationAssignment(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand);
	static std::shared_ptr<Value> BitwiseAndAssignment(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand);
	static std::shared_ptr<Value> BitwiseOrAssignment(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand);
	static std::shared_ptr<Value> BitwiseXorAssignment(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand);
	static std::shared_ptr<Value> LogicalAndAssignment(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand);
	static std::shared_ptr<Value> LogicalOrAssignment(std::shared_ptr<Value> lOperand, std::shared_ptr<Value> rOperand);

	// Unary operation
	static std::shared_ptr<Value> LogicalNot(std::shared_ptr<Value> lOperand);
	static std::shared_ptr<Value> BitwiseNot(std::shared_ptr<Value> lOperand);
	static std::shared_ptr<Value> UnaryNegation(std::shared_ptr<Value> lOperan);
	static std::shared_ptr<Value> UnaryPlus(std::shared_ptr<Value> lOperand);
	static std::shared_ptr<Value> UnaryAbs(std::shared_ptr<Value> lOperand);
	static std::shared_ptr<Value> FrontIncrement(std::shared_ptr<Value> lOperand);
	static std::shared_ptr<Value> EndIncrement(std::shared_ptr<Value> lOperand);
	static std::shared_ptr<Value> FrontDecrement(std::shared_ptr<Value> lOperand);
	static std::shared_ptr<Value> EndDecrement(std::shared_ptr<Value> lOperand);
	//static std::shared_ptr<Value> Previous(std::shared_ptr<Value> lOperand);
	//static std::shared_ptr<Value> Current(std::shared_ptr<Value> lOperand);
private:
	String() = delete;
};