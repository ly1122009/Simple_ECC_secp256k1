#include <iostream>
#include "func.hpp"
#include <cstdint>

auto print_helloworld(void) -> void
{
    std::cout << "Hello World!\n";
}

auto cal_sum(uint32_t value1, uint32_t value2) -> uint32_t
{
    return value1 + value2;
}
