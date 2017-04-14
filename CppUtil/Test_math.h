#pragma once

#include "Pairing.h"

using namespace math;
void Test_math()
{
    int x = 5000;
    int y = 3000;

    int z = Pairing::CantorPair(x, y);
    auto k = Pairing::CantorUnPair(z);

    z = Pairing::ElegantPair(x, y);
    auto l = Pairing::ElegantUnPair(z);

    int zzz = 0;
}