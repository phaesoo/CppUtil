#include <cmath>
#include <cassert>

#include "Arithmetic.h"
#include "Statistic.h"

using namespace std;
using namespace math;

double Statistic::Mean(const vector<double>& vals)
{
    size_t size = vals.size();
    if (size < 1) { return 0.0; }

    double sum = 0.0;
    for (size_t i = 0; i < size; ++i)
    {
        sum += vals[i];
    }

    return sum / size;
}

double Statistic::Variance(const vector<double>& vals, bool isPopulation /*= false*/)
{
    size_t size = vals.size();
    if (size < 2) { return 0.0; } // 데이터 1개이하의 분산 의미 없음

    double mean = Mean(vals);

    double sum = 0.0;
    for (size_t i = 0; i < size; ++i)
    {
        sum += pow(vals[i] - mean, 2.0);
    }

    // 모분산이 아닐경우(표본)
    if (!isPopulation)
    {
        size = size - 1;
    }

    return sum / size;
}

double Statistic::StandartDeviation(const vector<double>& vals, bool isPopulation /*= false*/)
{
    return sqrt(Variance(vals, isPopulation));
}

double Statistic::Covariance(const vector<double>& X, const vector<double>& Y)
{
    if (!ValidateInput(X, Y))
    {
        assert(0);
        return 0.0;
    }

    double mean_X = Mean(X);
    double mean_Y = Mean(Y);

    double sum = 0.0;

    size_t n = X.size();
    for (auto i = 0; i < n; ++i)
    {
        sum += (X[i] - mean_X) * (Y[i] - mean_Y);
    }

    return sum / n;
}

double Statistic::CorrCoef(const std::vector<double>& X, const std::vector<double>& Y)
{
    double cov = Covariance(X, Y);

    double sd_X = StandartDeviation(X, true);
    double sd_Y = StandartDeviation(Y, true);

    return SafeDivide(cov, sd_X * sd_Y);
}

double Statistic::PearsonCorrCoef(const vector<double>& X, const vector<double>& Y)
{
    if (!ValidateInput(X, Y))
    {
        assert(0);
        return 0.0;
    }

    double sum_x = 0.0;
    double sum_y = 0.0;
    double sum_xy = 0.0;
    double sum_x2 = 0.0;
    double sum_y2 = 0.0;

    size_t n = X.size();
    for (auto i = 0; i < n; ++i)
    {
        sum_x += X[i];
        sum_y += Y[i];
        sum_xy += X[i] * Y[i];
        sum_x2 += pow(X[i], 2.0);
        sum_y2 += pow(Y[i], 2.0);
    }

    double upper = n *  sum_xy - sum_x * sum_y;
    double lower = sqrt((n * (sum_x2)-pow(sum_x, 2.0)) * (n * (sum_y2)-pow(sum_y, 2.0)));

    return SafeDivide(upper, lower);
}

bool Statistic::ValidateInput(const std::vector<double>& X, const std::vector<double>& Y)
{
    size_t n = X.size();
    if (n < 1)
    {
        assert(0);
        return false;
    }

    if (n != Y.size())
    {
        assert(0);
        return false;
    }

    return true;
}