#include "Parser.h"
using namespace Complier;

std::shared_ptr<ProgramNode> Parser::Parse() {
    std::shared_ptr<ProgramNode> node = std::make_shared<ProgramNode>();
    node->Lhs = parseExpr();
    return node;
}

std::shared_ptr<Node> Parser::parseExpr() {
    return parseAddExpr();

}

std::shared_ptr<Node> Parser::parseAddExpr() { 
    std::shared_ptr<Node> left = parseMulExpr();
    while (Lex.CurrentToken->Kind == Add || Lex.CurrentToken->Kind == Sub) {
        BinaryOperator anOperator = ADD;
        if (Lex.CurrentToken->Kind == Sub) {
            anOperator = SUB;
        }
        Lex.GetNextToken();
        std::shared_ptr<BinaryNode> node =  std::make_shared<BinaryNode>();
        node->op = anOperator;
        node->Lhs = left;
        node->Rhs = parseMulExpr();
        left = node;
    }
    return left;
}

std::shared_ptr<Node> Parser::parseMulExpr() {
    std::shared_ptr<Node> left = parsePrimaryExpr();
    while (Lex.CurrentToken->Kind == Mul || Lex.CurrentToken->Kind == Div) {
        BinaryOperator anOperator = MUL;
        if (Lex.CurrentToken->Kind == Div) {
            anOperator = DIV;
        }
        Lex.GetNextToken();
        std::shared_ptr<BinaryNode> node =  std::make_shared<BinaryNode>();
        node->op = anOperator;
        node->Lhs = left;
        node->Rhs = parsePrimaryExpr();
        left = node;
    }
    return left;
}

std::shared_ptr<Node> Parser::parsePrimaryExpr() {
    std::shared_ptr<ConstantNode> node = std::make_shared<ConstantNode>();
    node->Value = Lex.CurrentToken->Value;
    Lex.GetNextToken();
    return node;
}