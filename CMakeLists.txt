cmake_minimum_required(VERSION 3.20)

project(survival_lab VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(survival_day02
    src/day02/PointerExamples.cpp
)
target_include_directories(survival_day02 PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_executable(survival_lab src/main.cpp)
target_link_libraries(survival_lab PRIVATE survival_day02)

add_executable(day02_pointer_test tests/day02_pointer_test.cpp)
target_link_libraries(day02_pointer_test PRIVATE survival_day02)

enable_testing()
add_test(NAME survival_lab_runs COMMAND survival_lab)
set_tests_properties(survival_lab_runs PROPERTIES
    PASS_REGULAR_EXPRESSION "Survival Lab: C\\+\\+20 ready"
)

add_test(NAME day02_pointer_test COMMAND day02_pointer_test)
