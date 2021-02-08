#pragma once
#include "bytecode/Instruction.hpp"
#include "bytecode/types.hpp"
#include <array>
#include <functional>


// function that binds argument value into program and returns it
////////////////////////////////////////////////////////////////////////////////
std::array<Instruction, 11> fibonacci_program(Nat);
