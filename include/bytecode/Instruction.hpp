#pragma once
#include "bytecode/OpCode.hpp"
#include "bytecode/types.hpp"



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
Instruction ret(Regindex);
Instruction ret(Nat);
Instruction set(Regindex, Regindex);
Instruction set(Regindex, Nat);
};
