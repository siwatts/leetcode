#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

/*
You are given an array of integers nums. You are also given an integer original
which is the first number that needs to be searched for in nums.

You then do the following steps:

- If original is found in nums, multiply it by two (i.e., set original = 2 * original).
- Otherwise, stop the process.
- Repeat this process with the new number as long as you keep finding the number.

Return the final value of original.
*/

class Solution
{
public:
    int findFinalValue(vector<int>& nums, int original)
    {
        unordered_set<int> s(nums.begin(), nums.end());

        while (s.contains(original))
        {
            original *= 2;
        }

        return original;
    }
};

int main(int argc, char* argv[])
{
    cout << "2154-keep-mult-found-val-by-2\n";

    vector<int> nums = { 5,3,6,1,12 };
    int original = 3;

    Solution sol;
    int res = sol.findFinalValue(nums, original);

    cout << "Input: nums = [ ";
    for (auto& n: nums)
    {
        cout << n << ",";
    }
    cout << " ], original = " << original << "\n";
    cout << "Output: res = " << res << "\n";

    return 0;
}

