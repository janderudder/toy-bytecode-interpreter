#pragma once
#include "bytecode/Instruction.hpp"
#include "bytecode/types.hpp"
#include "bytecode/config.hpp"
#include <array>
#include <initializer_list>
#include <vector>


class Machine
{
public:
    Machine(size_t reg_count);

    template <typename It>
    void load(It program_begin, It program_end);
    void load(std::initializer_list<Instruction>);

    auto run() noexcept -> Nat;

    void write(Regindex, Nat);
    auto read(Regindex) const -> Nat;
    auto read(size_t) const -> Nat;

private:
    using program_counter_t = uint_t;
    using pc_offset_t       = program_counter_t;
    using handle_instr_fn_t = auto (Machine::*)(Regindex, Nat) -> pc_offset_t;

    static std::array<handle_instr_fn_t, OpCode_count> m_dispatch_table;

    std::vector<Nat>         m_reg;
    std::vector<Instruction> m_program;

    auto dispatch_instruction(Instruction const&) noexcept -> pc_offset_t;

    // instruction handlers
    pc_offset_t add(Regindex, Nat);
    pc_offset_t addc(Regindex, Nat);
    pc_offset_t div(Regindex, Nat);
    pc_offset_t divc(Regindex, Nat);
    pc_offset_t eq(Regindex, Nat);
    pc_offset_t eqc(Regindex, Nat);
    pc_offset_t jmp(Regindex, Nat);
    pc_offset_t jmpc(Regindex, Nat);
    pc_offset_t mod(Regindex, Nat);
    pc_offset_t modc(Regindex, Nat);
    pc_offset_t mul(Regindex, Nat);
    pc_offset_t mulc(Regindex, Nat);
    pc_offset_t nop(Regindex, Nat);
    pc_offset_t print(Regindex, Nat);
    pc_offset_t printc(Regindex, Nat);
    pc_offset_t ret(Regindex, Nat);
    pc_offset_t retc(Regindex, Nat);
    pc_offset_t set(Regindex, Nat);
    pc_offset_t setc(Regindex, Nat);

};



// inline impl.
////////////////////////////////////////////////////////////////////////////////
 template <typename It>
void Machine::load(It program_begin, It program_end)
{
    m_program = {program_begin, program_end};
}
