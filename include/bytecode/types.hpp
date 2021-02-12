#pragma once
#include "bytecode/config.hpp"
#include <type_traits>



// strong typing for register indices, makes writing a bit easier
struct Regindex
{
    u8_t index = 0;
    operator u8_t() const { return index; }
};



// our number type needs to be able to point into memory (for strings)
using Nat = ptr_t;
