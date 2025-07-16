#include <iostream>
#include <vector>

using namespace std;

/*
You are given an integer array nums.

A subsequence of nums with length x is called valid if it satisfies:
    (sub[0] + sub[1]) % 2 == (sub[1] + sub[2]) % 2 == ... == (sub[x - 2] + sub[x - 1]) % 2.

Return the length of the longest valid subsequence of nums.

A subsequence is an array that can be derived from another array by deleting
some or no elements without changing the order of the remaining elements.
*/

class Solution
{
public:
    int maximumLength(vector<int>& nums)
    {
        // There are 4 possible cases:
        // - All elements even
        // - All elements odd
        // - Elements alternate between even+odd / odd+even
        int evenCount = 0;
        int oddCount = 0;
        int evenAltCount = 0;
        bool evenAltFlip = false;
        int oddAltCount = 0;
        bool oddAltFlip = false;
        for (auto n : nums)
        {
            if (n % 2 == 0)
            {
                evenCount++;
                if (!evenAltFlip)
                {
                    evenAltCount++;
                    evenAltFlip = true;
                }
                if (oddAltFlip)
                {
                    oddAltCount++;
                    oddAltFlip = false;
                }
            }
            else
            {
                oddCount++;
                if (evenAltFlip)
                {
                    evenAltCount++;
                    evenAltFlip = false;
                }
                if (!oddAltFlip)
                {
                    oddAltCount++;
                    oddAltFlip = true;
                }
            }
        }

        return max(max(evenCount, oddCount), max(evenAltCount, oddAltCount));
    }
};

int main(int argc, char* argv[])
{
    cout << "3201-find-max-length-valid-subseq-I\n";

    vector<int> nums { 1,2,3,4 };
    int exp = 4;

    Solution sol;
    int res = sol.maximumLength(nums);

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
