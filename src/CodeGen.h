
#include "Node.h"

namespace Complier {
    class CodeGen : public Vistor {
        public:
        int StackLevel = 0;
        CodeGen(){}
        void VistorProgramNode(ProgramNode *node);
        void VistorBinaryNode(BinaryNode *node);
        void VistorConstantNode(ConstantNode *node);
        void Push();
        void Pop(const char *reg);
    };
}