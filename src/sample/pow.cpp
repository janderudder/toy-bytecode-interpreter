#include "sample/programs.hpp"


std::vector<Instruction> pow_program(Nat n, Nat exp)
{
    constexpr Regindex Rn{0}, Rexp{1}, Racc{2};

    using namespace instruction_factory;

    return
    {
        set(Rn, n),         // Save original value.
        eq(Rn, 0),          // Special case, n is 0.
        ret(0),
        set(Rexp, exp),
        eq(Rexp, 0),        // Special case, exponent is 0.
        ret(1),
        set(Racc, n),       // Value will accumulate in here.
        eq(Rexp, 1),        // When exponent is 1,
        ret(Racc),          // return accumulator value.
        mul(Racc, Rn),      // Otherwise do a multiplication
        add(Rexp, -1),      // and decrease exponent (loop counter).
        jmp(-4)             // Then start again.
    };
}
