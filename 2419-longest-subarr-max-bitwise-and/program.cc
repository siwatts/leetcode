#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
You are given an integer array nums of size n.

Consider a non-empty subarray from nums that has the maximum possible bitwise
AND.

- In other words, let k be the maximum value of the bitwise AND of any
  subarray of nums. Then, only subarrays with a bitwise AND equal to k should be
  considered.

Return the length of the longest such subarray.

The bitwise AND of an array is the bitwise AND of all the numbers in it.

A subarray is a contiguous sequence of elements within an array.
*/

class Solution
{
public:
    int longestSubarray(vector<int>& nums)
    {
        int maxVal = 0;
        vector<int> maxCount;
        bool maxPrev = false;

        for (auto& n: nums)
        {
            if (n > maxVal)
            {
                // Found a new max value
                // Start a new count vector
                maxVal = n;
                maxCount.clear();
                maxCount.push_back(1);
                maxPrev = true;
            }
            else if (n == maxVal)
            {
                if (maxPrev)
                {
                    // Continuing a contiguous subarray of maxVal
                    maxCount.back()++;
                }
                else
                {
                    // Starting a new contiguous subarray of maxVal
                    maxCount.push_back(1);
                    maxPrev = true;
                }
            }
            else // n < maxVal
            {
                if (maxPrev)
                {
                    maxPrev = false;
                }
            }
        }

        return *max_element(maxCount.begin(), maxCount.end());
    }
};

int main(int argc, char* argv[])
{
    cout << "2419-longest-subarr-max-bitwise-and\n";

    vector<int> nums = { 1,2,3,3,2,2 };
    int exp = 2;

    cout << "Input: nums = [";
    for (auto& n: nums)
    {
        cout << n << ",";
    }
    cout << "], exp = " << exp << "\n";

    Solution sol;
    int res = sol.longestSubarray(nums);

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

