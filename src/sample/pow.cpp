#include "sample/programs.hpp"


std::vector<Instruction> pow_program(Nat n, Nat exp)
{
    constexpr auto rN   = Regindex{0};
    constexpr auto rEXP = Regindex{1};
    constexpr auto rACC = Regindex{2};

    using namespace instruction_factory;

    return
    {
        set(rN, n),         // Save original value.
        set(rACC, n),       // Value will accumulate in here.
        set(rEXP, exp),
        eq(rEXP, 0),        // Special case: check for exponent = 0.
        ret(1),
        eq(rEXP, 1),        // When exponent is 1,
        ret(rACC),          // return accumulator value;
        mul(rACC, rN),      // otherwise do a multiplication
        add(rEXP, -1),      // and decrease exponent (loop counter).
        jmp(-4)
    };
}
