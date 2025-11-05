#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

/*
You are given an array nums of n integers and two integers k and x.

The x-sum of an array is calculated by the following procedure:

- Count the occurrences of all elements in the array.
- Keep only the occurrences of the top x most frequent elements. If two
  elements have the same number of occurrences, the element with the bigger value
  is considered more frequent.
- Calculate the sum of the resulting array.

Note that if an array has less than x distinct elements, its x-sum is the sum of
the array.

Return an integer array answer of length n - k + 1 where answer[i] is the x-sum
of the subarray nums[i..i + k - 1].
*/

class Solution
{
private:
    long long findXSum(vector<int>& nums, int x)
    {
        if (x == 0)
            return 0;

        unordered_map<int,long long> numFreq;
        for (auto& n: nums)
        {
            numFreq[n]++;
        }
        // Keep only top x most frequent occurrences
        // So we need to sort numFreq by its value field
        vector<pair<int,long long>> numFreqSorted;
        for (auto& [n,f] : numFreq)
        {
            numFreqSorted.push_back({n,f});
        }
        sort(numFreqSorted.begin(), numFreqSorted.end(),
                [](auto a, auto b) {
                    if (a.second == b.second)
                    {
                        return a.first > b.first;
                    }
                    else
                    {
                        return a.second > b.second;
                    }
                });

        long long res = 0;
        x = min(x, (int)numFreqSorted.size());
        for (int i = 0; i < x; i++)
        {
            res += numFreqSorted[i].first * numFreqSorted[i].second;
        }

        return res;
    }
public:
    vector<long long> findXSum(vector<int>& nums, int k, int x)
    {
        int n = nums.size();
        int answerSize = n - k + 1;
        vector<long long> res;

        for (int i = 0; i < answerSize; i++)
        {
            vector<int> subVector(nums.begin() + i, nums.begin() + i + k);
            res.push_back(findXSum(subVector, x));
        }

        return res;
    }
};

int main(int argc, char* argv[])
{
    cout << "3318-find-x-sum-of-all-k-long-subarr-I\n";

    vector<int> nums = { 1,1,2,2,3,4,2,3 };
    int k = 6;
    int x = 2;
    cout << "Input: nums = [ ";
    for (auto& n: nums)
    {
        cout << n << ",";
    }
    cout << " ], k = " << k << ", x = " << x << "\n";

    Solution sol;
    vector<long long> res = sol.findXSum(nums, k, x);
    cout << "Output: res = [ ";
    for (auto& r: res)
    {
        cout << r << ",";
    }
    cout << " ]\n";

    return 0;
}

