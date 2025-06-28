#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
You are given an integer array nums and an integer k. You want to find a
subsequence of nums of length k that has the largest sum.

Return any such subsequence as an integer array of length k.

A subsequence is an array that can be derived from another array by deleting
some or no elements without changing the order of the remaining elements.
*/

class Solution
{
public:
    vector<int> maxSubsequence(vector<int>& nums, int k)
    {
        // We need the k top items, but must preserve the order
        vector<int> res;
        for (auto& n : nums)
        {
            if (res.size() < k)
            {
                res.push_back(n);
            }
            else
            {
                // Find min. value in res so far
                auto min = min_element(res.begin(), res.end());
                // If n greater, replace min value (not just the first lower value we find)
                if (n > *min)
                {
                    res.erase(min);
                    res.push_back(n);
                }
            }
        }

        return res;
    }
};

int main(int argc, char* argv[])
{
    cout << "2099-find-subseq-largest-sum\n";

    vector<int> nums;
    int k;
    if (argc > 2)
    {
        for (int i = 1; i < argc-1; i++)
        {
            nums.push_back(atoi(argv[i]));
        }
        k = atoi(argv[argc-1]);
    }
    else
    {
        nums = { 2,1,3,3 };
        k = 2;
    }

    Solution sol;
    vector<int> res = sol.maxSubsequence(nums, k);

    cout << "Input: nums = [";
    for (auto n : nums)
    {
        cout << n << ",";
    }
    cout << "], k = " << k << "\n";
    cout << "Output: res = [";
    for (auto n : res)
    {
        cout << n << ",";
    }
    cout << "]\n";

    return 0;
}

