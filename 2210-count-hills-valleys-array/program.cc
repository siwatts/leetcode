#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
You are given a 0-indexed integer array nums. An index i is part of a hill in
nums if the closest non-equal neighbors of i are smaller than nums[i].
Similarly, an index i is part of a valley in nums if the closest non-equal
neighbors of i are larger than nums[i]. Adjacent indices i and j are part of the
same hill or valley if nums[i] == nums[j].

Note that for an index to be part of a hill or valley, it must have a non-equal
neighbor on both the left and right of the index.

Return the number of hills and valleys in nums.
*/

class Solution
{
public:
    int countHillValley(vector<int>& nums)
    {
        // Remove consecutive equal values, so we don't have to worry about
        // hills or valleys being multiple values wide
        // Now we can just consider adjacent values
        auto last = unique(nums.begin(), nums.end());
        nums.erase(last, nums.end());
        // At least 3 remaining items are required for a hill or valley
        if (nums.size() < 3)
            return 0;

        int count = 0;
        // Lets examine adjacent array elements a,b,c with indices j-1,j,j+1
        int a,b,c;
        for (size_t j = 1; j < nums.size()-1; j++)
        {
            a = nums[j-1];
            b = nums[ j ];
            c = nums[j+1];
            if (a < b && c < b)
            {
                // Hill
                count++;
            }
            else if (a > b && c > b)
            {
                // Valley
                count++;
            }
        }

        return count;
    }
};

int main(int argc, char* argv[])
{
    cout << "2210-count-hills-valleys-array\n";

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
        nums = { 2,4,1,1,6,5 };
        exp = 3;
    }
    Solution sol;
    int res = sol.countHillValley(nums);

    cout << "Input: nums = [";
    for (auto n: nums)
    {
        cout << n << ",";
    }
    cout << "], exp = " << exp << "\n";
    cout << "Output: res = " << res << "\n";

    return 0;
}

