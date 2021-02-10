#include "sample/programs.hpp"


std::vector<Instruction> mul2_program(Nat a, Nat b)
{
    constexpr auto R0 = Regindex{0};

    using namespace instruction_factory;

    return
    {
        set(R0, a),
        mul(R0, b),
        ret(R0)
    };
}
