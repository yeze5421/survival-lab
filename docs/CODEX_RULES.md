# Codex Rules for survival-lab

These rules keep the repository clean while using Codex for daily C++ training.

## Core Rules

1. Do not rewrite the project.
2. Do not delete existing files unless the user explicitly asks.
3. Do not implement multiple unrelated features in one run.
4. Implement only the next unfinished task in `PROJECT_ROADMAP.md`.
5. Keep the project buildable, runnable, and testable.
6. Always update `DAILY_LOG.md` and `PROJECT_STATUS.md` after a daily task.
7. Do not push directly to `main`; use a draft pull request when code changes are needed.

## README Rules

1. Do not modify the root `README.md` for routine daily tasks.
2. If a task needs documentation, write it in code comments first.
3. If a separate README is necessary, create it only inside the new folder created for that task.
4. Do not add daily notes to the root `README.md`.

## Code-First Learning Rule

Prefer this pattern:

```text
small topic -> runnable C++ code -> clear Chinese comments -> small CTest -> log/status update
```

Avoid this pattern:

```text
large Markdown note -> no runnable code -> no test
```

## Daily Task Shape

Each daily task should normally produce:

- one small code increment
- one small test increment
- updated `DAILY_LOG.md`
- updated `PROJECT_STATUS.md`
- no unrelated formatting changes
