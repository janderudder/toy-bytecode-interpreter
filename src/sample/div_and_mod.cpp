#include "sample/programs.hpp"


std::vector<Instruction> div_and_mod_program(Nat a, Nat b)
{
    constexpr auto R0 = Regindex{0};
    constexpr auto R1 = Regindex{1};

    using namespace instruction_factory;

    return
    {
        set(R0, a),
        set(R1, a),
        div(R0, b),
        mod(R1, b),
        ret(0)
    };
}
