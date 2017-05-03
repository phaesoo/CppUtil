#pragma once

#include "Compare.h"
#include "Pairing.h"
#include "assert.h"

using namespace math;
void Test_Pair()
{
    int x = 5000;
    int y = 3000;

    int z = Pairing::CantorPair(x, y);
    auto k = Pairing::CantorUnPair(z);

    z = Pairing::ElegantPair(x, y);
    auto l = Pairing::ElegantUnPair(z);

    int zzz = 0;
}

void Test_Compare()
{
    if (!Compare::EQ0(0.0000000001))
    {
        assert(0);
    }

    if (!Compare::UQ0(0.0001))
    {
        assert(0);
    }

    if (!Compare::MT(0.0001, 0.00002))
    {
        assert(0);
    }

    if (!Compare::LT(0.00002, 0.0001))
    {
        assert(0);
    }

    if (!Compare::LE(0.00002, 0.0000200000001))
    {
        assert(0);
    }

    int a = 0;
}