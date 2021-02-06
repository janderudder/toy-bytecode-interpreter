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
    NOP,
    RET,
    RETC,
    SET,
    SETC,
};
