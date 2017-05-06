#pragma once

#include <vector>
#include <iostream>
#include <cassert>

#include "Compare.h"
#include "Pairing.h"
#include "Graph.h"
#include "SigFig.h"
#include "Statistic.h"

using namespace std;
using namespace math;

void Test_Pair()
{
    int x = 5000;
    int y = 3000;

    int z = Pairing::CantorPair(x, y);
    auto k = Pairing::CantorUnPair(z);

    z = Pairing::ElegantPair(x, y);
    auto l = Pairing::ElegantUnPair(z);

    int zzz = 0;
}

void Test_Compare()
{
    if (!EQ0(0.0000000001))
    {
        assert(0);
    }

    if (!UQ0(0.0001))
    {
        assert(0);
    }

    if (!MT(0.0001, 0.00002))
    {
        assert(0);
    }

    if (!LT(0.00002, 0.0001))
    {
        assert(0);
    }

    if (!LE(0.00002, 0.0000200000001))
    {
        assert(0);
    }

    int a = 0;
}

void Test_Graph()
{
    Graph<int> gr(false);
    gr.AddVertex(1);
    gr.AddVertex(2);
    gr.AddVertex(3);
    gr.AddEdge(Edge<int>(1, 2));
    gr.AddEdge(Edge<int>(2, 3));

    vector <vector<int>> matrix;

    gr.GetAdjacentMatrix(matrix);

    for (int i = 0; i < matrix.size(); ++i)
    {
        for (int j = 0; j < matrix.size(); ++j)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void Test_Statistic()
{
    vector<double> X({ 43, 21, 25, 42, 57, 59 });
    vector<double> Y({ 99, 65, 79, 75, 87, 81 });

    double result = Statistic::PearsonCorrCoef(X, Y);

    int some = 0;
}

void Test_SigFig()
{
    double some1 = 12.33456;
    double some2 = 12.33454;

    double c = Ceil(some1, 3);
    double f = Floor(some1, 3);
    double r = Round(some1, 3);

    double c2 = Ceil(some2, 5);
    double f2 = Floor(some2, 5);
    double r2 = Round(some2, 5);

    int z = 0;
}