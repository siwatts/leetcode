#include <iostream>

using namespace std;

/*
Given two integers left and right, return the count of numbers in the inclusive
range [left, right] having a prime number of set bits in their binary
representation.

Recall that the number of set bits an integer has is the number of 1's present
when written in binary.

- For example, 21 written in binary is 10101, which has 3 set bits.
*/

class Solution
{
private:
    int countSetBits(int n)
    {
        int res = 0;
        while (n > 0)
        {
            if (n & 1)
            {
                res++;
            }
            n = n >> 1;
        }
        return res;
    }
    bool isPrimeNum(int n)
    {
        // Prime numbers are only divisble by themselves and 1
        // They must also be greater than 1 (0 and 1 are not prime)
        if (n <= 1)
        {
            return false;
        }
        for (int i = 2; i < n; i++)
        {
            if (n % i == 0)
            {
                return false;
            }
        }
        return true;
    }
public:
    int countPrimeSetBits(int left, int right)
    {
        int res = 0;

        for (int i = left; i <= right; i++)
        {
            if (isPrimeNum(countSetBits(i)))
            {
                res++;
            }
        }

        return res;
    }
};

int main(int argc, char *argv[])
{
    cout << "762-prime-num-set-bits-binary-repr\n";

    int left, right;
    int exp;
    if (argc > 3)
    {
        left = stoi(argv[1]);
        right = stoi(argv[2]);
        exp = stoi(argv[3]);
    }
    else
    {
        left = 6;
        right = 10;
        exp = 4;
    }
    cout << "Input: left = " << left << ", right = " << right << ", exp = " << exp << "\n";

    Solution sol;
    int res = sol.countPrimeSetBits(left, right);

    cout << "Output: res = " << res << "\n";
    if (exp == res)
        cout << "Test: PASS\n";
    else
        cout << "Test: FAIL\n";

    return 0;
}

