cmake_minimum_required(VERSION 3.5.0)
project(ip_filter VERSION 0.1.0 LANGUAGES C CXX)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})

# Основная программа
add_executable(ip_filter main.cpp ip_filter.cpp)

target_compile_options(ip_filter PRIVATE -fconcepts)

file(COPY ${CMAKE_SOURCE_DIR}/ip_filter.tsv DESTINATION ${EXECUTABLE_OUTPUT_PATH})

# Подключаем GoogleTest
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/release-1.11.0.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

# Исполняемый файл для тестов
add_executable(tests tests.cpp ip_filter.cpp)  # Добавляем ip_filter.cpp для тестов
target_link_libraries(tests gtest gtest_main)

install(TARGETS ip_filter DESTINATION bin)
install(FILES ip_filter.tsv DESTINATION bin)

set(CPACK_GENERATOR "DEB;ZIP")

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT example@example.com)

include(CPack)

# Добавляем тесты в CTest
add_test(NAME ip_filter_test COMMAND tests)

