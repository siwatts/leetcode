#include <iostream>
#include <vector>
#include <set>

using namespace std;

/*
You are given an array of positive integers nums and want to erase a subarray
containing unique elements. The score you get by erasing the subarray is equal
to the sum of its elements.

Return the maximum score you can get by erasing exactly one subarray.

An array b is called to be a subarray of a if it forms a contiguous subsequence
of a, that is, if it is equal to a[l],a[l+1],...,a[r] for some (l,r).
*/

class Solution
{
public:
    int maximumUniqueSubarray(vector<int>& nums, int startingPos)
    {
        // Need to find the longest unique subarray and sum it
        set<int> nSet;
        // Pre-seed with first value, incase we have all negative elements (simply
        // seeding with sum = 0 may not be correct)
        int n = nums[startingPos];
        nSet.insert(n);
        int sum = n;
        for (int i = startingPos+1; i < nums.size(); i++)
        {
            n = nums[i];
            if (nSet.contains(n))
            {
                // Finished, return what we found
                return sum;
            }
            else
            {
                // Keep going
                nSet.insert(n);
                sum += n;
            }
        }
        // We might hit the end without finding any duplicates, return what we found
        return sum;
    }
    int maximumUniqueSubarray(vector<int>& nums)
    {
        int sum = maximumUniqueSubarray(nums, 0);
        for (int i = 1; i < nums.size(); i++)
        {
            sum = max(sum, maximumUniqueSubarray(nums, i));
        }
        return sum;
    }
};

int main(int argc, char* argv[])
{
    cout << "1695-max-erasure-value\n";

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
        nums = { 4,2,4,5,6 };
        exp = 17;
    }

    Solution sol;
    int res = sol.maximumUniqueSubarray(nums);

    cout << "Input: nums = [ ";
    for (auto n : nums)
    {
        cout << n << " ";
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
