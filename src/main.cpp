#include <iostream>
// #include "Lexer.h"
#include "Parser.h"
#include "PrintVistor.h"

using namespace Complier;

const char *code = "5+1-3*4/2";

void testLexer() {
    Lexer lex(code);
    do
    {
        lex.GetNextToken();
        std::cout << lex.CurrentToken->Content << std::endl;
    } while (lex.CurrentToken->Kind != Eof);
}

int main()
{
    Lexer lex(code);
    lex.GetNextToken();

    Parser parser(lex);
    PrintVistor vistor;
    std::shared_ptr<ProgramNode> root = parser.Parse();
    root->Accept(&vistor);
    return 0;
}