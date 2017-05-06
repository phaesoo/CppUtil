#pragma once

#include <vector>
#include <numeric>
#include <cmath>

namespace math
{
	class Statistic
	{
	public:
		Statistic() = delete;

		static double Mean(const std::vector<double>& vals);
		static double Variance(const std::vector<double>& vals, bool isPopulation=false);
		static double StandartDeviation(const std::vector<double>& vals, bool isPopulation=false);

        static double Covariance(const std::vector<double>& X, const std::vector<double>& Y);

        // Population Correlation Coefficient
        static double CorrCoef(const std::vector<double>& X, const std::vector<double>& Y);

        // Sample Correlation Coefficient
        static double PearsonCorrCoef(const std::vector<double>& X, const std::vector<double>& Y);

    private:
        static bool ValidateInput(const std::vector<double>& X, const std::vector<double>& Y);
	};
};