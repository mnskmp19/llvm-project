#include "llvm/Transforms/Utils/TestPass.h"

#include <iostream>

using namespace llvm;

PreservedAnalyses PrintDebugPass::run(Function &F,
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

PreservedAnalyses RemoveDebugPass::run(Function &F,
                                      FunctionAnalysisManager &AM) {

    for(auto& BB : F){
        for(auto& I : make_early_inc_range(BB)){
            if(I.isDebugOrPseudoInst()){
                I.eraseFromParent();
            }
        }
    }
    
    return PreservedAnalyses::all();
}