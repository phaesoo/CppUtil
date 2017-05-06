#pragma once

#include <cmath>

// Significant Figures
namespace math
{
    inline double Scale(double x, int digits)
    {
        return std::pow(10.0, digits - std::ceil(std::log10(std::fabs(x))));
    }

    inline double Ceil(double x, int digits)
    {
        double scale = Scale(x, digits);
        return ceil(x * scale) / scale;
    }

    inline double Floor(double x, int digits)
    {
        double scale = Scale(x, digits);
        return floor(x * scale) / scale;
    }

    inline double Round(double x, int digits)
    {
        double scale = Scale(x, digits);
        return round(x * scale) / scale;
    }
}
