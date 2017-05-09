#pragma once

#include <Eigen/Core>
#include<Eigen/SVD>

class MatrixAlgebra
{
public:
    MatrixAlgebra() = default;

public:
    // pseudoInverse function
    // https://fuyunfei1.gitbooks.io/c-tips/content/pinv_with_eigen.html
    static Eigen::MatrixXd PseudoInverse(const Eigen::MatrixXd &a, double epsilon = std::numeric_limits<double>::epsilon())
    {
        Eigen::JacobiSVD< Eigen::MatrixXd > svd(a, Eigen::ComputeThinU | Eigen::ComputeThinV);
        double tolerance = epsilon * std::max(a.cols(), a.rows()) * svd.singularValues().array().abs()(0);
        return svd.matrixV() *  (svd.singularValues().array().abs() > tolerance).select(svd.singularValues().array().inverse(), 0).matrix().asDiagonal() * svd.matrixU().adjoint();
    }
};
