#include <iostream>
#include <vector>

using namespace std;

/*
Given a positive integer n, find and return the longest distance between any two
adjacent 1's in the binary representation of n. If there are no two adjacent
1's, return 0.

Two 1's are adjacent if there are only 0's separating them (possibly no 0's).
The distance between two 1's is the absolute difference between their bit
positions. For example, the two 1's in "1001" have a distance of 3.
*/

class Solution
{
public:
    int binaryGap(int n)
    {
        vector<int> bitPositions;
        int pos = 0;
        while (n > 0)
        {
            if (n & 1)
            {
                bitPositions.push_back(pos);
            }
            pos++;
            n = n >> 1;
        }
        int maxGap = 0;
        if (bitPositions.size() >= 2)
        {
            for (uint i = 1; i < bitPositions.size(); i++)
            {
                maxGap = max(maxGap, bitPositions[i]-bitPositions[i-1]);
            }
        }
        return maxGap;
    }
};

int main(int argc, char *argv[])
{
    cout << "\n";
    int n, exp;
    if (argc > 2)
    {
        n = stoi(argv[1]);
        exp = stoi(argv[2]);
    }
    else
    {
        n = 22;
        exp = 2;
    }
    cout << "Input: n = " << n << ", exp = " << exp << "\n";

    Solution sol;
    int res = sol.binaryGap(n);

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

