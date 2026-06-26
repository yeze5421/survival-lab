# 02. 类型设计、接口边界与 `const`

## 老教授板书

C++ 的类型系统不是为了让编译器挑错而存在，它是为了让程序员把“不该发生的事”变得更难写出来。一个好接口应该告诉调用者：你可以做什么、不能做什么、谁拥有数据、谁只是观察数据。

## 1. 用类型表达含义

两个 `int` 可能含义完全不同。把领域概念包成类型，可以减少参数顺序错误。

```cpp
struct Health {
    int value = 100;
};

struct Damage {
    int value = 0;
};

Health apply_damage(Health health, Damage damage) {
    health.value -= damage.value;
    if (health.value < 0) {
        health.value = 0;
    }
    return health;
}
```

`apply_damage(Health{80}, Damage{25})` 比 `apply_damage(80, 25)` 更能说明意图。

## 2. `const` 是接口承诺

`const` 不只是“防止变量变”，它告诉读者这个函数不会修改传入对象。

```cpp
#include <string_view>
#include <vector>

struct Monster {
    std::string name;
    int danger = 0;
};

const Monster* find_monster(std::string_view name, const std::vector<Monster>& monsters) {
    for (const Monster& monster : monsters) {
        if (monster.name == name) {
            return &monster;
        }
    }
    return nullptr;
}
```

返回 `const Monster*` 表示调用者可以观察结果，但不能通过这个指针修改容器里的怪物。

## 3. 参数传递的基本判断

- 小而廉价的值，例如 `int`、`double`、小枚举：按值传递。
- 只读的大对象，例如 `std::vector<T>`、`std::string`：按 `const&` 或 `std::string_view` 传递。
- 函数要取得所有权：按值传入，然后 `std::move` 到成员。
- 可选返回结果：用 `std::optional<T>` 或指针，避免魔法值。

```cpp
#include <optional>

std::optional<Monster> strongest_monster(const std::vector<Monster>& monsters) {
    if (monsters.empty()) {
        return std::nullopt;
    }

    const Monster* best = &monsters.front();
    for (const Monster& monster : monsters) {
        if (monster.danger > best->danger) {
            best = &monster;
        }
    }
    return *best;
}
```

## 4. 让无效状态难以构造

如果生命值必须在 `0..100`，不要让所有代码都重复检查。把检查收进构造或工厂函数。

```cpp
#include <algorithm>

class HealthBar {
public:
    explicit HealthBar(int value) : value_(std::clamp(value, 0, 100)) {}

    int value() const {
        return value_;
    }

private:
    int value_;
};
```

## 课堂练习

1. 把 `int stamina` 包装成 `Stamina` 类型，并限制范围在 `0..200`。
2. 写一个 `find_item` 函数，只读查询背包，返回 `const std::string*`。
3. 把一个返回 `-1` 表示失败的函数改成返回 `std::optional<int>`。

## 老教授检查清单

- 参数列表里是否有多个同类型参数，容易调换顺序？
- 只读函数是否明确使用了 `const`？
- 是否用魔法值表达失败？能否改成 `std::optional`？
