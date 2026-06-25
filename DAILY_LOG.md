# Daily Log

## 2026-06-25 — Day 01

### Completed

- Created the minimal C++20 CMake project skeleton.
- Added `src/main.cpp` with a small executable readiness message.
- Added one CTest smoke test for the executable output.
- Added a scheduled GitHub Actions workflow for the Daily C++ Survival Lab check.
- Updated project roadmap and status documents.

### Build Command

```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build
```

### Run Command

```bash
./build/survival_lab
```

### Test Command

```bash
ctest --test-dir build --output-on-failure
```

### Draft PR

Yes. A pull request should be opened as a draft after committing this change.

### Three C++ Points To Understand Today

1. `#include <iostream>` gives access to standard input/output streams such as `std::cout`.
2. `int main()` is the program entry point and returns an integer exit status to the operating system.
3. `std::cout << "..."` writes text to standard output; `\n` ends the line.

### Suggested Next Step

Day 02: add one tiny pure function and test it while keeping the project minimal.
