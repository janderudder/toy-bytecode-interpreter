#include "sample/programs.hpp"


std::vector<Instruction> div_and_mod_program(Nat a, Nat b)
{
    constexpr auto R0 = Regindex{0};
    constexpr auto R1 = Regindex{1};

    using namespace instruction_factory;

    return
    {
        set(R0, b),
        eq(R0, 0),      // trying to divide by 0
        jmp(7),
        set(R0, a),     // trying to divide 0
        eq(R0, 0),
        jmp(4),
        set(R1, a),
        div(R0, b),
        mod(R1, b),
        jmp(2),
        set(R0, 0),     // handle the case where one or both args are 0
        set(R1, 0),
        ret(0)
    };
}
