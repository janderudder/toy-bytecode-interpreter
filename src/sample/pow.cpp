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
        eq(rN, 0),          // Special case, n is 0.
        ret(0),
        set(rEXP, exp),
        eq(rEXP, 0),        // Special case, exponent is 0.
        ret(1),
        set(rACC, n),       // Value will accumulate in here.
        eq(rEXP, 1),        // When exponent is 1,
        ret(rACC),          // return accumulator value.
        mul(rACC, rN),      // Otherwise do a multiplication
        add(rEXP, -1),      // and decrease exponent (loop counter).
        jmp(-4)             // Then start again.
    };
}
