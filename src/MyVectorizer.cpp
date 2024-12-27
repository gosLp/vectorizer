#include "MyVectorizer.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/Support/raw_ostream.h"

using namespace llvm;

PreservedAnalyses MyVectorizer::run(Function &F, FunctionAnalysisManager &FAM) {
    // very naive approach first
    // 1. look for simple loop: a for-like structure with a single latch block
    // 2. Attempt to unroll or vectorize it in a trival way eg. unroll by 2
    // 3. Print out transformations for debugging

    bool Changed = false;

    // we'll just print the function name for now
    errs() << "Running MyVectorizer on function: " << F.getName() << "\n";

    // TODO: implement the logic
    // * Scan basic blocks for a loop structure
    // * Possibly use LoopInfo analysis (if you prefer a loop pass, you'd do that differently)
    // * Insert your naive "vectorization" or unrolling transformation

    // auto &LI = FAM.getResult<LoopAnalysis>(F);
    // For demonstration, we won't do a real transformation yet
    // but let's pretend we did something:
    // ...
    // Changed = true; // if we did something

    // If we changed the IR, we return PreservedAnalyses::none().
    // Otherwise, we return PreservedAnalyses::all().

    if (Changed) {
        return PreservedAnalyses::none();

    } else {
        PreservedAnalyses::all();
    }
}