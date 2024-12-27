#pragma once

#include "llvm/IR/PassManager.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/Module.h"

namespace llvm {
    class MyVectorizer : public PassInfoMixin<MyVectorizer> {
    public:
        PreservedAnalyses run(Function &F, FunctionAnalysisManager &FAM);
    };
}