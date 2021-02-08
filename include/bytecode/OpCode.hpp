#pragma once
#include "common/config.hpp"


enum class OpCode : u8_t
{
    ADD,
    ADDC,
    EQ,
    EQC,
    JMP,
    JMPC,
    MUL,
    MULC,
    NOP,
    RET,
    RETC,
    SET,
    SETC,
};



constexpr size_t OpCode_count = 13;
