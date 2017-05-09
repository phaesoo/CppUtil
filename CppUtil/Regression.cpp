#include <cassert>
#include <utility>

#include "MatrixAlgebra.h"
#include "Regression.h"

using namespace std;
using namespace Eigen;

// [ref] http://darkpgmr.tistory.com/56
vector<double> Regression::LSM(const vector<double>& X, const vector<double>& Y, int degree /*= 2*/)
{
    if (degree < 2)
    {
        // 2이상(최소 선형 그래프)
        assert(0);
        return vector<double>();
    }

    size_t sz = X.size();
    if (sz < 2)
    {
        // 데이터는 최소 2개이상
        assert(0);
        return vector<double>();
    }

    if (sz != Y.size())
    {
        assert(0);
        return vector<double>();
    }

    MatrixXd A(sz, degree);
    MatrixXd B(sz, 1);

    for (auto i = 0; i < sz; ++i)
    {
        for (int j = 0; j < degree; ++j)
        {
            A(i, j) = std::pow(X[i], static_cast<double>(degree - j - 1));
        }
    }

    auto result = MatrixAlgebra::PseudoInverse(A) * B;

    if (result.cols() != sz)
    {
        assert(0);
        return vector<double>();
    }

    if (result.rows() != 1)
    {
        assert(0);
        return vector<double>();
    }

    vector<double> param(sz, 0.0);

    for (int i = 0; i < sz; ++i)
    {
        param[i] = result(i, 0);
    }

    return param;
}