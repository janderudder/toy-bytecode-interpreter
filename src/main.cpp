#include "common/parse_numbers.hpp"
#include "machine/Machine.hpp"
#include "sample/programs.hpp"
#include <iostream>


int main(int const argc, char** const argv)
{
    auto const prog = hello_world();

    Machine machine {1};
    machine.load(prog.cbegin(), prog.cend());

    return machine.run();
}
