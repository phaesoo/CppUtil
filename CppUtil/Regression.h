#pragma once

#include <vector>

// Regression Analysis
class Regression
{
public:
    // Least Square Method
    static std::vector<double> LSM(const std::vector<double>& X, const std::vector<double>& Y, int degree = 2);
};