#ifndef COMPLIER_LEXER_H
#define COMPLIER_LEXER_H

#include <string>
namespace Complier {
    enum TokenKind
    {
        Add,
        Sub,
        Mul,
        Div,
        Num,
        Eof
    };
    
    class Token {
        public:
            TokenKind Kind;
            int Value;
            std::string Content;
    };

    class Lexer
    {
    private:
        std::string SourceCode;
        char CurChar = ' ';  //当前字符
        int Cursor = 0;  //当前字符的下一个字符
    public:
        std::shared_ptr<Token> CurrentToken;
    public:
        Lexer(const char *code) {
            SourceCode = code;
        }
        void GetNextToken();
        void GetNextChar();
    };
}

#endif