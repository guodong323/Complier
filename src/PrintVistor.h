

#include "Node.h"

namespace Complier {
    class PrintVistor : public Vistor {
        public:
        void VistorProgramNode(ProgramNode *node);
        void VistorBinaryNode(BinaryNode *node);
        void VistorConstantNode(ConstantNode *node);
    };
}