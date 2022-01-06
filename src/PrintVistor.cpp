
#include "PrintVistor.h"
#include <stdio.h>
using namespace Complier;

void PrintVistor::VistorProgramNode(ProgramNode *node) {
    printf("Program: ");
    node->Lhs->Accept(this);
    printf("\n");
}

void PrintVistor::VistorBinaryNode(BinaryNode *node) {
    // 后序遍历
    node->Rhs->Accept(this);
    node->Lhs->Accept(this);
    switch(node->op) {
        case BinaryOperator::ADD:
            printf(" + ");
            break;
        case BinaryOperator::SUB:
            printf(" - ");
            break;
        case BinaryOperator::MUL:
            printf(" * ");
            break;
        case BinaryOperator::DIV:
            printf(" / ");
            break;
        default:
            assert(0);
            break;
    }
}

void PrintVistor::VistorConstantNode(ConstantNode *node) {
    printf(" %d ",node->Value);
}