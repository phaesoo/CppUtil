#pragma once

#include <math.h>

#include "MathDef.h"

namespace math
{
    // Compare 2 numbers
    inline bool EQ(double x, double y)
    {
        return fabs(x - y) < math::abs_tol;
    }

    inline bool UQ(double x, double y)
    {
        return !EQ(x, y);
    }

    inline bool LT(double x, double y)
    {
        return x - y < -math::abs_tol;
    }

    inline bool LE(double x, double y)
    {
        return x - y < math::abs_tol;
    }

    inline bool MT(double x, double y)
    {
        return x - y > math::abs_tol;
    }

    inline bool ME(double x, double y)
    {
        return x - y > -math::abs_tol;
    }

    // Compare with Zero
    inline bool EQ0(double x)
    {
        return EQ(x, 0.0);
    }

    inline bool UQ0(double x)
    {
        return UQ(x, 0.0);
    }

    inline bool LT0(double x)
    {
        return LT(x, 0.0);
    }

    inline bool LE0(double x)
    {
        return LE(x, 0.0);
    }

    inline bool MT0(double x)
    {
        return MT(x, 0.0);
    }

    inline bool ME0(double x)
    {
        return ME(x, 0.0);
    }

}
