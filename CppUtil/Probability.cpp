#include "Probability.h"

#include <algorithm>
#include <assert.h>

using namespace std;
int Probability::Permutation(int n, int r, bool canRepeated /*= false*/)
{
    if (!ValidateInput(n, r))
    {
        assert(0);
        return 0;
    }

    if (canRepeated)
    {
        return static_cast<int>(pow(n, r));
    }
    else
    {
        int upper = Factorial(n);
        int lower = Factorial(n - r);
        if (lower < 1)
        {
            assert(0);
            return 0;
        }

        return upper / lower;
    }
}

int Probability::Combination(int n, int r, bool canRepeated /*= false*/)
{
    if (!ValidateInput(n, r))
    {
        assert(0);
        return 0;
    }

    if (canRepeated)
    {
        return Combination(n + r - 1, r, false);
    }
    else
    {
        int upper = Factorial(n);
        int lower = Factorial(r) * Factorial(n - r);
        if (lower < 1)
        {
            assert(0);
            return 0;
        }

        return upper / lower;
    }
}

int Probability::Factorial(int n)
{
    if (n < 0)
    {
        assert(0);
        return 0;
    }

    int result = 1;
    for (int i = n; i >= 1; --i)
    {
        result *= i;
    }
    return result;
}

bool Probability::ValidateInput(int n, int r)
{
    if (n < 0 || r < 0)
    {
        assert(0);
        return false;
    }

    if (n - r < 0)
    {
        assert(0);
        return false;
    }

    return true;
}
