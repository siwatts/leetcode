#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
We define a harmonious array as an array where the difference between its
maximum value and its minimum value is exactly 1.

Given an integer array nums, return the length of its longest harmonious
among all its possible subsequences.
*/

class Solution
{
public:
    int findLHS(vector<int>& nums)
    {
        unordered_map<int,int> numFreq;
        for (auto n : nums)
        {
            numFreq[n]++;
        }

        vector<int> lengths;
        for (auto [n,f] : numFreq)
        {
            if (numFreq.find(n+1) != numFreq.end())
            {
                lengths.push_back(numFreq[n] + numFreq[n+1]);
            }
        }
        return (lengths.size() != 0) ? *max_element(lengths.begin(),lengths.end()) : 0;
    }
};

int main(int argc, char* argv[])
{
    cout << "594-longest-harmonious-subseq\n";

    vector<int> nums = { 1,3,2,2,5,2,3,7 };
    int exp = 5;

    Solution sol;
    int res = sol.findLHS(nums);

    cout << "Input: nums = [";
    for (auto n : nums)
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

