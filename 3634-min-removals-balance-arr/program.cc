#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
You are given an integer array nums and an integer k.

An array is considered balanced if the value of its maximum element is at most k
times the minimum element.

You may remove any number of elements from nums without making it empty.

Return the minimum number of elements to remove so that the remaining array is
balanced.

Note: An array of size 1 is considered balanced as its maximum and minimum are
equal, and the condition always holds true.
*/

class Solution
{
public:
    int minRemoval(vector<int>& nums, int k)
    {
        int N = nums.size();
        int removed = 0;
        int start = 0;
        int end = N-1;
        sort(nums.begin(), nums.end());
        double balance = nums[end] / (double)nums[start];
        while (balance > k && N > 1)
        {
            // Reduce
            double left = nums[start+1] / (double)nums[start];
            double right = nums[end] / (double)nums[end-1];
            if (right > left)
            {
                end--;
            }
            else
            {
                start++;
            }
            N--;
            removed++;
            balance = nums[end] / (double)nums[start];
        }

        return removed;
    }
};

int main(int argc, char* argv[])
{
    cout << "3634-min-removals-balance-arr\n";

    vector<int> nums;
    int k, exp;
    if (argc > 3)
    {
        // Args 1, ..., argc-3 -> array
        // Arg argc-2 -> k
        // Arg argc-1 -> exp
        for (int i = 1; i < argc-2; i++)
        {
            nums.push_back(stoi(argv[i]));
        }
        k = stoi(argv[argc-2]);
        exp = stoi(argv[argc-1]);
    }
    else
    {
        nums = { 2,1,5 };
        k = 2;
        exp = 1;
    }
    cout << "Input: nums = [";
    for (auto& n: nums)
    {
        cout << n << ",";
    }
    cout << "], k = " << k << ", exp = " << exp << "\n";

    Solution sol;
    int res = sol.minRemoval(nums, k);

    cout << "Ouptut: res = " << res << "\n";
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

