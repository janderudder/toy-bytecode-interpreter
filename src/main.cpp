#include "bytecode/Instruction.hpp"
#include "common/parse_numbers.hpp"
#include "machine/Machine.hpp"
#include "sample/programs.hpp"
#include <array>
#include <cstring>
#include <iostream>



int main(int const argc, char** const argv)
{
    auto const args = parse_numbers(argc, argv, 2);

    if (args.size() < 2) {
        std::cout << "please pass two numbers as arguments\n";
        return 0;
    }

    auto const n   = args[0];
    auto const exp = args[1];
    auto const pow_prog = pow_program(n, exp);

    Machine machine {4};
    machine.load(pow_prog.cbegin(), pow_prog.cend());

    auto const return_value = machine.run();

    std::cout << int(return_value) << "\n";
}
