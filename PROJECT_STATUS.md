# Project Status

## Current State

The project is now a small C++20 survival training lab with Day 01 and Day 02 in place:

- `CMakeLists.txt` defines the `survival_lab` executable, a `survival_day02` library, and CTest targets.
- `src/main.cpp` keeps the Day 01 readiness output and runs the Day 02 pointer demonstrations.
- `include/survival/day02/PointerExamples.hpp` declares the Day 02 pointer teaching examples.
- `src/day02/PointerExamples.cpp` implements runnable pointer examples with detailed Chinese comments.
- `tests/day02_pointer_test.cpp` verifies the pure helper functions used by the pointer examples.
- CTest keeps the original executable smoke test and adds `day02_pointer_test`.

## Current Priority

Day 02 is complete: C++ Pointer Survival Lab now covers addresses, `nullptr`, pointer-vs-reference behavior, const pointer forms, array decay, dangling pointer warnings, `std::unique_ptr`, `std::shared_ptr`, and `std::weak_ptr`.

## Last Verified Commands

```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build
./build/survival_lab
ctest --test-dir build --output-on-failure
```
