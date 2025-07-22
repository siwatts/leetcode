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
    int maximumUniqueSubarray(vector<int>& nums)
    {
        set<int> nSet;
        auto left = nums.begin();
        auto right = nums.begin()+1;
        int n = *left;
        int sum = n;
        int maxSum = sum;
        nSet.insert(n);
        // Sliding window approach with 2 pointers (iterators)
        // Move right forwards keeping the sum as we go, until
        // we hit a duplicate number, then move left forwards until
        // the duplicate is removed
        while (left != nums.end() && right != nums.end())
        {
            n = *right;
            if (nSet.contains(n))
            {
                while (left != nums.end() && *left != n)
                {
                    sum -= *left;
                    nSet.erase(*left);
                    left++;
                }
                // now left == n, we can remove it and continue
                left++;
            }
            else
            {
                sum += n;
                maxSum = max(maxSum, sum);
                nSet.insert(n);
            }
            right++;
        }
        return maxSum;
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
