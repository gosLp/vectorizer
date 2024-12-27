cmake_minimum_required(VERSION 3.13)

project(MyVectorizer LANGUAGES CXX)

# Set C++17 or later if needed
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find the LLVM package. Adjust the path to where your LLVM is installed.
# For example, if you built LLVM from source, you might pass
# `-DLLVM_DIR=/path/to/llvm/lib/cmake/llvm` to cmake.
find_package(LLVM REQUIRED CONFIG)

message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")

# Set the include directories for LLVM
include_directories(${LLVM_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})

# If you’re using the new Pass Manager, you typically want to link with these.
# Some passes may also need specific LLVM component libraries.
llvm_map_components_to_libnames(REQ_LLVM_LIBS
  Core
  Support
  IRReader
  # Add more as needed...
)

# Create a library for your pass. 
# We'll produce a shared library that can be loaded via `opt -load-pass-plugin`.
add_library(MyVectorizerPass SHARED
  src/MyVectorizer.cpp
  passes/PassPlugin.cpp
)

target_include_directories(MyVectorizerPass PRIVATE include)
target_link_libraries(MyVectorizerPass PRIVATE ${REQ_LLVM_LIBS})

# Optional: you can also add an executable for testing or demonstration.
# e.g. a driver that uses LLVM APIs directly.