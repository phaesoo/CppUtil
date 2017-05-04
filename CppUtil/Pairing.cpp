#include <cassert>

#include "Pairing.h"

using namespace std;
using namespace math;

// [Reference] https://en.wikipedia.org/wiki/Pairing_function
int Pairing::CantorPair(int x, int y)
{
    if (!(ValidateData(x) && ValidateData(y)))
    {
        assert(0);
        return 0;
    }
    return (x + y) * (x + y + 1) / 2 + y;
}

pair<int, int> Pairing::CantorUnPair(int z)
{
    int w = static_cast<int>(floor((sqrt(8 * z + 1) - 1) / 2.0));
    int t = static_cast<int>(floor((w*w + w) / 2.0));

    int y = z - t;
    int x = w - y;
    if (!(ValidateData(x) && ValidateData(y)))
    {
        assert(0);
        return make_pair(-1, -1);
    }

    return make_pair(w - y, y);
}

// [Reference] http://szudzik.com/ElegantPairing.pdf
int Pairing::ElegantPair(int x, int y)
{
    if (x < y)
    {
        return y * y + x;
    }
    else
    {
        return x * x + x + y;
    }
}

pair<int, int> Pairing::ElegantUnPair(int z)
{
    int SqrtFloor = static_cast<int>(floor(sqrt(z)));
    int PowSqrtFloor = SqrtFloor*SqrtFloor;

    pair<int, int> pair;
    if ((z - PowSqrtFloor) < SqrtFloor)
    {
        pair.first = z - PowSqrtFloor;
        pair.second = SqrtFloor;
    }
    else
    {
        pair.first = SqrtFloor;
        pair.second = z - PowSqrtFloor - SqrtFloor;
    }

    return pair;
}