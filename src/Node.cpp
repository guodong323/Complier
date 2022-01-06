#include "Node.h"

using namespace Complier;

void ProgramNode::Accept(Vistor *vistor) {
    vistor->VistorProgramNode(this);
}

void BinaryNode::Accept(Vistor *vistor) {
    vistor->VistorBinaryNode(this);
}

void ConstantNode::Accept(Vistor *vistor) {
    vistor->VistorConstantNode(this);
}