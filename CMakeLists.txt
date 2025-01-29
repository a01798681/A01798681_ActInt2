cmake_minimum_required(VERSION 3.10)
project(GrafoTests)

set(CMAKE_CXX_STANDARD 17)

# Buscar GoogleTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Agregar ejecutables
add_executable(runTests test.cpp main.cpp)

# Linkear con GoogleTest
target_link_libraries(runTests GTest::GTest GTest::Main)
