#include "machine/Machine.hpp"
#include <functional>
#include <iostream>


// static member initialization
////////////////////////////////////////////////////////////////////////////////
std::array<Machine::handle_instr_fn_t, OpCode_count> Machine::m_dispatch_table
{
    add,
    addc,
    div,
    divc,
    eq,
    eqc,
    jmp,
    jmpc,
    mod,
    modc,
    mul,
    mulc,
    nop,
    print,
    printc,
    ret,
    retc,
    set,
    setc
};



////////////////////////////////////////////////////////////////////////////////
Machine::Machine(size_t reg_count):
    m_reg     (reg_count, Nat(0)),
    m_program (1, instruction_factory::ret(0))
{
}



////////////////////////////////////////////////////////////////////////////////
void Machine::load(std::initializer_list<Instruction> instructions)
{
    m_program = instructions;
}



////////////////////////////////////////////////////////////////////////////////
auto Machine::run() noexcept -> Nat
{
    program_counter_t pc     = 0;

    while (auto const offset = dispatch_instruction(m_program[pc]))
    {
        pc += offset;
    }

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



auto Machine::read(size_t rN) const -> Nat
{
    return m_reg[rN];
}



////////////////////////////////////////////////////////////////////////////////
auto Machine::dispatch_instruction(Instruction const& instruction) noexcept
 -> pc_offset_t
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



Machine::pc_offset_t Machine::div(Regindex lhs, Nat rhs)
{
    m_reg[lhs] /= m_reg[rhs];
    return 1;
}



Machine::pc_offset_t Machine::divc(Regindex lhs, Nat rhs)
{
    m_reg[lhs] /= rhs;
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
    return (signed_int_t(m_reg[rhs]) < 0)
        ? pc_offset_t(m_reg[rhs])
        : pc_offset_t(m_reg[rhs]+1);
}



Machine::pc_offset_t Machine::jmpc(Regindex lhs, Nat rhs)
{
    return (signed_int_t(rhs) < 0)
        ? pc_offset_t(rhs)
        : pc_offset_t(rhs+1);
}



Machine::pc_offset_t Machine::mod(Regindex lhs, Nat rhs)
{
    m_reg[lhs] %= m_reg[rhs];
    return 1;
}



Machine::pc_offset_t Machine::modc(Regindex lhs, Nat rhs)
{
    m_reg[lhs] %= rhs;
    return 1;
}



Machine::pc_offset_t Machine::mul(Regindex lhs, Nat rhs)
{
    m_reg[lhs] *= m_reg[rhs];
    return 1;
}



Machine::pc_offset_t Machine::mulc(Regindex lhs, Nat rhs)
{
    m_reg[lhs] *= rhs;
    return 1;
}



Machine::pc_offset_t Machine::nop(Regindex lhs, Nat rhs)
{
    return 1;
}


Machine::pc_offset_t Machine::print(Regindex lhs, Nat rhs)
{
    std::cout << reinterpret_cast<const char* const>(m_reg[rhs]);
    return 1;
}



Machine::pc_offset_t Machine::printc(Regindex lhs, Nat rhs)
{
    std::cout << reinterpret_cast<const char* const>(rhs);
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
