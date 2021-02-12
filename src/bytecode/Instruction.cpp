#include "bytecode/Instruction.hpp"



namespace instruction_factory
{


Instruction add(Regindex lhs_reg, Regindex rhs_reg)
{
    return {OpCode::ADD, lhs_reg, static_cast<Nat>(rhs_reg)};
}



Instruction add(Regindex lhs_reg, Nat rhs_n)
{
    return {OpCode::ADDC, lhs_reg, rhs_n};
}



Instruction div(Regindex lhs_reg, Regindex rhs_reg)
{
    return {OpCode::DIV, lhs_reg, static_cast<Nat>(rhs_reg)};
}



Instruction div(Regindex lhs_reg, Nat rhs_n)
{
    return {OpCode::DIVC, lhs_reg, rhs_n};
}



Instruction eq(Regindex lhs_reg, Regindex rhs_reg)
{
    return {OpCode::EQ, lhs_reg, static_cast<Nat>(rhs_reg)};
}



Instruction eq(Regindex lhs_reg, Nat rhs_n)
{
    return {OpCode::EQC, lhs_reg, rhs_n};
}



Instruction jmp(Regindex rhs_reg)
{
    return {OpCode::JMP, 0, static_cast<Nat>(rhs_reg)};
}



Instruction jmp(Nat rhs_n)
{
    return {OpCode::JMPC, 0, rhs_n};
}



Instruction mod(Regindex lhs_reg, Regindex rhs_reg)
{
    return {OpCode::MOD, lhs_reg, static_cast<Nat>(rhs_reg)};
}



Instruction mod(Regindex lhs_reg, Nat rhs_n)
{
    return {OpCode::MODC, lhs_reg, rhs_n};
}



Instruction mul(Regindex lhs_reg, Regindex rhs_reg)
{
    return {OpCode::MUL, lhs_reg, static_cast<Nat>(rhs_reg)};
}



Instruction mul(Regindex lhs_reg, Nat rhs_n)
{
    return {OpCode::MULC, lhs_reg, rhs_n};
}



Instruction nop()
{
    return {OpCode::NOP, 0, 0};
}



Instruction print(Regindex rhs_reg)
{
    return {OpCode::PRINT, 0, static_cast<Nat>(rhs_reg)};
}



Instruction print(std::string_view rhs_str)
{
    return {OpCode::PRINTC, 0, reinterpret_cast<Nat const>(rhs_str.data())};
}



Instruction ret(Regindex rhs_reg)
{
    return {OpCode::RET, 0, rhs_reg};
}



Instruction ret(Nat rhs_n)
{
    return {OpCode::RETC, 0, rhs_n};
}



Instruction set(Regindex lhs_reg, Regindex rhs_reg)
{
    return {OpCode::SET, lhs_reg, static_cast<Nat>(rhs_reg)};
}



Instruction set(Regindex lhs_reg, Nat rhs_n)
{
    return {OpCode::SETC, lhs_reg, rhs_n};
}



Instruction set(Regindex lhs_reg, std::string_view rhs_str)
{
    return {OpCode::SETC, lhs_reg, reinterpret_cast<Nat const>(rhs_str.data())};
}



} // :: instruction_factory
