#include <iostream>
#include <vector>

using namespace std;

/*
You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/

class Solution
{
    vector<int> stairCounts;
    int getStairCount(int n)
    {
        // Careful not to mix up stair count, vs the array index
        int i = n-1;
        if (i < 0 || i >= stairCounts.size())
        {
            throw logic_error("array size = " + to_string(stairCounts.size()) + ", i = " + to_string(i));
        }
        if (stairCounts[i] == 0)
        {
            stairCounts[i] = getStairCount(n-1) + getStairCount(n-2);
        }

        return stairCounts[i];
    }
public:
    int climbStairs(int n)
    {
        // Dynamic programming we hardcode the 1st 2:
        // n = 1: [1] = 1
        // n = 2: [1,1], [2] = 2
        // Store them in a vector with index n-1
        stairCounts.resize(max(n, 2), 0);
        stairCounts[0] = 1;
        stairCounts[1] = 2;

        // After that it is always (n-1) + (n-2) counts, because you are adding one
        // way to get to the new number by adding a final 2 step (n-2) and one by 1 step
        // (n-1)
        return getStairCount(n);
    }
};

int main(int argc, char* argv[])
{
    cout << "70-climbing-stairs\n";

    int n;
    int exp;
    if (argc > 2)
    {
        n = atoi(argv[1]);
        exp = atoi(argv[2]);
    }
    else
    {
        n = 3;
        exp = 3;
    }

    Solution sol;
    int res = sol.climbStairs(n);

    cout << "Input: n = " << n << ", exp = " << exp << "\n";
    cout << "Output: res = " << res << "\n";
    if (res == exp)
        cout << "Test: PASS\n";
    else
        cout << "Test: FAIL\n";

    return 0;
}

