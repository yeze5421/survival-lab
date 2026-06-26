#include "survival/day02/PointerExamples.hpp"

#include <array>
#include <iostream>
#include <memory>
#include <numeric>
#include <vector>

namespace survival::day02 {
namespace {

// 函数参数写成 int values[] 时，实际接收的是 int*，长度信息会丢失。
int sum_raw_array(const int values[], int size) {
    int total = 0;
    for (int i = 0; i < size; ++i) {
        total += values[i];  // values[i] 等价于 *(values + i)。
    }
    return total;
}

}  // namespace

void demo_address_and_pointer() {
    int x = 42;
    int* p = &x;  // &x 取得 x 的地址，p 保存这个地址。

    std::cout << "x value: " << x << '\n';
    std::cout << "address stored in p: " << p << '\n';
    std::cout << "value read through *p: " << *p << '\n';  // *p 解引用，访问 p 指向的对象。

    *p = 43;  // 非 const 指针可以通过解引用修改目标对象。
    std::cout << "x after *p = 43: " << x << '\n';
}

void demo_nullptr_and_dereference() {
    const int* p = nullptr;  // nullptr 明确表示这个指针当前不指向任何对象。
    std::cout << "safe_read_pointer(nullptr, -1): " << safe_read_pointer(p, -1) << '\n';

    int value = 7;
    p = &value;
    if (p != nullptr) {  // 解引用前先检查，避免未定义行为。
        std::cout << "safe value after nullptr check: " << *p << '\n';
    }
}

void demo_pointer_vs_reference() {
    int a = 10;
    int b = 20;

    const int* maybe_number = nullptr;  // 指针可以表达“可能没有值”。
    std::cout << "add_by_pointer(nullptr, &b): " << add_by_pointer(maybe_number, &b) << '\n';

    maybe_number = &a;
    std::cout << "add_by_pointer(&a, &b): " << add_by_pointer(maybe_number, &b) << '\n';
    std::cout << "add_by_reference(a, b): " << add_by_reference(a, b) << '\n';  // 引用调用处必须有对象。
}

void demo_const_pointer() {
    int a = 1;
    int b = 2;

    const int* pointer_to_const = &a;  // 不能通过 pointer_to_const 修改 a。
    pointer_to_const = &b;            // 但指针本身可以改为指向 b。
    std::cout << "const int* reads: " << *pointer_to_const << '\n';

    int* const const_pointer = &a;  // const_pointer 不能再改指向别处。
    *const_pointer = 3;             // 但可以通过它修改 a，因为指向的 int 不是 const。
    std::cout << "int* const changed a to: " << a << '\n';

    const int* const const_pointer_to_const = &b;  // 指针不能改指向，也不能通过它改 b。
    std::cout << "const int* const reads: " << *const_pointer_to_const << '\n';
}

void demo_array_decay() {
    int raw_values[3] = {1, 2, 3};
    std::cout << "raw array sum: " << sum_raw_array(raw_values, 3) << '\n';

    std::array<int, 3> fixed_values = {4, 5, 6};  // std::array 保留长度信息在类型中。
    const int fixed_total = std::accumulate(fixed_values.begin(), fixed_values.end(), 0);
    std::cout << "std::array sum: " << fixed_total << '\n';

    std::vector<int> dynamic_values = {7, 8, 9};  // std::vector 适合运行期长度变化。
    const int dynamic_total = std::accumulate(dynamic_values.begin(), dynamic_values.end(), 0);
    std::cout << "std::vector sum: " << dynamic_total << '\n';
}

void demo_dangling_pointer_warning() {
    int alive = 99;
    const int* safe_observer = &alive;  // 这里只是观察 alive，不拥有 alive。
    std::cout << "safe observer reads: " << *safe_observer << '\n';

    // 错误示例，不要这样写，也不要运行：
    // int* bad_pointer() {
    //     int local = 5;
    //     return &local;  // local 离开函数就销毁，返回的地址会变成悬空指针。
    // }
    // 结论：指针只是地址，不等于所有权；需要所有权时优先使用智能指针或值对象。
}

void demo_unique_ptr() {
    auto score = std::make_unique<int>(88);  // make_unique 创建对象并交给 unique_ptr 独占管理。
    std::cout << "unique_ptr value: " << *score << '\n';

    auto moved_score = std::move(score);  // unique_ptr 不能复制，只能移动所有权。
    std::cout << "source after move is null: " << (score == nullptr ? "yes" : "no") << '\n';
    std::cout << "moved unique_ptr value: " << *moved_score << '\n';
}

void demo_shared_ptr_and_weak_ptr() {
    auto shared = std::make_shared<int>(256);  // shared_ptr 表示多个地方可以共享同一个对象。
    std::weak_ptr<int> weak = shared;          // weak_ptr 只观察，不增加拥有者数量。

    {
        auto another_owner = shared;
        std::cout << "shared_ptr use_count while shared: " << shared.use_count() << '\n';
    }

    // use_count 适合演示和调试，不建议把业务逻辑建立在计数细节上。
    std::cout << "shared_ptr use_count after scope: " << shared.use_count() << '\n';

    if (auto locked = weak.lock()) {  // lock 成功说明对象还活着，并临时得到 shared_ptr。
        std::cout << "weak_ptr locked value: " << *locked << '\n';
    }

    shared.reset();
    std::cout << "weak_ptr expired after reset: " << (weak.expired() ? "yes" : "no") << '\n';
}

int add_by_pointer(const int* a, const int* b) {
    if (a == nullptr || b == nullptr) {
        return 0;  // 空指针不能解引用，用清晰规则返回安全值。
    }
    return *a + *b;
}

int add_by_reference(const int& a, const int& b) {
    return a + b;  // 引用语法像普通变量，但调用者必须传入有效对象。
}

int safe_read_pointer(const int* p, int fallback) {
    if (p == nullptr) {
        return fallback;
    }
    return *p;
}

int unique_ptr_value_demo() {
    auto value = std::make_unique<int>(123);
    return *value;  // 返回 int 值，不返回内部地址，避免泄露所有权细节。
}

}  // namespace survival::day02
