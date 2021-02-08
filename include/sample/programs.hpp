#pragma once
#include "bytecode/Instruction.hpp"
#include "bytecode/types.hpp"
#include <array>
#include <functional>
#include <vector>


// bind argument values into a program and return it
////////////////////////////////////////////////////////////////////////////////
std::array<Instruction, 11> fibonacci_program(Nat);
std::vector<Instruction>    mul2_program(Nat, Nat);
