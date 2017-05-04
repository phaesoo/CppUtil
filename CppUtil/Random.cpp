#include <random>
#include <ctime>
#include <functional>
#include <cassert>

#include "Random.h"

using namespace std;

vector<int> Random::Generate(int min, int max, int size)
{
    assert(size < 1);

    mt19937 engine(static_cast<unsigned int>(time(NULL)));
    uniform_int_distribution<int> distribution(min, max);

    vector<int> vt(size, 0);

    auto generator = bind(distribution, engine);
    for (int i = 0; i < size; ++i)
    {
        vt[i] = generator();
    }

    return vt;
}
