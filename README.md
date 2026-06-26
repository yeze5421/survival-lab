# survival-lab

A small daily C++20 survival training project.

## Goal

Build the project one tiny C++20 increment at a time while keeping it:

- buildable
- runnable
- testable
- easy to review

This repository is not meant to become a random pile of demos. Each day should add one focused C++ survival skill.

## Current Structure

```text
survival-lab/
├── .github/workflows/              # GitHub Actions build/test checks
├── include/survival/               # Public headers for training examples
│   └── day02/                      # Day 02 pointer declarations
├── src/                            # Executable and implementation files
│   └── day02/                      # Day 02 pointer implementations
├── tests/                          # CTest smoke/unit tests
├── tutorials/cpp-old-professor/    # Optional reference notes; not the main daily workflow
├── DAILY_LOG.md                    # Daily training log
├── PROJECT_ROADMAP.md              # Long-term daily roadmap
├── PROJECT_STATUS.md               # Current project state
└── CMakeLists.txt                  # CMake build definition
```

## Current Lessons

- **Day 01:** Minimal C++20 project skeleton with CMake and CTest.
- **Day 02:** Pointer Survival Lab using runnable code and Chinese comments.

Day 02 code lives in:

- `include/survival/day02/PointerExamples.hpp`
- `src/day02/PointerExamples.cpp`
- `tests/day02_pointer_test.cpp`

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

## Daily Work Rules

1. Do not rewrite the project.
2. Do not delete existing files unless the task explicitly says so.
3. Do not implement multiple unrelated features in one day.
4. Prefer runnable C++ code with clear Chinese comments over long Markdown notes.
5. Keep the root `README.md` stable. For daily feature documentation, write comments in code or create a `README.md` only inside the newly created feature folder.
6. Always update `DAILY_LOG.md` and `PROJECT_STATUS.md` after a daily task.
7. Keep the project buildable, runnable, and testable.

More Codex-specific rules are in [`docs/CODEX_RULES.md`](docs/CODEX_RULES.md).

## Daily Automation

The `Daily C++ Survival Lab` GitHub Actions workflow is scheduled for **06:00 UTC**, which is **14:00 Beijing Time / Asia/Shanghai**.

It reads the project planning files, configures CMake, builds the executable, runs it, and executes CTest.
