# 01. 值语义、生命周期与 RAII

## 老教授板书

C++ 的第一课不应该只是 `for` 循环，而应该是：对象什么时候出生，什么时候死亡，谁负责它拥有的资源。现代 C++ 的核心不是“到处写指针”，而是让对象把资源管理封装起来，让析构函数按作用域自动完成清理。

## 1. 值语义不是低级概念

值语义意味着一个对象可以像整数一样被复制、移动、比较和销毁，使用者不必知道内部是否管理了堆内存、文件句柄或网络连接。

```cpp
#include <string>
#include <vector>

struct Player {
    std::string name;
    int health = 100;
};

std::vector<Player> make_team() {
    return {Player{"Ada", 100}, Player{"Bjarne", 90}};
}
```

这里的 `Player` 没有手写析构函数、拷贝构造或赋值运算符，因为 `std::string` 已经正确管理自己的资源。老教授会说：能让编译器生成的，就不要抢着写。

## 2. 生命周期要尽量短

变量作用域越大，读代码时需要记住的状态越多。优先在第一次需要时声明变量，并让它尽快离开作用域。

```cpp
int total_alive_health(const std::vector<Player>& players) {
    int total = 0;
    for (const Player& player : players) {
        if (player.health > 0) {
            total += player.health;
        }
    }
    return total;
}
```

`player` 只在循环体内有效，`total` 只在函数内有效。生命周期边界清晰，bug 的活动范围也被缩小。

## 3. RAII：资源获取即初始化

RAII 的意思是把资源绑定到对象生命周期。构造函数拿资源，析构函数还资源，中间的普通成员函数只表达业务动作。

```cpp
#include <fstream>
#include <stdexcept>

class SaveFile {
public:
    explicit SaveFile(const std::string& path) : out_(path) {
        if (!out_) {
            throw std::runtime_error("cannot open save file");
        }
    }

    void write_score(int score) {
        out_ << "score=" << score << '\n';
    }

private:
    std::ofstream out_;
};
```

`SaveFile` 不需要手动 `close()`。即使写入过程中抛出异常，`out_` 的析构函数仍会在栈展开时运行。

## 4. Rule of Zero 优先于 Rule of Five

如果类的成员都能自己管理资源，就让编译器生成特殊成员函数：析构、拷贝、移动、赋值。只有当类直接管理裸资源时，才考虑手写这些函数。

```cpp
class Inventory {
public:
    void add(std::string item) {
        items_.push_back(std::move(item));
    }

private:
    std::vector<std::string> items_;
};
```

这就是 Rule of Zero：没有析构函数，没有拷贝控制，反而更安全。

## 课堂练习

1. 写一个 `SessionLog` 类，内部持有 `std::ofstream`，构造时打开文件，提供 `append(std::string_view)`。
2. 写一个 `Character` 结构体，包含 `std::string name`、`int health`、`std::vector<std::string> inventory`，不要手写析构函数。
3. 找出一个变量作用域过大的函数，把变量移动到最小必要作用域。

## 老教授检查清单

- 这个类是否真的需要 `new` 或 `delete`？
- 析构函数是否只是为了释放成员已经会释放的东西？如果是，删掉它。
- 函数里每个变量的生命周期是否足够短？
