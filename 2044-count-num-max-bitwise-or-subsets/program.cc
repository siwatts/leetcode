#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;

/*
Given an integer array nums, find the maximum possible bitwise OR of a subset of
nums and return the number of different non-empty subsets with the maximum
bitwise OR.

An array a is a subset of an array b if a can be obtained from b by deleting
some (possibly zero) elements of b. Two subsets are considered different if the
indices of the elements chosen are different.

The bitwise OR of an array a is equal to `a[0] OR a[1] OR ... OR a[a.length - 1]`
(0-indexed).
*/

class Solution
{
private:
    unordered_map<int,int> bitwiseOrScores;
public:
    int countMaxOrSubsets(vector<int>& nums)
    {
        int permutations = pow(2, nums.size());
        int maxScore = 0;
        int score;
        int mask;
        for (int i = 1; i <= permutations; i++)
        {
            // Use this binary number i as a bitmask so we try every combination
            // of elements
            score = 0;
            mask = i;
            int j = 0;
            while (mask > 0)
            {
                if (mask & 1)
                {
                    score |= nums[j];
                }
                j++;
                mask = mask << 1;
            }
            bitwiseOrScores[score]++;
            maxScore = max(maxScore, score);
        }

        return bitwiseOrScores[maxScore];
    }
};

int main(int argc, char* argv[])
{
    cout << "2044-count-num-max-bitwise-or-subsets\n";

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
        nums = { 3,1 };
        exp = 2;
    }

    cout << "Input: nums = [";
    for (auto& n : nums)
    {
        cout << n << ",";
    }
    cout << "], exp = " << exp << "\n";

    Solution sol;
    int res = sol.countMaxOrSubsets(nums);

    cout << "Output: res = " << res << "\n";

    return 0;
}
