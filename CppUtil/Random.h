#pragma once

#include <vector>

class Random
{
public:
    Random() = delete;

public:
    static std::vector<int> Generate(int min, int max, int size);
};