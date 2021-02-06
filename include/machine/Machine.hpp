#pragma once
#include "bytecode/Instruction.hpp"
#include "bytecode/types.hpp"
#include "common/config.hpp"
#include <functional>
#include <vector>
class IProgram;


class Machine
{
    std::vector<Nat>            m_reg;
    std::vector<Instruction>    m_program;

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
    auto _fetch_value(Instruction const&) noexcept -> Nat;

};



// inline impl.
////////////////////////////////////////////////////////////////////////////////
 template <typename Fn, typename... Args>
void Machine::load(Fn&& prog_fn, Args&&... args)
{
    auto const& program = std::invoke(prog_fn, std::forward<Args>(args)...);
    m_program = {std::cbegin(program), std::cend(program)};
}
