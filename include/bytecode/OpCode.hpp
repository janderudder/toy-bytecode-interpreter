#pragma once
#include "common/config.hpp"


constexpr u8_t CONST_MASK = 1;


////////////////////////////////////////////////////////////////////////////////
enum class OpCode : u8_t
{
    ADD         = 0x02,
    ADDC        = ADD | CONST_MASK,
    EQ          = 0x04,
    EQC         = EQ | CONST_MASK,
    JMP         = 0x08,
    JMPC        = JMP | CONST_MASK,
    NOP         = 0x00,
    RET         = 0x80,
    RETC        = RET | CONST_MASK,
    SET         = 0x10,
    SETC        = SET | CONST_MASK,
};



////////////////////////////////////////////////////////////////////////////////
constexpr bool compare_opcode(OpCode const& c1, OpCode const& c2)
{
    return static_cast<u8_t>(c1) & static_cast<u8_t>(c2);
}
