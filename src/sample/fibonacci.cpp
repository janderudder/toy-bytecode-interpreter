#include "sample/fibonacci.hpp"

using namespace instruction_factory;

constexpr auto R0 = Regindex{0};
constexpr auto R1 = Regindex{1};
constexpr auto R2 = Regindex{2};
constexpr auto R3 = Regindex{3};


std::array<Instruction, 11> fibonacci_program(Nat n)
{
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
