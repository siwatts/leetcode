#include <iostream>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

/*
You are given a 0-indexed integer array nums consisting of 3 * n elements.

You are allowed to remove any subsequence of elements of size exactly n from
nums. The remaining 2 * n elements will be divided into two equal parts:

- The first n elements belonging to the first part and their sum is sumfirst.
- The next n elements belonging to the second part and their sum is sumsecond.

The difference in sums of the two parts is denoted as sumfirst - sumsecond.

- For example, if sumfirst = 3 and sumsecond = 2, their difference is 1.
- Similarly, if sumfirst = 2 and sumsecond = 3, their difference is -1.

Return the minimum difference possible between the sums of the two parts after
the removal of n elements.

In this situation, minimum = most negative
*/

class Solution
{
public:
    long long minimumDifference(multiset<int>& first, multiset<int>& second, int n)
    {
        long long sumfirst = 0;
        long long sumsecond = 0;
        auto fit = first.begin();
        auto sit = second.rbegin();
        for (int i = 0; i < n; i++)
        {
            sumfirst += *fit;
            fit++;
            // Want most positive, so take n elements from end not beginning
            sumsecond += *sit;
            sit++;
        }
        return sumfirst - sumsecond;
    }
    long long minimumDifference(vector<int>& nums)
    {
        // For the elements that make up sumfirst, we want as negative as possible, <
        // For the elements that make up sumsecond, we want as positive as possible, >
        //
        // We must preserve the order, so when considering the most negative we can consider
        // the first 2/3rds, and when considering the most positive we can consider the last
        // 2/3rds
        // It doesn't matter if the most negative number in the list is in the final 1/3
        // because we cannot take it for our final list
        //
        // Scenarios:
        // - 2/3 -ve, 1/3 -ve,
        // - 2/3 -ve, 1/3 +ve
        // - 2/3 +ve, 1/3 -ve
        // - 2/3 +ve, 1/3 +ve
        // - 1/3 -ve, 2/3 -ve
        // - 1/3 -ve, 2/3 +ve
        // - 1/3 +ve, 2/3 -ve
        // - 1/3 +ve, 2/3 +ve
        int n = nums.size() / 3.0;

        // Do we just have to brute force all n possibilities?
        // From min/maxing every division from n|2n, n+1|2n-1, ..., 2n-1|n+1, 2n|n ?
        multiset<int> first(nums.begin(), nums.begin()+n); // First 1/3
        multiset<int> second(nums.begin()+n, nums.end()); // Last 2/3
        long long minDiff = minimumDifference(first, second, n);
        for (int i = 0; i < n; i++)
        {
            // Iterate through until we get to first 2/3, last 1/3
            int elem = nums[n+i];
            first.insert(elem);
            auto it = second.find(elem);
            if (it != second.end())
            {
                second.erase(it); // Only remove the first we found, if multiple
            }
            else
            {
                throw runtime_error("Didn't find second multimap value " + to_string(elem) + " for removal");
            }
            // Keep new diff if better
            minDiff = min(minDiff, minimumDifference(first, second, n));
        }

        return minDiff;
    }
};

int main(int argc, char* argv[])
{
    cout << "2163-min-diff-sums-after-removal-elem\n";

    vector<int> nums { 3,1,2 };
    long long exp = -1;
    Solution sol;
    long long res = sol.minimumDifference(nums);

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
