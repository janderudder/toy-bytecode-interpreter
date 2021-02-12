#include "sample/programs.hpp"


std::vector<Instruction> hello_world_program()
{
    constexpr auto R0 = Regindex{0};

    using namespace instruction_factory;

    return
    {
        print("hello, "),
        set(R0, "world!\n"),
        print(R0),
        ret(0)
    };
}
