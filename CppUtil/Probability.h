#pragma once

// [reference] http://mentalplex.blogspot.kr/2012/04/blog-post_1017.html
class Probability
{
public:
    Probability() = delete;

public:
    // nPr
    static int Permutation(int n, int r, bool canRepeated = false);
    // nCr
    static int Combination(int n, int r, bool canRepeated = false);
    // n!
    static int Factorial(int n);

private:
    static bool ValidateInput(int n, int r);
};