#pragma once
#include "bytecode/types.hpp"
#include <cstdlib>
#include <vector>


inline auto parse_numbers(unsigned const argc, char** const argv)
 -> std::vector<Nat>
{
    std::vector<Nat> numbers;

    for (size_t i=1; i < argc; ++i)
    {
        numbers.push_back(std::atoi(argv[i]));
    }

    return numbers;
}
