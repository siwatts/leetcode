#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

/*
You are given a 0-indexed array nums of length n, consisting of non-negative
integers. For each index i from 0 to n - 1, you must determine the size of the
minimum sized non-empty subarray of nums starting at i (inclusive) that has the
maximum possible bitwise OR.

In other words, let `B_ij` be the bitwise OR of the subarray `nums[i...j]`. You
need to find the smallest subarray starting at i, such that bitwise OR of this
subarray is equal to `max(B_ik)` where `i <= k <= n - 1`.

The bitwise OR of an array is the bitwise OR of all the numbers in it.

Return an integer array answer of size n where answer[i] is the length of the
minimum sized subarray starting at i with maximum bitwise OR.

A subarray is a contiguous non-empty sequence of elements within an array.
*/

class Solution
{
public:
    vector<int> smallestSubarrays(vector<int>& nums)
    {
        int n = nums.size();
        // We need to test every subarray [i..n] from i = 0 to i = n,
        vector<int> res(n);

        // Iterate backwards
        // Track each bit of int with its earliest seen position
        // Strictly speaking we should find the size dynamically, but we know from
        // the problem constraints that nums[i] < 10^9. This can be represented in
        // 30 digits (2^0 to 2^29, ie. max value (2^30)-1)
        // we also happen to know that int = int32 for our compiler
        constexpr int digits = 30;
        array<int,digits> pos {0};
        int size;
        for (int i = n-1; i >= 0; i--)
        {
            int val = nums[i];
            for (int bitPosition = 0; val > 0 && bitPosition < digits; bitPosition++)
            {
                if (val & 1)
                {
                    pos[bitPosition] = i;
                }
                val = val >> 1;
            }
            // We now have an array of the earliest known location for each bit
            // we've seen so far, so the subarray size required here is from i to
            // max_element(pos)
            size = *max_element(pos.begin(), pos.end()) + 1 - i;
            // Can't have non-zero subarray, min 1
            res[i] = max(1, size);
        }

        return res;
    }
};

int main(int argc, char* argv[])
{
    cout << "2411-smallest-subarrays-max-bitwise-or\n";

    vector<int> nums = { 1,0,2,1,3 };
    vector<int> exp = { 3,3,2,2,1 };

    Solution sol;
    vector<int> res = sol.smallestSubarrays(nums);

    cout << "Input: nums = [";
    for (auto& n: nums)
    {
        cout << n << ",";
    }
    cout << "], exp = [";
    for (auto& e: exp)
    {
        cout << e << ",";
    }
    cout << "]\n";
    cout << "Output: res = [";
    for (auto& r: res)
    {
        cout << r << ",";
    }
    cout << "]\n";

    return 0;
}
