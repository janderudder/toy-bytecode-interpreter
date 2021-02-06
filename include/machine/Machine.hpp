#pragma once
#include "bytecode/Instruction.hpp"
#include "bytecode/types.hpp"
#include "common/config.hpp"
#include <array>
#include <functional>
#include <vector>


class Machine
{
public:
    Machine(size_t reg_count);

     template <typename Fn, typename... Args>
    void load(Fn&& prog_fn, Args&&... args);

    auto run() noexcept -> Nat;

    void write(Regindex, Nat);
    auto read(Regindex) const -> Nat;

private:
    using program_counter_t         = u32_t;
    using pc_offset_t               = program_counter_t;

    auto _exec(Instruction const&) noexcept -> pc_offset_t;

    std::vector<Nat> m_reg;
    std::vector<Instruction> m_program;
    std::array<pc_offset_t(Machine::*)(Regindex, Nat), 256> m_dispatch_table;

    pc_offset_t add(Regindex, Nat);
    pc_offset_t addc(Regindex, Nat);
    pc_offset_t eq(Regindex, Nat);
    pc_offset_t eqc(Regindex, Nat);
    pc_offset_t jmp(Regindex, Nat);
    pc_offset_t jmpc(Regindex, Nat);
    pc_offset_t nop(Regindex, Nat);
    pc_offset_t ret(Regindex, Nat);
    pc_offset_t retc(Regindex, Nat);
    pc_offset_t set(Regindex, Nat);
    pc_offset_t setc(Regindex, Nat);

};



// inline impl.
////////////////////////////////////////////////////////////////////////////////
 template <typename Fn, typename... Args>
void Machine::load(Fn&& prog_fn, Args&&... args)
{
    auto const& program = std::invoke(prog_fn, std::forward<Args>(args)...);
    m_program = {std::cbegin(program), std::cend(program)};
}
