#include "llvm/Transforms/Utils/TestPass.h"

#include <iostream>

using namespace llvm;

PreservedAnalyses TestPass::run(Function &F,
                                      FunctionAnalysisManager &AM) {

    for(auto& BB : F){
        for(auto& I : BB){
            if(I.isDebugOrPseudoInst()){
                errs() << I << '\n';
            }
        }
    }
    
    return PreservedAnalyses::all();
}