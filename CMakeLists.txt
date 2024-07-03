# Define version CMake
cmake_minimum_required(VERSION 3.22)

# Define project
project(TemplateProjectCpp VERSION 1.0.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD          20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS        OFF)


set(LIBRARY_NAME    Library)
set(EXECUTABLE_NAME Executable)
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/")



option(ENABLE_TESTING "Enable Testing with catch2" ON)
option(ENABLE_WARNINGS "Enable to add warnings to a target" ON)
option(ENABLE_WARNINGS_AS_ERRORS "Enable to treat warning as errors" OFF)
option(ENABLE_SANITIZER_ADDRESS "Enable Sanitizer address" OFF)
option(ENABLE_SANITIZER_UNDEFINED "Enable Sanitizer Undefined" OFF)


find_package(Catch2)
include(Catch)
if(ENABLE_WARNINGS OR ENABLE_WARNINGS_AS_ERRORS)
    include(Warnings)
endif(ENABLE_WARNINGS OR ENABLE_WARNINGS_AS_ERRORS)
if (ENABLE_SANITIZER_ADDRESS OR ENABLE_SANITIZER_UNDEFINED)
    include(Sanitizer)
    add_sanitizer_flags(ENABLE_SANITIZER_ADDRESS ENABLE_SANITIZER_UNDEFINED)
endif()

# Đặt đường dẫn tới các module tìm kiếm thư viện
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

# Tìm thư viện GMP và GMPXX
find_package(GMP REQUIRED)

add_subdirectory(app)
add_subdirectory(src)
add_subdirectory(inc)
add_subdirectory(test-vector)
add_subdirectory(tests)
add_subdirectory(catch2)
