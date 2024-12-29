#include "MyVectorizer.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Analysis/LoopInfo.h"
#include "llvm/Analysis/LoopAnalysisManager.h"
#include "llvm/Analysis/LoopPass.h"
#include "MyVectorizer.h"

#include "llvm/Analysis/LoopAnalysisManager.h"
#include "llvm/Analysis/LoopInfo.h"
#include "llvm/IR/Dominators.h"
#include "llvm/Analysis/ScalarEvolution.h"
#include "llvm/Analysis/AssumptionCache.h"
#include "llvm/Analysis/TargetTransformInfo.h"
#include "llvm/Analysis/TargetLibraryInfo.h"
#include "llvm/IR/CFG.h"
#include "llvm/IR/PassManager.h"
#include "llvm/Passes/PassBuilder.h"
#include "llvm/Transforms/Utils/LoopUtils.h"
#include "llvm/Transforms/Utils/UnrollLoop.h"
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

    auto &LI = FAM.getResult<LoopAnalysis>(F);
    auto &Se = FAM.getResult<ScalarEvolutionAnalysis>(F); // Scalar evolution 
    auto &DT = FAM.getResult<DominatorTreeAnalysis>(F); // Domitar tree
    auto &AC = FAM.getResult<AssumptionAnalysis>(F); // assumption analysis
    auto &TLI = FAM.getResult<TargetLibraryAnalysis>(F); // Target library info
    auto &TTI = FAM.getResult<TargetIRAnalysis>(F); // Target transform info
    // For demonstration, we won't do a real transformation yet
    // but let's pretend we did something:

    // COllect loops in a vector first becasue unrolling can invalidate the loop list
    SmallVector<Loop*, 8> Loops(LI.begin(), LI.end());

    // iterate oer each loop
    for (Loop *L : Loops) {
        // Optional: Cehck if the loop has a single latch (very naive condition)
        BasicBlock *Latch = L->getLoopLatch();
        if (!Latch) {
            continue; // If we can't identiy a single latch, skip

        }


        // Print the loop blocks for debbugging
        errs() << " Found a loop in function : " << F.getName() << "\n";
    }
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