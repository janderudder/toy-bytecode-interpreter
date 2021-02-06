#pragma once
#include "bytecode/Instruction.hpp"
#include <cstddef>


struct IProgram
{
    Instruction const*  _begin;
    size_t              _size;

    size_t size() const { return _size; }

    auto begin()  const -> Instruction const* { return _begin; }
    auto end()    const -> Instruction const* { return _begin + _size; }
    auto cbegin() const -> Instruction const* { return _begin; }
    auto cend()   const -> Instruction const* { return _begin + _size; }
};
