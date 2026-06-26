#pragma once

namespace survival::day02 {

// 演示变量地址、指针保存地址、以及用 * 解引用读取值。
void demo_address_and_pointer();

// 演示 nullptr 表示“没有指向对象”，以及解引用前必须检查。
void demo_nullptr_and_dereference();

// 演示指针可以为空、引用必须绑定对象，并对比两种传参方式。
void demo_pointer_vs_reference();

// 演示 const int*、int* const、const int* const 三种 const 指针写法。
void demo_const_pointer();

// 演示原生数组在函数参数中退化为指针，并推荐 std::array / std::vector。
void demo_array_decay();

// 演示悬空指针风险：指针不代表所有权，不要返回局部变量地址。
void demo_dangling_pointer_warning();

// 演示 std::unique_ptr 的独占所有权、make_unique 和移动语义。
void demo_unique_ptr();

// 演示 std::shared_ptr 共享所有权与 std::weak_ptr 的非拥有观察。
void demo_shared_ptr_and_weak_ptr();

// 用指针读取两个整数；任一指针为空时返回 0，避免危险解引用。
int add_by_pointer(const int* a, const int* b);

// 用引用读取两个整数；引用调用时必须已经绑定到有效对象。
int add_by_reference(const int& a, const int& b);

// 安全读取指针；为空时返回 fallback，非空时返回 *p。
int safe_read_pointer(const int* p, int fallback);

// 返回 unique_ptr 管理对象中的值，用于测试独占所有权示例。
int unique_ptr_value_demo();

}  // namespace survival::day02
