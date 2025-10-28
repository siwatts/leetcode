#include <iostream>
#include <vector>

using namespace std;

/*
You are given an integer array nums.

Start by selecting a starting position curr such that nums[curr] == 0, and
choose a movement direction of either left or right.

After that, you repeat the following process:

- If curr is out of the range [0, n - 1], this process ends.
- If nums[curr] == 0, move in the current direction by incrementing curr if you
  are moving right, or decrementing curr if you are moving left.
- Else if nums[curr] > 0:
    - Decrement nums[curr] by 1.
    - Reverse your movement direction (left becomes right and vice versa).
    - Take a step in your new direction.

A selection of the initial position curr and movement direction is considered
valid if every element in nums becomes 0 by the end of the process.

Return the number of possible valid selections.
*/

class Solution
{
public:
    bool isValidSelection(vector<int> nums, int start, int dir)
    {
        int curr = start;
        int N = nums.size();
        while (curr >= 0 && curr < N)
        {
            if (nums[curr] == 0)
            {
                curr += dir;
            }
            else if (nums[curr] > 0)
            {
                nums[curr]--;
                dir *= -1;
                curr += dir;
            }
            else
            {
                throw runtime_error("nums[curr] < 0");
            }
        }

        // Check whether resulting array is all 0
        for (auto& n : nums)
        {
            if (n != 0)
            {
                return false;
            }
        }
        return true;
    }
    int countValidSelections(vector<int>& nums)
    {
        vector<int> starts;
        int validCount = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
                starts.push_back(i);
        }

        for (int& st : starts)
        {
            // Test left and right
            int dir = -1;
            if (isValidSelection(nums, st, dir))
                validCount++;
            dir = 1;
            if (isValidSelection(nums, st, dir))
                validCount++;
        }

        return validCount;
    }
};

int main(int argc, char* argv[])
{
    cout << "3354-make-array-elem-equal-zero\n";

    vector<int> nums = { 1,0,2,0,3 };
    int exp = 2;

    Solution sol;
    int res = sol.countValidSelections(nums);

    cout << "Input: nums = [";
    for (auto& n: nums)
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

