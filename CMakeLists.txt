cmake_minimum_required(VERSION 3.5.0)
project(ip_filter VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Основная программа
add_executable(ip_filter main.cpp ip_filter.cpp)

# Подключаем GoogleTest
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/release-1.11.0.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()

# Исполняемый файл для тестов
add_executable(tests tests.cpp ip_filter.cpp)  # Добавляем ip_filter.cpp для тестов
target_link_libraries(tests gtest gtest_main)

# Добавляем тесты в CTest
add_test(NAME ip_filter_test COMMAND tests)

