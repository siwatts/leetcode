#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

/*

You are given an integer array nums of size n where n is a multiple of 3 and
a positive integer k.

Divide the array nums into n / 3 arrays of size 3 satisfying the following
condition:

The difference between any two elements in one array is less than or equal
to k.

Return a 2D array containing the arrays. If it is impossible to satisfy the
conditions, return an empty array. And if there are multiple answers, return any
of them.

Example 1:
Input: nums = [1,3,4,8,7,9,3,5,1], k = 2
Output: [[1,1,3],[3,4,5],[7,8,9]]

Explanation:
The difference between any two elements in each array is less than or equal
to 2.

 */

class Solution
{
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k)
    {
        int n = nums.size();
        int n3 = (int) n / 3.0;
        assert(n % 3 == 0);
        assert(n3 * 3 == n);

        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        // Want n3 arrays of length 3, where the elements differ
        // by no more than k
        // So we know we have a fixed amount to iterate over
        int index = 0;
        for (int i = 0; i < n3; i++)
        {
            if (nums[index+2] - nums[index] <= k)
            {
                // We keep this subarray
                vector<int> subarray = { nums[index], nums[index+1], nums[index+2] };
                result.push_back(subarray);
                index += 3;
            }
            else
            {
                // We failed to satisfy the conditions for this subarray
                // so we need to return empty vector for the entire operation
                return vector<vector<int>> {};
            }
        }

        return result;
    }
};

int main(int argc, char* argv[])
{
    cout << "2966-divide-array-arrays-max-diff\n";

    vector<int> nums;
    int k;
    if (argc > 2)
    {
        for (int i = 1; i < argc - 1; i++)
        {
            nums.push_back(atoi(argv[i]));
        }
        k = atoi(argv[argc-1]);
    }
    else
    {
        nums = { 1,3,4,8,7,9,3,5,1 };
        k = 2;
    }
    cout << "Input: [";
    for (auto& i : nums)
    {
        cout << i << ",";
    }
    cout << "], k = " << k << "\n";

    Solution sol;
    vector<vector<int>> res = sol.divideArray(nums, k);

    cout << "Output: [";
    for (auto& v : res)
    {
        cout << "[";
        for (auto& i : v)
        {
            cout << i << ",";
        }
        cout << "],";
    }
    cout << "]\n";

    return 0;
}

