#include <iostream>
#include <vector>

using namespace std;

/*
Given an array of integers nums which is sorted in ascending order, and an
integer target, write a function to search target in nums. If target exists,
then return its index. Otherwise, return -1.

You must write an algorithm with O(log n) runtime complexity.
*/

class Solution
{
public:
    int search(vector<int>& nums, int target)
    {
        int N = nums.size();
        int left = 0;
        int right = N;
        int mid = (int)(N/2.0);

        int val;
        do
        {
            val = nums[mid];
            if (val < target)
            {
                if (left == mid)
                    break;
                left = mid;
            }
            else if (val > target)
            {
                if (right == mid)
                    break;
                right = mid;
            }
            mid = left + (int)((right - left) / 2.0);
        }
        while (val != target);

        if (val == target)
            return mid;
        else
            return -1;
    }
};

int main(int argc, char* argv[])
{
    cout << "704-binary-search\n";

    vector<int> nums = { 2,5 };
    int target = 2;
    int exp = 0;

    Solution sol;
    int res = sol.search(nums, target);

    cout << "Input: nums = [";
    for (auto n : nums)
    {
        cout << n << ",";
    }
    cout << "], target = " << target << ", exp = " << exp << "\n";
    cout << "Output: res = " << res << "\n";

    return 0;
}

