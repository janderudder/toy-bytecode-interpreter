#pragma once
#include "machine/Machine.hpp"
#include "sample/programs.hpp"
#include <functional>
#include <optional>
#include <tuple>


// run a sample bytecode program - uses utilities below.
int sample_driver(int argc, char const** argv);

// extract numbers from command line arguments
std::vector<Nat> parse_cl_numbers(unsigned const argc, const char** argv);

// bytecode program and other information needed by the machine to run.
// Some programs return a value, others store their computation in registers,
// that's why we use a specific callback for each program to output the result.
using sample_config_t =
 std::tuple<size_t,std::vector<Instruction>,std::function<void(Machine&, Nat)>>;

// get it according to command line arguments
auto get_sample_config(int, const char**) -> std::optional<sample_config_t>;
