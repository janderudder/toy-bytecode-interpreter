#pragma once
#include "bytecode/config.hpp"


enum class OpCode : u8_t
{
    ADD,
    ADDC,
    DIV,
    DIVC,
    EQ,
    EQC,
    JMP,
    JMPC,
    MOD,
    MODC,
    MUL,
    MULC,
    NOP,
    RET,
    RETC,
    SET,
    SETC,
};



constexpr size_t OpCode_count = 17;
