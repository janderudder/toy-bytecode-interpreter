#pragma once
#include "bytecode/types.hpp"
#include <optional>
#include <vector>


inline auto parse_numbers(unsigned const argc, char** const argv, size_t count)
 -> std::optional<std::vector<Nat>>
{
    std::vector<Nat> numbers;

    for (size_t i=0; i < count; ++i)
    {
        numbers.push_back(std::atoi(argv[i]));
    }

    return !numbers.empty() ? std::make_optional(numbers) : std::nullopt;
}
