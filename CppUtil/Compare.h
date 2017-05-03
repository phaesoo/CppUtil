#pragma once

#include <math.h>

#include "MathDef.h"

class Compare
{
public:
    Compare() = delete;

public:
    // Compare 2 numbers
    static bool EQ(double x, double y)
    {
        return fabs(x - y) < math::abs_tol;
    }

    static bool UQ(double x, double y)
    {
        return !EQ(x, y);
    }

    static bool LT(double x, double y)
    {
        return x - y < -math::abs_tol;
    }

    static bool LE(double x, double y)
    {
        return x - y < math::abs_tol;
    }

    static bool MT(double x, double y)
    {
        return x - y > math::abs_tol;
    }

    static bool ME(double x, double y)
    {
        return x - y > -math::abs_tol;
    }

    // Compare with Zero
    static bool EQ0(double x)
    {
        return EQ(x, 0.0);
    }

    static bool UQ0(double x)
    {
        return UQ(x, 0.0);
    }

    static bool LT0(double x)
    {
        return LT(x, 0.0);
    }

    static bool LE0(double x)
    {
        return LE(x, 0.0);
    }

    static bool MT0(double x)
    {
        return MT(x, 0.0);
    }

    static bool ME0(double x)
    {
        return ME(x, 0.0);
    }
};