# 04. STL、迭代器与算法思维

## 老教授板书

STL 不是一堆容器名字，而是一种分离思想：容器负责存储，迭代器描述范围，算法表达操作。新手常写很长的循环，老教授会问：你是在“怎么做”，还是在表达“要什么”。

## 1. 先选容器，再写算法

常见默认选择是 `std::vector`，因为它内存连续、遍历快、语义简单。除非你明确需要稳定迭代器、频繁中间插入、键值查找，否则不要过早选择复杂容器。

```cpp
#include <string>
#include <vector>

struct Item {
    std::string name;
    int weight = 0;
};

using Inventory = std::vector<Item>;
```

## 2. 用算法表达意图

```cpp
#include <algorithm>

bool has_heavy_item(const Inventory& inventory, int limit) {
    return std::any_of(inventory.begin(), inventory.end(), [limit](const Item& item) {
        return item.weight > limit;
    });
}
```

`std::any_of` 比手写循环更直接表达“是否存在”。

## 3. 迭代器是一对边界

很多 STL 算法接收 `[begin, end)` 半开区间。`begin` 指向第一个元素，`end` 指向最后一个元素之后的位置。

```cpp
int total_weight(const Inventory& inventory) {
    int total = 0;
    for (auto it = inventory.begin(); it != inventory.end(); ++it) {
        total += it->weight;
    }
    return total;
}
```

实际项目中，范围 `for` 更常用；显式迭代器适合需要擦除、分段或与算法组合时。

## 4. 谨慎处理失效

向 `std::vector` 添加元素可能导致重新分配，从而让旧引用、指针、迭代器失效。

```cpp
void add_item(Inventory& inventory, Item item) {
    inventory.push_back(std::move(item));
}
```

如果调用前保存了 `Item* first = &inventory.front();`，调用 `add_item` 后 `first` 可能已经悬空。老教授会提醒：性能优化前，先尊重失效规则。

## 5. C++20 ranges 的适度使用

`std::ranges` 可以让算法直接接收范围，减少 `.begin()` / `.end()` 噪音。

```cpp
#include <ranges>

bool contains_item(const Inventory& inventory, std::string_view name) {
    return std::ranges::any_of(inventory, [name](const Item& item) {
        return item.name == name;
    });
}
```

## 课堂练习

1. 用 `std::ranges::count_if` 统计重量超过阈值的物品数量。
2. 用 `std::find_if` 查找第一个名字匹配的物品。
3. 解释为什么 `std::vector` 扩容后旧指针可能失效。

## 老教授检查清单

- 默认容器是否可以用 `std::vector`？
- 手写循环是否能被 `any_of`、`find_if`、`count_if` 或 `accumulate` 表达？
- 是否保存了可能被容器修改操作失效的引用或迭代器？
