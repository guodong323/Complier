#include <iostream>
#include "Lexer.h"

using namespace Complier;
int main()
{
    const char *code = "    5  +1 - 3*4  /2 ";
    Lexer lex(code);
    do
    {
        lex.GetNextToken();
        std::cout << lex.CurrentToken->Content << std::endl;
    } while (lex.CurrentToken->Kind != Eof);
    return 0;
}