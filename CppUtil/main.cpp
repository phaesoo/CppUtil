#include "Test_math.h"
#include "Graph.h"
#include <type_traits>
#include <iostream>

using namespace std;

int main()
{
    Test_Compare();

    Test_Graph();

    Test_Statistic();

    Test_SigFig();

    Test_LSM();
    return 0;
}