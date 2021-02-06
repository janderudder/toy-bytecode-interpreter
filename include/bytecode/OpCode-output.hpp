#pragma once
#include "bytecode/OpCode-output.hpp"


inline const char* to_string(OpCode code) noexcept
{
    switch (code)
    {
    case OpCode::ADD:
        return "ADD";
    break;
    case OpCode::ADDC:
        return "ADDC";
    break;
    case OpCode::END:
        return "END";
    break;
    case OpCode::EQ:
        return "EQ";
    break;
    case OpCode::EQC:
        return "EQC";
    break;
    case OpCode::JMP:
        return "JMP";
    break;
    case OpCode::JMPC:
        return "JMPC";
    break;
    case OpCode::NOP:
        return "NOP";
    break;
    case OpCode::SET:
        return "SET";
    break;
    case OpCode::SETC:
        return "SETC";
    break;
    default:
        return "<unknown opcode>";
    break;
    }
}
