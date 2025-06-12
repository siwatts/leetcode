#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        /*
         * Given a circular array nums, find the maximum absolute difference between adjacent elements.
         *
         * Note: In a circular array, the first and last elements are adjacent.
         */
        // Wrap around first and last element as special case
        int maxDiff = abs(nums[0] - nums.back());
        for (int i = 1; i < nums.size(); i++)
        {
            maxDiff = max(maxDiff, abs(nums[i] - nums[i-1]));
        }
        return maxDiff;
    }
};

int main(int argc, char* argv[])
{
    cout << "3423-max-diff-adj-elem-circular-array\n";

    vector<int> nums = {1,2,4};
    int expected = 3;

    Solution soln;
    int result = soln.maxAdjacentDistance(nums);

    cout << "Answer: " << result << endl;
    if (result != expected)
    {
        cout << "Wrong answer, expected " << expected << endl;
    }

}

