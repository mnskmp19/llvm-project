#include "llvm/Transforms/Utils/ExpressionOptimizer.h"
#include "llvm/IR/PatternMatch.h"

#include <iostream>

using namespace llvm;
using namespace PatternMatch;

PreservedAnalyses ExpressionOptimizerPass::run(Function &F,
                                      FunctionAnalysisManager &AM) {

    errs() << "EXPR OPT\n";

    for(auto& BB : F){
        for(auto& I : BB){
            Value* add1, *add2, *add3, *add4, *add5, *add6;
            Value* sq1, *sq2;
            
            if(match(&I, 
                m_Add(
                    m_Add(
                        m_Mul(
                            m_Value(add1),
                            m_Value(add2)
                        ),
                        m_Mul(
                            m_Mul(
                                m_SpecificInt(2),
                                m_Value(add3)
                            ),
                            m_Value(add4)
                        )
                    ),
                    m_Mul(
                        m_Value(add5),
                        m_Value(add6)
                    )
                )
            )
            && match(add1, m_Load(m_Value(sq1)))
            && match(add2, m_Load(m_Specific(sq1)))
            && match(add3, m_Load(m_Specific(sq1)))
            && match(add4, m_Load(m_Value(sq2)))
            && match(add5, m_Load(m_Specific(sq2)))
            && match(add6, m_Load(m_Specific(sq2)))
            ){
                errs() << "Square" << '\n';
            }
        }
    }
    
    return PreservedAnalyses::all();
}