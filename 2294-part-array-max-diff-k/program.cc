#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
   You are given an integer array nums and an integer k. You may partition nums
   into one or more subsequences such that each element in nums appears in
   exactly one of the subsequences.

   Return the minimum number of subsequences needed such that the difference
   between the maximum and minimum values in each subsequence is at most k.

   A subsequence is a sequence that can be derived from another sequence by
   deleting some or no elements without changing the order of the remaining
   elements.

   Example 1:
   - Input: nums = [3,6,1,2,5], k = 2
   - Output: 2
   Explanation:
   - We can partition nums into the two subsequences [3,1,2] and [6,5].
   - The difference between the maximum and minimum value in the first subsequence is
     3 - 1 = 2.
   - The difference between the maximum and minimum value in the second
     subsequence is 6 - 5 = 1.
   - Since two subsequences were created, we return 2. It
     can be shown that 2 is the minimum number of subsequences needed.

 */

class Solution
{
public:
    int partitionArray(vector<int>& nums, int k)
    {
        // Loop over from smallest element?
        sort(nums.begin(), nums.end());

        int min = *nums.begin();
        int count = 1;
        for (const auto &i : nums)
        {
            if (i - min > k)
            {
                min = i;
                count++;
            }
        }

        return count;
    }
};

int main(int argc, char* argv[])
{
    cout << "2294-part-array-max-diff-k\n";

    vector<int> nums;
    int k;
    int exp;
    if (argc > 2)
    {
        for (int i = 1; i < argc - 2; i++)
        {
            nums.push_back(atoi(argv[i]));
        }
        k = atoi(argv[argc-2]);
        exp = atoi(argv[argc-1]);
    }
    else
    {
        nums = { 3,6,1,2,5 };
        k = 2;
        exp = 2;
    }
    cout << "Input: [";
    for (auto& i : nums)
    {
        cout << i << ",";
    }
    cout << "], k = " << k << "\n";

    Solution sol;
    int res = sol.partitionArray(nums, k);

    cout << "Output: " << res << "\n";
    cout << "Expected: " << exp << "\n";
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

