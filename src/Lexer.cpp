#include "Lexer.h"
#include <cstring>
void Complier::Lexer::GetNextChar() {
    if (Cursor == SourceCode.size()) {
        CurChar = '\0';
        Cursor++;
    }
    else
    {
        CurChar = SourceCode[Cursor++];
    }
}

void Complier::Lexer::GetNextToken() {
    // 1.删除空格字符
    while (isspace(CurChar))
    {
        GetNextChar();
    }
    TokenKind kind;
    int value = 0;
    int startPos = Cursor - 1;
    if (CurChar == '\0')
    {
        kind = Eof;
    } else if (CurChar == '+') {
        kind = Add;
        GetNextChar();
    }
    else if (CurChar == '-')
    {
        kind = Sub;
        GetNextChar();
    }
    else if (CurChar == '*')
    {
        kind = Mul;
        GetNextChar();
    }
    else if (CurChar == '/')
    {
        kind = Div;
        GetNextChar();
    }
    else if (isdigit(CurChar))
    {
        kind = Num;
        value = 0;
        do {
            value = value * 10 + CurChar - '0';
            GetNextChar();
        } while (isdigit(CurChar));
    }
    else
    {
        printf("error: not support %c\n",CurChar);
    }
    CurrentToken = std::make_shared<Token>();
    CurrentToken->Kind = kind;
    CurrentToken->Value = value;
    // 字符截取
    CurrentToken->Content = SourceCode.substr(startPos, Cursor - 1 - startPos);
}