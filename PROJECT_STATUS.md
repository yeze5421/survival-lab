# Project Status

## Current State

The project has a minimal C++20 CMake skeleton:

- `CMakeLists.txt` defines the `survival_lab` executable.
- `src/main.cpp` prints a small readiness message.
- CTest contains one smoke test that verifies the executable output.
- `.github/workflows/daily-cpp-survival-lab.yml` runs the daily build-and-test check at 21:00 UTC.

## Current Priority

Day 01 is complete. The next smallest roadmap task is Day 02: add one tiny pure function and test it.

## Last Verified Commands

```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build
./build/survival_lab
ctest --test-dir build --output-on-failure
```
