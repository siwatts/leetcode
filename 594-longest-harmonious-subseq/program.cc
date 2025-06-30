#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
We define a harmonious array as an array where the difference between its
maximum value and its minimum value is exactly 1.

Given an integer array nums, return the length of its longest harmonious
among all its possible subsequences.
*/

class Solution
{
public:
    int findLHS(vector<int>& nums)
    {
        // We require a sorted array
        sort(nums.begin(), nums.end());
        // Brute force starting +1 difference arrays at various starting values nums[i]
        // and make vector to hold the resulting span sizes
        vector<int> spans;
        spans.resize(nums.size(), 1);
        // Loop possible starting values
        for (int i = 0; i < nums.size(); i++)
        {
            int start = nums[i];
            for (int j = i+1; j < nums.size(); j++)
            {
                if (nums[j] - start <= 1)
                {
                    spans[i]++;
                }
                else
                {
                    break;
                }
            }
        }

        return *max_element(spans.begin(), spans.end());
    }
};

int main(int argc, char* argv[])
{
    cout << "594-longest-harmonious-subseq\n";

    vector<int> nums = { 1,3,2,2,5,2,3,7 };
    int exp = 5;

    Solution sol;
    int res = sol.findLHS(nums);

    cout << "Input: nums = [";
    for (auto n : nums)
    {
        cout << n << ",";
    }
    cout << "], exp = " << exp << "\n";
    cout << "Output: res = " << res << "\n";
    if (exp == res)
    {
        cout << "Test: PASS\n";
    }
    else
    {
        cout << "Test: FAIL\n";
    }

    return 0;
}

