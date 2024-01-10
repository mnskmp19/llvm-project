
#ifndef LLVM_TRANSFORMS_UTILS_TESTPASS_H
#define LLVM_TRANSFORMS_UTILS_TESTPASS_H

#include "llvm/IR/PassManager.h"

namespace llvm {

class PrintDebugPass : public PassInfoMixin<PrintDebugPass> {
public:
  PreservedAnalyses run(Function &F, FunctionAnalysisManager &AM);
};

class RemoveDebugPass : public PassInfoMixin<RemoveDebugPass> {
public:
  PreservedAnalyses run(Function &F, FunctionAnalysisManager &AM);
};

} // namespace llvm

#endif // LLVM_TRANSFORMS_UTILS_TESTPASS_H