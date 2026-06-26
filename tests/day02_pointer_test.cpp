#include "survival/day02/PointerExamples.hpp"

#include <cassert>

int main() {
    const int a = 11;
    const int b = 31;

    assert(survival::day02::add_by_pointer(&a, &b) == 42);
    assert(survival::day02::add_by_pointer(nullptr, &b) == 0);
    assert(survival::day02::add_by_pointer(&a, nullptr) == 0);
    assert(survival::day02::add_by_reference(a, b) == 42);
    assert(survival::day02::safe_read_pointer(&a, -1) == 11);
    assert(survival::day02::safe_read_pointer(nullptr, -1) == -1);
    assert(survival::day02::unique_ptr_value_demo() == 123);

    return 0;
}
