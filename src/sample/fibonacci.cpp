#include "sample/programs.hpp"


std::array<Instruction, 11> fibonacci_program(Nat n)
{
    constexpr Regindex R0{0}, R1{1}, R2{2}, R3{3};

    using namespace instruction_factory;

    return
    {
        set(R0, n),
        set(R1, 0),
        set(R2, 1),
        eq(R0, 0),
        jmp(5),
        set(R3, R1),
        set(R1, R2),
        add(R2, R3),
        add(R0, -1),
        jmp(-6),
        ret(R1)
    };
}
