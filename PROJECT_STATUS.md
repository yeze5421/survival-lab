# Project Status

## Current State

The project is now a small C++20 survival training lab with a stable minimal structure:

- `CMakeLists.txt` defines the `survival_lab` executable, the `survival_day02` library, and CTest targets.
- `src/main.cpp` keeps the Day 01 readiness output and runs the Day 02 pointer demonstrations.
- `include/survival/day02/PointerExamples.hpp` declares the Day 02 pointer teaching examples.
- `src/day02/PointerExamples.cpp` implements runnable pointer examples with detailed Chinese comments.
- `tests/day02_pointer_test.cpp` verifies the pure helper functions used by the pointer examples.
- `.github/workflows/daily-cpp-survival-lab.yml` runs a scheduled GitHub Actions build/test check.
- `tutorials/cpp-old-professor/` remains as optional reference notes, but the daily workflow should prioritize code-first labs.

## Completed

- Day 01: Minimal C++20 CMake project skeleton.
- Day 02: Code-first C++ Pointer Survival Lab.
- Project cleanup: root README is now stable and the roadmap now matches the actual Day 02 work.

## Current Priority

Next task should be Day 03:

> Build a code-first RAII and object lifetime lab with constructors, destructors, non-copyable resource guards, and tests.

Do not add another large Markdown tutorial. Use runnable code and comments.

## Project Hygiene Rules

1. Do not rewrite the project.
2. Do not delete existing files unless explicitly requested.
3. Do not modify root `README.md` for every daily task.
4. If a daily task needs documentation, create it only inside that task's new folder.
5. Prefer code plus Chinese comments over separate long notes.
6. Always update `DAILY_LOG.md` and this file after daily changes.
7. Keep CMake, the executable, and CTest working.

## Last Verified Commands

```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build
./build/survival_lab
ctest --test-dir build --output-on-failure
```

## Known Notes

The scheduled file under `.github/workflows/` is a GitHub Actions workflow. It checks whether the project still builds and tests on schedule. It is not the same thing as a Codex App automation card.
