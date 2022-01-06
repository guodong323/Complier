
#include "Lexer.h"
#include "Node.h"
namespace Complier {
    class Parser {
        private:
            Lexer &Lex;
        public:
        Parser(Lexer &lex):Lex(lex){}
        std::shared_ptr<ProgramNode> Parse();

        private:
        std::shared_ptr<Node> parseExpr();
        std::shared_ptr<Node> parseAddExpr();
        std::shared_ptr<Node> parseMulExpr();
        std::shared_ptr<Node> parsePrimaryExpr();
    };
}