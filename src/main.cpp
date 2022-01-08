#include <iostream>
// #include "Lexer.h"
#include "Parser.h"
#include "PrintVistor.h"
#include "CodeGen.h"

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

int main(int argc,char *argv[])
{
    if (argc != 2) {
        printf("please input: ./complier code\n");
        return 0;
    }

    const char *source = argv[1];
    Lexer lex(source);
    lex.GetNextToken();

    Parser parser(lex);
    CodeGen codegen;
    // PrintVistor vistor;
    std::shared_ptr<ProgramNode> root = parser.Parse();
    // root->Accept(&vistor);
    root->Accept(&codegen);
    return 0;
}