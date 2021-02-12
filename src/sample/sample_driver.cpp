#include "sample/sample_driver.hpp"
#include <iostream>



////////////////////////////////////////////////////////////////////////////////
int sample_driver(int argc, char const** argv)
{
    auto const sample_config = get_sample_config(argc, argv);

    if (!sample_config) {
        return 0;
    }

    auto const& [register_count, program, end_callback] = *sample_config;

    Machine machine {register_count};

    machine.load(program.cbegin(), program.cend());

    auto const ret_value = machine.run();

    std::invoke(end_callback, machine, ret_value);

    return 0;
}



////////////////////////////////////////////////////////////////////////////////
std::vector<Nat> parse_cl_numbers(unsigned const argc, const char** argv)
{
    std::vector<Nat> numbers;

    for (size_t i=0; i < argc; ++i)
    {
        numbers.push_back(std::atoi(argv[i]));
    }

    return numbers;
}



// this function is a bit convoluted but the driver program is cleaner for it.
////////////////////////////////////////////////////////////////////////////////
auto get_sample_config(int const argc, const char** argv)
    -> std::optional<sample_config_t>
{
    std::string_view const prog_name = (argc > 1) ? argv[1] : "hello";

    auto const prog_args = (argc > 1)
        ? parse_cl_numbers(argc-2, &argv[2])
        : std::vector<Nat>{};


    // this function may return these default values
    sample_config_t sample_config = {0, {}, [](Machine&, Nat){}};


    auto& [register_count, program, end_callback] = sample_config;


    if (prog_name == "hello")
    {
        register_count = 2;
        program = hello_world_program();
    }

    else if (prog_name == "fib" || prog_name == "fibonacci")
    {
        register_count = 4;

        if (prog_args.empty()) {
            std::cout << "please provide the term number as argument\n";
            return std::nullopt;
        }

        auto const instructions = fibonacci_program(prog_args[0]);
        program = {instructions.cbegin(), instructions.cend()};

        end_callback = [](Machine&, Nat ret_value) {
            std::cout << ret_value << "\n";
        };
    }

    else if (prog_name == "div" || prog_name == "mod")
    {
        register_count = 2;

        if (prog_args.size() < 2) {
            std::cout<<"please provide the dividend and divisor as arguments\n";
            return std::nullopt;
        }

        program = div_and_mod_program(prog_args[0], prog_args[1]);

        end_callback = [](Machine& m, Nat) {
            std::cout << m.read(0) << "\n";
            std::cout << m.read(1) << "\n";
        };
    }

    else if (prog_name == "pow")
    {
        register_count = 3;

        if (prog_args.size() < 2) {
            std::cout << "please provide number and exponent as arguments\n";
            return std::nullopt;
        }

        program = pow_program(prog_args[0], prog_args[1]);

        end_callback = [](Machine&, Nat ret_value) {
            std::cout << ret_value << "\n";
        };
    }

    else
    {
        std::cout << "Unrecognized program name. ";
        std::cout << "Try 'hello' or 'fibonacci 42'\n";
        return std::nullopt;
    }


    return sample_config;

}
