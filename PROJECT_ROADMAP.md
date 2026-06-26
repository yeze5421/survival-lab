# Project Roadmap

## Daily C++ Survival Lab

Goal: grow this project through one focused C++20 increment per day without rewriting the project.

## Rules

1. Do not rewrite the project.
2. Do not delete existing files.
3. Do not implement multiple unrelated features in one run.
4. Implement only the next smallest roadmap task.
5. Keep the project buildable, runnable, and testable.
6. Update `DAILY_LOG.md` and `PROJECT_STATUS.md` after each change.
7. Do not push directly to `main`.
8. If code must be submitted, use a draft pull request.
9. If the day is not suitable for code changes, record the reason and the suggested next step.

## Documentation Hygiene

1. Keep the root `README.md` stable.
2. Do not edit the root `README.md` for every daily task.
3. If a task needs its own documentation, create a `README.md` only inside that task's new folder.
4. Prefer code plus clear Chinese comments over long standalone notes.
5. `DAILY_LOG.md` and `PROJECT_STATUS.md` are the normal places for daily progress updates.

## Roadmap

- [x] Day 01: Establish a minimal C++20 project skeleton with CMake, `src/main.cpp`, and CTest.
- [x] Day 02: Build a code-first Pointer Survival Lab covering raw pointers, `nullptr`, references, `const` pointers, array decay, dangling pointer warnings, `unique_ptr`, `shared_ptr`, and `weak_ptr`.
- [ ] Day 03: Build a code-first RAII and object lifetime lab with constructors, destructors, non-copyable resource guards, and tests.
- [ ] Day 04: Build a small file I/O lab using `std::filesystem`, `std::ifstream`, `std::ofstream`, and safe error handling.
- [ ] Day 05: Introduce a simple command-line dispatcher such as `about`, `day02`, and `day03`.
- [ ] Day 06: Add a small logger with levels such as info, warning, and error.
- [ ] Day 07: Add a timing utility using `std::chrono` and test it through a small demo.
- [ ] Day 08: Add a container lab covering `std::vector`, `std::array`, `std::map`, and iterator invalidation.
- [ ] Day 09: Add a string parsing lab for simple key-value text.
- [ ] Day 10: Review and refactor project structure without changing behavior.

## Long-Term Direction

After the first 10 days, keep the same pattern:

```text
one topic -> runnable code -> small tests -> daily log -> status update
```

Avoid turning the repository into a notebook collection. The main learning artifact should be working C++ code.
