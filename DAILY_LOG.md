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

## 2026-06-26 — Day 02

### 今日主题

C++ Pointer Survival Lab：用可编译、可运行、可测试的代码学习 C++ 指针基础。

### 新增文件

- `include/survival/day02/PointerExamples.hpp`
- `src/day02/PointerExamples.cpp`
- `tests/day02_pointer_test.cpp`

### 修改文件

- `CMakeLists.txt`
- `src/main.cpp`
- `README.md`
- `PROJECT_STATUS.md`
- `DAILY_LOG.md`

### 编译命令

```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build
```

### 运行命令

```bash
./build/survival_lab
```

### 测试命令

```bash
ctest --test-dir build --output-on-failure
```

### 今日必须理解的 5 个 C++ 指针点

1. `&x` 取得对象地址，`int* p = &x` 保存地址，`*p` 解引用访问对象。
2. 指针可以是 `nullptr`，解引用前必须检查，否则可能触发未定义行为。
3. 指针可以表达“可能没有对象”，引用通常必须绑定到一个有效对象。
4. `const int*`、`int* const`、`const int* const` 分别限制“值”“指针本身”或二者。
5. 指针不等于所有权；避免悬空指针，拥有资源时优先使用 RAII 和智能指针。

### Draft PR

Yes. A pull request should be opened as a draft after committing this change.
