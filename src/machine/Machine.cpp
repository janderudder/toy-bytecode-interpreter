#include "machine/Machine.hpp"
#include "machine/IProgram.hpp"



Machine::Machine(size_t reg_count):
    m_reg (reg_count, 0)
{
}



////////////////////////////////////////////////////////////////////////////////
auto Machine::run() noexcept -> Nat
{
    program_counter_t pc     = 0;
    pc_offset_t       offset = 0;

    do {
        offset = _exec(m_program[pc]);
        pc += offset;
    }
    while (offset != 0);

    if (compare_opcode(m_program[pc].code, OpCode::RET))
    {
        return _fetch_value(m_program[pc]);
    }
    else
    {
        return Nat(-1);
    }
}



////////////////////////////////////////////////////////////////////////////////
void Machine::write(Regindex rN, Nat n)
{
    m_reg[rN] = n;
}



auto Machine::read(Regindex rN) const -> Nat
{
    return m_reg[rN];
}



////////////////////////////////////////////////////////////////////////////////
auto Machine::_exec(Instruction const& instruction) noexcept -> pc_offset_t
{
    auto const& [code, lhs, rhs] = instruction;

    if (compare_opcode(code, OpCode::ADD))
    {
        m_reg[lhs] += _fetch_value(instruction);
    }
    else if (compare_opcode(code, OpCode::EQ))
    {
        if (m_reg[lhs] != rhs) {
            return 2;
        }
    }
    else if (compare_opcode(code, OpCode::JMP))
    {
        auto const value = _fetch_value(instruction);

        return (std::int32_t(value) < 0)
            ? value
            : value+1;
    }
    else if (compare_opcode(code, OpCode::RET))
    {
        return 0;
    }
    else if (compare_opcode(code, OpCode::SET))
    {
        m_reg[lhs] = _fetch_value(instruction);
    }

    return 1;
}



auto Machine::_fetch_value(Instruction const& instruction) noexcept -> Nat
{
    return (static_cast<u8_t>(instruction.code) & CONST_MASK)
        ? instruction.rhs
        : m_reg[instruction.rhs];
}
