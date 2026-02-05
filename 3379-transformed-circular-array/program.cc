#include <iostream>
#include <vector>

using namespace std;

/*
You are given an integer array nums that represents a circular array. Your task
is to create a new array result of the same size, following these rules: For
each index i (where 0 <= i < nums.length), perform the following independent
actions:

- If nums[i] > 0: Start at index i and move nums[i] steps to the right in the
  circular array. Set result[i] to the value of the index where you land.
- If nums[i] < 0: Start at index i and move abs(nums[i]) steps to the left in
  the circular array. Set result[i] to the value of the index where you land.
- If nums[i] == 0: Set result[i] to nums[i].

Return the new array result.

Note: Since nums is circular, moving past the last element wraps around to the
beginning, and moving before the first element wraps back to the end.
*/

class Solution
{
public:
    vector<int> constructTransformedArray(vector<int>& nums)
    {
        vector<int> res(nums);
        int N = nums.size();
        for (int i = 0; i < N; i++)
        {
            if (nums[i] != 0)
            {
                int j = i + nums[i];
                while (j < 0)
                {
                    j += N;
                }
                j = j % N;
                res[i] = nums[j];
            }
            else
            {
                res[i] = nums[i];
            }
        }
        return res;
    }
};

int main(int argc, char* argv[])
{
    cout << "3379-transformed-circular-array\n";

    vector<int> nums = { 3,-2,1,1 };
    vector<int> exp = { 1,1,1,3 };

    Solution sol;
    vector<int> res = sol.constructTransformedArray(nums);

    bool pass = true;
    for (uint i = 0; i < exp.size(); i++)
    {
        if (exp[i] != res[i])
        {
            pass = false;
            break;
        }
    }

    cout << "Input: nums = [";
    for (auto& x: nums)
    {
        cout << x << ",";
    }
    cout << "], exp = [";
    for (auto& x: exp)
    {
        cout << x << ",";
    }
    cout << "]\nOutput: res = [";
    for (auto& x: res)
    {
        cout << x << ",";
    }
    cout << "]\n";
    if (pass)
        cout << "Test: PASS\n";
    else
        cout << "Test: FAIL\n";

    return 0;
}

