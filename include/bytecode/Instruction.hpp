#pragma once
#include "bytecode/OpCode.hpp"
#include "bytecode/types.hpp"
#include <string_view>


struct Instruction
{
    OpCode   code;
    Regindex lhs;
    Nat      rhs;
};


namespace instruction_factory
{
Instruction add(Regindex, Regindex);
Instruction add(Regindex, Nat);
Instruction div(Regindex, Regindex);
Instruction div(Regindex, Nat);
Instruction eq(Regindex, Regindex);
Instruction eq(Regindex, Nat);
Instruction jmp(Regindex);
Instruction jmp(Nat);
Instruction mod(Regindex, Regindex);
Instruction mod(Regindex, Nat);
Instruction mul(Regindex, Regindex);
Instruction mul(Regindex, Nat);
Instruction nop();
Instruction print(Regindex);
Instruction print(std::string_view);
Instruction ret(Regindex);
Instruction ret(Nat);
Instruction set(Regindex, Regindex);
Instruction set(Regindex, Nat);
Instruction set(Regindex, std::string_view);
};
