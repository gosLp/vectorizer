#!/usr/bin/env bash

# 1) Which LLVM components you need depends on your pass logic.
#    Common ones: core, support, irreader, passes, analysis, etc.
#    Adjust as needed.
LLVM_COMPS="core support irreader analysis passes"
CXXFLAGS=$(llvm-config --cxxflags)
LDFLAGS=$(llvm-config --ldflags)
LIBS=$(llvm-config --libs $LLVM_COMPS)

clang++ \
  -I./include \
  -fPIC \
  -shared \
  $CXXFLAGS \
  $LDFLAGS \
  $LIBS \
  src/MyVectorizer.cpp \
  src/PassPlugin.cpp \
  -o MyVectorizerPass.so


echo "Built MyVectorizerPass.so"