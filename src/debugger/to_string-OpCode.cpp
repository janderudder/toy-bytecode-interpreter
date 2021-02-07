#include "debugger/to_string-OpCode.hpp"



constexpr char const* to_string(OpCode code) noexcept
{
    switch (code)
    {
    case OpCode::ADD:
        return "ADD";
    break;
    case OpCode::ADDC:
        return "ADDC";
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
    case OpCode::RET:
        return "RET";
    break;
    case OpCode::RETC:
        return "RETC";
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
