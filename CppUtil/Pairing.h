#pragma once

#include <utility>

namespace math
{
    class Pairing
    {
    public:
        Pairing() = delete;

        // Cantor
        static int CantorPair(int x, int y);
        static std::pair<int, int> CantorUnPair(int z);

        // Elegant
        static int ElegantPair(int x, int y);
        static std::pair<int, int> ElegantUnPair(int z);

    private:
        static bool ValidateData(int val) { return val >= 0 && val <= _maxVal; } // 0 ~ max

    private:
        static const int _maxVal = 5000; // 5000까지는 통과
    };
}
