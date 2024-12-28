#include "llvm/Passes/PassPlugin.h"
#include "llvm/Passes/PassBuilder.h"
#include "llvm/Passes/OptimizationLevel.h"
#include "MyVectorizer.h"

using namespace llvm;

extern "C" ::llvm::PassPluginLibraryInfo LLVM_ATTRIBUTE_WEAK llvmGetPassPluginInfo() {
    return {
        LLVM_PLUGIN_API_VERSION,
        "MyVectorizer",
        LLVM_VERSION_STRING, 
        [](PassBuilder &PB) {
            // Register your pass callback
            PB.registerPipelineParsingCallback(
                [&](StringRef Name, FunctionPassManager &FPM,
                    ArrayRef<PassBuilder::PipelineElement>) {
                        if (Name == "my-vectorizer") {
                            FPM.addPass(MyVectorizer());
                            return true;
                        }
                        return false;
                    }
            );
        }
    };
}