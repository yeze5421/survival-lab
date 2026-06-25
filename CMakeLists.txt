cmake_minimum_required(VERSION 3.20)

project(survival_lab VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(survival_lab src/main.cpp)

enable_testing()
add_test(NAME survival_lab_runs COMMAND survival_lab)
set_tests_properties(survival_lab_runs PROPERTIES
    PASS_REGULAR_EXPRESSION "Survival Lab: C\\+\\+20 ready"
)
