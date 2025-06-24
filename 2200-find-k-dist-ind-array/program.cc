#include <iostream>
#include <vector>
#include <set>

using namespace std;

/*
You are given a 0-indexed integer array nums and two integers key and k. A
k-distant index is an index i of nums for which there exists at least one index
j such that |i - j| <= k and nums[j] == key.

Return a list of all k-distant indices sorted in increasing order.
*/

class Solution
{
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k)
    {
        int N = nums.size();
        vector<int> keyInd;
        for (int i = 0; i < N; i++)
        {
            if (nums[i] == key)
            {
                keyInd.push_back(i);
            }
        }

        vector<int> out;
        int nextStart = 0;
        for (int i : keyInd)
        {
            int start = (i - k) >= nextStart ? i - k : nextStart;
            int end = (i + k) < N ? i + k : N-1;
            for (int j = start; j <= end; j++)
            {
                out.push_back(j);
            }
            nextStart = end + 1;
        }

        return out;
    }
};

int main(int argc, char* argv[])
{
    cout << "2200-find-k-dist-ind-array\n";

    vector<int> nums;
    int key;
    int k;
    vector<int> exp;
    if (argc > 3)
    {
        // Array from arg 1 -> N-3
        // key at arg N-2
        // k at arg N-1
        for (int i = 1; i <= argc-3; i++)
        {
            nums.push_back(atoi(argv[i]));
        }
        key = atoi(argv[argc-2]);
        k = atoi(argv[argc-3]);
    }
    else
    {
        nums = { 3,4,9,1,3,9,5 };
        key = 9;
        k = 1;
        exp = { 1,2,3,4,5,6 };
    }

    Solution sol;
    vector<int> res = sol.findKDistantIndices(nums, key, k);

    cout << "Input: [";
    for (auto n : nums)
    {
        cout << n << ",";
    }
    cout << "], key = " << key << ", k = " << k << "\n";
    cout << "Output: [";
    for (auto n : res)
    {
        cout << n << ",";
    }
    cout << "]\n";

    return 0;
}


