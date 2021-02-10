#include "common/parse_numbers.hpp"
#include "machine/Machine.hpp"
#include "sample/programs.hpp"
#include <iostream>


int main(int const argc, char** const argv)
{
    auto const args = parse_numbers(argc, argv);

    constexpr size_t needed_arg_count = 2;

    if (args.size() < needed_arg_count) {
        std::cout << "please provide " << needed_arg_count
                  << " numbers as arguments\n";
        return 0;
    }

    auto const prog = div_and_mod_program(args[0], args[1]);

    Machine machine {2};
    machine.load(prog.cbegin(), prog.cend());

    machine.run();

    std::cout << "r0: " << machine.read(0) << "\n";
    std::cout << "r1: " << machine.read(1) << "\n";
}
