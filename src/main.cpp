#include <iostream>

#include "survival/day02/PointerExamples.hpp"

int main() {
    std::cout << "Survival Lab: C++20 ready\n";

    std::cout << "\n[Day 02] Pointer Survival Lab\n";

    std::cout << "\n1. Address and pointer\n";
    survival::day02::demo_address_and_pointer();

    std::cout << "\n2. nullptr and dereference\n";
    survival::day02::demo_nullptr_and_dereference();

    std::cout << "\n3. pointer vs reference\n";
    survival::day02::demo_pointer_vs_reference();

    std::cout << "\n4. const pointer\n";
    survival::day02::demo_const_pointer();

    std::cout << "\n5. array decay\n";
    survival::day02::demo_array_decay();

    std::cout << "\n6. dangling pointer warning\n";
    survival::day02::demo_dangling_pointer_warning();

    std::cout << "\n7. unique_ptr\n";
    survival::day02::demo_unique_ptr();

    std::cout << "\n8. shared_ptr and weak_ptr\n";
    survival::day02::demo_shared_ptr_and_weak_ptr();

    return 0;
}
