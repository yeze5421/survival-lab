# survival-lab

A small daily C++ survival training project.

## Current Goal

Build the project one tiny C++20 increment at a time while keeping it buildable, runnable, and testable.


## C++ Tutorials

A set of intermediate beginner-friendly C++20 notes is available in [`tutorials/cpp-old-professor`](tutorials/cpp-old-professor/README.md). The notes focus on value semantics, RAII, const-correct interfaces, error handling, STL algorithms, and small practice labs.

## Build

```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build
```

## Run

```bash
./build/survival_lab
```

## Test

```bash
ctest --test-dir build --output-on-failure
```

## Daily Automation

The `Daily C++ Survival Lab` GitHub Actions workflow is scheduled for 21:00 UTC every day. It reads the project planning files, configures CMake, builds the executable, runs it, and executes CTest.
