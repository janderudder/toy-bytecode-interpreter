#include "machine/Machine.hpp"



Machine::Machine(size_t reg_count):
    m_reg (reg_count, 0)
{
    m_dispatch_table[static_cast<size_t>(OpCode::ADD)]  = add;
    m_dispatch_table[static_cast<size_t>(OpCode::ADDC)] = addc;
    m_dispatch_table[static_cast<size_t>(OpCode::EQ)]   = eq;
    m_dispatch_table[static_cast<size_t>(OpCode::EQC)]  = eqc;
    m_dispatch_table[static_cast<size_t>(OpCode::JMP)]  = jmp;
    m_dispatch_table[static_cast<size_t>(OpCode::JMPC)] = jmpc;
    m_dispatch_table[static_cast<size_t>(OpCode::NOP)]  = nop;
    m_dispatch_table[static_cast<size_t>(OpCode::RET)]  = ret;
    m_dispatch_table[static_cast<size_t>(OpCode::RETC)] = retc;
    m_dispatch_table[static_cast<size_t>(OpCode::SET)]  = set;
    m_dispatch_table[static_cast<size_t>(OpCode::SETC)] = setc;
}



////////////////////////////////////////////////////////////////////////////////
auto Machine::run() noexcept -> Nat
{
    program_counter_t pc     = 0;
    pc_offset_t       offset = 0;

    do {
        offset = this->dispatch_instruction(m_program[pc]);
        pc += offset;
    }
    while (offset != 0);

    auto const& last_instruction = m_program[pc];

    if (last_instruction.code == OpCode::RET)
    {
        return m_reg[last_instruction.rhs];
    }
    else if (last_instruction.code == OpCode::RETC)
    {
        return last_instruction.rhs;
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
auto Machine::dispatch_instruction(Instruction const& instruction) noexcept -> pc_offset_t
{
    auto const& [code, lhs, rhs] = instruction;
    return
       std::invoke(m_dispatch_table[static_cast<size_t>(code)], this, lhs, rhs);
}



////////////////////////////////////////////////////////////////////////////////
Machine::pc_offset_t Machine::add(Regindex lhs, Nat rhs)
{
    m_reg[lhs] += m_reg[rhs];
    return 1;
}



Machine::pc_offset_t Machine::addc(Regindex lhs, Nat rhs)
{
    m_reg[lhs] += rhs;
    return 1;
}



Machine::pc_offset_t Machine::eq(Regindex lhs, Nat rhs)
{
    if (m_reg[lhs] != m_reg[rhs]) {
        return 2;
    }
    return 1;
}



Machine::pc_offset_t Machine::eqc(Regindex lhs, Nat rhs)
{
    if (m_reg[lhs] != rhs) {
        return 2;
    }
    return 1;
}



Machine::pc_offset_t Machine::jmp(Regindex lhs, Nat rhs)
{
    return (std::int32_t(m_reg[rhs]) < 0)
        ? m_reg[rhs]
        : m_reg[rhs]+1;
}



Machine::pc_offset_t Machine::jmpc(Regindex lhs, Nat rhs)
{
    return (std::int32_t(rhs) < 0)
        ? rhs
        : rhs+1;
}



Machine::pc_offset_t Machine::nop(Regindex lhs, Nat rhs)
{
    return 1;
}



Machine::pc_offset_t Machine::ret(Regindex lhs, Nat rhs)
{
    return 0;
}



Machine::pc_offset_t Machine::retc(Regindex lhs, Nat rhs)
{
    return 0;
}



Machine::pc_offset_t Machine::set(Regindex lhs, Nat rhs)
{
    m_reg[lhs] = m_reg[rhs];
    return 1;
}



Machine::pc_offset_t Machine::setc(Regindex lhs, Nat rhs)
{
    m_reg[lhs] = rhs;
    return 1;
}
