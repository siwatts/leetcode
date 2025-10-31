#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/*
In the town of Digitville, there was a list of numbers called nums containing
integers from 0 to n - 1. Each number was supposed to appear exactly once in the
list, however, two mischievous numbers sneaked in an additional time, making the
list longer than usual.

As the town detective, your task is to find these two sneaky numbers. Return an
array of size two containing the two numbers (in any order), so peace can return
to Digitville.
*/

class Solution
{
public:
    vector<int> getSneakyNumbers(vector<int>& nums)
    {
        unordered_map<int,int> m;
        for (auto& n: nums)
        {
            m[n]++;
        }
        vector<int> res;
        for (auto& [n,c]: m)
        {
            if (c > 1)
                res.push_back(n);
        }

        return res;
    }
};

int main(int argc, char* argv[])
{
    cout << "3289-the-2-sneaky-nums-of-digitville\n";

    vector<int> nums = { 0,3,2,1,3,2 };
    vector<int> exp = { 2,3 };

    Solution sol;
    vector<int> res = sol.getSneakyNumbers(nums);

    cout << "Input: nums = [";
    for (auto& n: nums)
    {
        cout << n << ",";
    }
    cout << "], exp = [";
    for (auto& e: exp)
    {
        cout << e << ",";
    }
    cout << "]\n";
    cout << "Output: res = [";
    for (auto& r: res)
    {
        cout << r << ",";
    }
    cout << "]\n";
    bool match = false;
    if (exp.size() == res.size())
    {
        sort(exp.begin(), exp.end());
        sort(res.begin(), res.end());
        match = true;
        for (int i = 0; i < exp.size(); i++)
        {
            if (exp[i] != res[i])
            {
                match = false;
                break;
            }
        }
    }
    if (match)
    {
        cout << "Test: PASS\n";
    }
    else
    {
        cout << "Test: FAIL\n";
    }

    return 0;
}

