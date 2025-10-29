#include <iostream>
#include <cmath>

using namespace std;

/*
You are given a positive number n.

Return the smallest number x greater than or equal to n, such that the binary
representation of x contains only _set bits_
*/

class Solution
{
public:
    int smallestNumber(int n)
    {
        // This is a maths problem
        // Find the highest set bit required for the number n
        // This will be the power of 2
        int pow = (int)log2(n);

        int x = 1;
        for (int i = 0; i < pow; i++)
        {
            x = x << 1;
            x = x | 1;
        }

        return x;
    }
};

int main(int argc, char* argv[])
{
    cout << "3370-smallest-num-all-set-bits\n";

    int n = 5;
    int exp = 7;

    cout << "Input: n = " << n << ", exp = " << exp << "\n";

    Solution sol;
    int res = sol.smallestNumber(n);

    cout << "Output: res = " << res << "\n";
    if (res == exp)
    {
        cout << "Test: PASS\n";
    }
    else
    {
        cout << "Test: FAIL\n";
    }

    return 0;
}
