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
    int isValidSelection(vector<int> nums, int start)
    {
        int N = nums.size();
        // If the sum of elements left + right of start are equal, we
        // can start in either direction and will reduce them all to 0
        // by bouncing between them
        // If one side is +/-1 of the other, we must start in that direction
        // specifically so only one dir. is valid
        int sumLeft = 0;
        int sumRight = 0;
        for (int i = 0; i < start; i++)
        {
            sumLeft += nums[i];
        }
        for (int i = start + 1; i < N; i++)
        {
            sumRight += nums[i];
        }

        int diff = abs(sumLeft - sumRight);
        if (diff == 0)
            return 2;
        else if (diff == 1)
            return 1;
        else
            return 0;
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
            validCount += isValidSelection(nums, st);
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

