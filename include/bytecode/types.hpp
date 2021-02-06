#pragma once
#include "common/config.hpp"


using Nat = u32_t;


struct Regindex
{
    u8_t const index = 0;
    operator u8_t() const { return index; }
};
