# 03. 错误处理、异常安全与资源回滚

## 老教授板书

成熟的 C++ 程序不假装错误不会发生。文件可能打不开，输入可能非法，内存可能分配失败。关键不是“永远不出错”，而是出错时对象仍保持可析构、可理解、可恢复的状态。

## 1. 区分程序员错误与运行时错误

- 程序员错误：违反前置条件，例如数组下标越界。通常用断言、测试和代码审查发现。
- 运行时错误：外部环境导致，例如文件不存在、网络失败、用户输入非法。需要返回错误或抛异常。

```cpp
#include <stdexcept>
#include <string>

int parse_positive_int(const std::string& text) {
    int value = std::stoi(text);
    if (value <= 0) {
        throw std::invalid_argument("value must be positive");
    }
    return value;
}
```

## 2. 异常安全的三档目标

1. 基本保证：异常后对象仍有效，可析构，但状态可能改变。
2. 强保证：异常后对象回到调用前状态。
3. 不抛保证：函数承诺不抛异常，常用于析构函数和移动操作。

强保证常用技巧是“先准备，再提交”。

```cpp
#include <vector>

class ScoreBoard {
public:
    void replace_scores(std::vector<int> scores) {
        scores_ = std::move(scores);
    }

private:
    std::vector<int> scores_;
};
```

调用者先在外部构造好 `scores`，函数内部只提交新状态。若构造新向量失败，旧对象不受影响。

## 3. 不要在析构函数里抛异常

析构函数常在异常传播期间运行。如果析构函数再抛异常，程序可能直接终止。析构函数应该尽量 `noexcept`，并把可能失败的操作提前到普通成员函数里显式处理。

```cpp
class Transaction {
public:
    void commit() {
        committed_ = true;
    }

    ~Transaction() noexcept {
        if (!committed_) {
            rollback_noexcept();
        }
    }

private:
    void rollback_noexcept() noexcept {
        // best-effort rollback
    }

    bool committed_ = false;
};
```

## 4. 选择错误表达方式

- 调用方必须处理、且错误是常见分支：可用 `std::optional`、错误码或自定义结果类型。
- 错误跨越多层调用，且不是普通业务分支：异常通常更清晰。
- 析构、移动构造、清理函数：避免抛异常。

## 课堂练习

1. 写一个 `load_score` 函数，文件打不开时抛出 `std::runtime_error`。
2. 写一个 `try_find_level` 函数，找不到时返回 `std::optional<int>`。
3. 设计一个 `ScopedTimer`，析构函数只记录耗时，不抛异常。

## 老教授检查清单

- 错误路径是否被测试过？
- 抛异常后对象是否还能安全析构？
- 析构函数里是否调用了可能抛异常的代码？
