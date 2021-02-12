#include "sample/programs.hpp"


std::vector<Instruction> hello_world()
{
    auto const str1 = "hello\n";
    auto const str2 = "world\n";

    constexpr auto R0 = Regindex{0};

    using namespace instruction_factory;

    return
    {
        print(str1),
        set(R0, str2),
        print(R0),
        ret(0)
    };
}
