#pragma once

#include "Compare.h"

namespace math
{
    inline double SafeDivide(double upper, double lower)
    {
        return EQ0(lower) ? 0.0 : upper / lower;
    }
}
