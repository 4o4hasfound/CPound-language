#pragma once
#include <string>
#include <memory>
#include <unordered_map>

#include "ASTNodes.hpp"
#include "Types.hpp"
#include "Tokens.hpp"
#include "Error.hpp"

class AST {
public:
	AST(const std::vector<std::unique_ptr<Token>>& tokens);

	void build(const std::wstring* string);
	void debug(ASTNode* node, int depth = 0) const;
	void debug(const VariableDeclarationInfo& declInfo, int depth) const;

	std::unique_ptr<ProgramNode> program;
private:

	int m_index, m_fallbackIndex;
	const std::vector<std::unique_ptr<Token>>& m_tokens;
	const std::wstring* m_string;

	Token* peek(int delta = 0) const;
	bool match(Token::TokenType type) const;
	template<typename T, typename = std::enable_if_t<std::is_enum_v<T>>>
	bool match(T value) const;
	void loadIndex();
	void fallback();
	Token* advance(int delta = 1);
	Token* previous() const;
	Token* consume(Token::TokenType type, const std::string& errorMessage);

	template<typename T, typename = std::enable_if_t<std::is_enum_v<T>>>
	Token* consume(T value, const std::string& errorMessage);

	bool isEnd() const;

	std::unique_ptr<ProgramNode>	parseProgram();
	std::unique_ptr<ASTNode>		parseBlock(bool checkForStatementType = 1);
	std::unique_ptr<ASTNode>		parseType();
	std::unique_ptr<StatementNode>	parseFunctionDeclaration();
	std::unique_ptr<StatementNode>	parseVariableDeclaration();
	std::unique_ptr<StatementNode>	parseEvaluationVariableDeclaration();
	std::unique_ptr<StatementNode>	parseClassDeclaration();
	std::unique_ptr<ASTNode>		parseUnary();
	std::unique_ptr<ASTNode>		parsePrimary();
	std::unique_ptr<ASTNode>		parseExpression(int precedence = 0);
	std::unique_ptr<ASTNode>		parseCallExpression();
	std::unique_ptr<ASTNode>		parseExpressionStatement();
	std::unique_ptr<StatementNode>	parseIfStatement();
	std::unique_ptr<StatementNode>	parseReverseStatement();
	std::unique_ptr<StatementNode>	parseReturnStatement();
	std::unique_ptr<StatementNode>	parsePrintStatement();
	std::unique_ptr<StatementNode>	parseInputStatement();
	std::unique_ptr<StatementNode>	parseKeyword();
	std::unique_ptr<StatementNode>	parseStatementType();
	bool skipTerminatorType();

	VariableDeclarationType parseDeclType();
	Token* parseIdentifier();
	LifetimeInfo parseLifeTime();

	VariableDeclarationType getVariableDeclarationType(Token* token) const;
	int getPrecendence(Token* token) const;
	bool isAssignmentOperator(Token* token) const;
	bool isUnaryOperator(Token* token) const;
	bool isUnaryKeyword(Token* token) const;
	bool isPrefixUnaryOperator(Token* token) const;
	bool isPostfixUnaryOperator(Token* token) const;

	bool tokenIsType(Token* token, Token::TokenType type) const;
	template<typename T, typename = std::enable_if_t<std::is_enum_v<T>>>
	bool tokenIsType(Token* token, T value) const;

	static const std::unordered_map<OperatorType, int> s_presedence;

};

template<typename T, typename>
inline bool AST::match(T value) const {
	return tokenIsType(peek(), value);
}

template<typename T, typename>
inline Token* AST::consume(T value, const std::string& errorMessage) {
	if (peek()->isType(value)) return advance();
	throw std::runtime_error(errorMessage);
}

template<typename T, typename>
inline bool AST::tokenIsType(Token* token, T value) const {
	return token && token->isType(value);
}
