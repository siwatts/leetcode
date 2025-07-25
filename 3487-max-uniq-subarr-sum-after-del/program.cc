#include <iostream>
#include <vector>
#include <ranges>
#include <numeric>

using namespace std;

/*
You are given an integer array nums.

You are allowed to delete any number of elements from nums without making it
empty. After performing the deletions, select a subarray of nums such that:

- All elements in the subarray are unique.
- The sum of the elements in the subarray is maximized.

Return the maximum sum of such a subarray.
*/

class Solution
{
public:
    int maxSum(vector<int>& nums)
    {
        auto n = nums | views::filter([] (auto const& x) { return x > 0; } );
        nums = vector<int>(n.begin(), n.end());
        sort(nums.begin(), nums.end());
        auto last = unique(nums.begin(), nums.end());
        nums.erase(last, nums.end());
        int sum = accumulate(nums.begin(), nums.end(), 0);

        return sum;
    }
};

int main(int argc, char* argv[])
{
    cout << "3487-max-uniq-subarr-sum-after-del\n";

    vector<int> nums;
    int exp;
    if (argc > 2)
    {
        for (int i = 1; i < argc-1; i++)
        {
            nums.push_back(atoi(argv[i]));
        }
        exp = atoi(argv[argc-1]);
    }
    else
    {
        nums = { 1,2,3,4,5 };
        exp = 15;
    }

    Solution sol;
    int res = sol.maxSum(nums);

    cout << "Input: nums = [";
    for (auto n: nums)
    {
        cout << n << ",";
    }
    cout << "], exp = " << exp << "\n";
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

