#ifndef COMPLIER_NODE_H
#define COMPLIER_NODE_H
#include <memory>

namespace Complier {
    class Vistor;

    class Node {
        public:
            virtual ~Node(){}
            virtual void Accept(Vistor *vistor) {};
    };

    class ProgramNode : public Node {
        public:
        std::shared_ptr<Node> Lhs;
        void Accept(Vistor *vistor);
    };

    enum BinaryOperator {
        ADD,
        SUB,
        MUL,
        DIV
    };

    class BinaryNode : public Node {
        public:
            BinaryOperator op;
            std::shared_ptr<Node> Lhs;
            std::shared_ptr<Node> Rhs;
            void Accept(Vistor *vistor);
    };

    class ConstantNode : public Node {
        public:
            int Value;
            void Accept(Vistor *vistor);
    };

    class Vistor {
        public:
            virtual void VistorProgramNode(ProgramNode *node) {};
            virtual void VistorBinaryNode(BinaryNode *node) {};
            virtual void VistorConstantNode(ConstantNode *node) {};
    };
}

#endif