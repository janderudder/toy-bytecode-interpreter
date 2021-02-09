#pragma once
#include "bytecode/types.hpp"
#include <cstdlib>
#include <vector>


inline auto parse_numbers(unsigned const argc, char** const argv, size_t count)
 -> std::vector<Nat>
{
    std::vector<Nat> numbers;

    for (size_t i=1; i<argc && i<=count; ++i)
    {
        numbers.push_back(std::atoi(argv[i]));
    }

    return numbers;
}
