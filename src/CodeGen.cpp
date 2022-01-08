
#include "CodeGen.h"
#include <stdio.h>
#include <assert.h>
using namespace Complier;

void CodeGen::VistorProgramNode(ProgramNode *node) {
    printf("\t.text\n");
    printf("\t.globl prog\n");
    printf("_prog:\n");

    // 开始
    printf("\tpush %%rbp\n");
    printf("\tmov %%rsp, %%rbp\n");
    printf("\tsub $32, %%rsp\n");
    
    node->Lhs->Accept(this);
    assert(StackLevel == 0);

    // 结束
    printf("\tmov %%rbp, %%rsp\n");
    printf("\tpop %%rbp\n");
    printf("\tret\n");
}

void CodeGen::VistorConstantNode(ConstantNode *node) {
    printf("\tmov $%d, %%rax\n",node->Value);
}

void CodeGen::VistorBinaryNode(BinaryNode *node) {
    node->Rhs->Accept(this);
    Push();
    node->Lhs->Accept(this);
    Pop("%rdi");

    switch (node->op) {
        case ADD:
            printf("\tadd %%rdi, %%rax\n");
            break;
        case SUB:
            printf("\tsub %%rdi, %%rax\n");
            break;
        case MUL:
            printf("\timul %%rdi, %%rax\n");
            break;
        case DIV:
            printf("\tcqo\n");
            printf("\tidiv %%rdi\n");
            break;
        default:
            assert(0);
            break;
    }
}

void CodeGen::Push() {
    printf("\tpush %%rax\n");
    // StackLevel++;
}

void CodeGen::Pop(const char *reg) {
    printf("\tpop %s\n",reg);
    // StackLevel--;
}