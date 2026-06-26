# 05. 现代 C++20 工程小练习

## 老教授板书

教程不能停在阅读。C++ 的理解来自反复把小程序构建、运行、测试、重构。这个项目已经使用 CMake 和 C++20，可以把下面练习逐步移入 `src/`，每次只做一个小增量。

## 练习一：生命值模型

目标：实现一个不允许无效状态的 `Health` 类型。

要求：

- 构造时把值限制在 `0..100`。
- 提供 `value() const` 查询。
- 提供 `apply_damage(int)`，伤害不能让生命值低于 `0`。
- 提供 `heal(int)`，治疗不能让生命值高于 `100`。

参考接口：

```cpp
class Health {
public:
    explicit Health(int value);
    int value() const;
    void apply_damage(int amount);
    void heal(int amount);

private:
    int value_ = 100;
};
```

## 练习二：背包查询

目标：使用 `std::vector` 和 STL 算法实现只读查询。

要求：

- 定义 `Item { std::string name; int weight; }`。
- 定义 `Inventory = std::vector<Item>`。
- 实现 `bool contains(const Inventory&, std::string_view)`。
- 实现 `int total_weight(const Inventory&)`。
- 实现 `std::optional<Item> heaviest(const Inventory&)`。

## 练习三：存档文件

目标：练习 RAII 和错误处理。

要求：

- 定义 `SaveFile` 类，构造时打开路径。
- 打不开文件时抛出 `std::runtime_error`。
- 提供 `write_line(std::string_view)`。
- 不手写析构函数，让 `std::ofstream` 自己关闭文件。

## 练习四：把练习接入现有程序

可以先让 `src/main.cpp` 输出几行简单演示，再逐步拆分头文件和源文件。每次修改后运行：

```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build
ctest --test-dir build --output-on-failure
```

如果输出文本改变，记得同步更新 `CMakeLists.txt` 里的测试期望。

## 复盘问题

1. 哪些类型拥有资源？哪些类型只是观察？
2. 哪些函数承诺不修改参数？是否用 `const` 表达出来？
3. 错误是普通分支还是异常情况？你选择了哪种表达方式？
4. 是否有手写循环能替换成 STL 算法？
5. 如果下一步要写测试，最应该先测试哪条错误路径？
