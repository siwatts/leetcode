#include <iostream>
#include <vector>

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
private:
public:
    bool DebugPrint = false;
    vector<int> smallestSubarrays(vector<int>& nums)
    {
        int n = nums.size();
        // We need to test every subarray [i..n] from i = 0 to i = n,
        vector<int> res(n);

        // Brute force approach
        int maxBitwiseOr;
        int bitwiseOr;
        int size;
        for (int i = 0; i < n; i++)
        {
            bitwiseOr = 0;
            maxBitwiseOr = -1;
            size = 0;
            for (int j = i; j < n; j++)
            {
                bitwiseOr |= nums[j];
                if (bitwiseOr > maxBitwiseOr)
                {
                    maxBitwiseOr = bitwiseOr;
                    size = (j+1)-i;
                }
            }
            res[i] = size;
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
    sol.DebugPrint = true;
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
