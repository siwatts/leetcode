#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>

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

class SumBuilder
{
private:
    int x;
    int count;
    // The key is the freq!
    map<long long, set<int>> topElements;
    // The map is sorted so the minFreq is the first key
public:
    SumBuilder(int x) : x(x), count(0)
    {
    }
    void Add(int num, long long freq)
    {
        if (count < x)
        {
            // Seeding first elements
            topElements[freq].insert(num);
            count++;
        }
        else
        {
            long long minFreq = topElements.begin()->first;
            if (freq > minFreq)
            {
                // We must replace the lowest frequency top entry seen so far
                // But it may be a list of more than 1 number, so
                // in that case remove the smallest value
                if (topElements[minFreq].size() > 1)
                {
                    // Remove the smallest, at the beginning of the sorted set
                    topElements[minFreq].erase(topElements[minFreq].begin());
                }
                else
                {
                    // Remove this freq. entry entirely
                    topElements.erase(minFreq);
                }
                topElements[freq].insert(num);
            }
            else if (freq == minFreq)
            {
                // Special case where frequencies match, we keep the larger value in the set
                int smallestNum = *topElements[freq].begin();
                if (num > smallestNum)
                {
                    topElements[freq].erase(smallestNum);
                    topElements[freq].insert(num);
                }
            }
        }
    }
    long long Sum()
    {
        long long res = 0;
        for (auto& [f,ns] : topElements)
        {
            for (auto& n : ns)
            {
                res += n * f;
            }
        }
        return res;
    }
};

class Solution
{
private:
    long long findXSum(int x, unordered_map<int,long long>& numFreq)
    {
        if (x == 0)
            return 0;

        // Keep only top x most frequent occurrences
        SumBuilder sb(x);
        for (auto& [n,f] : numFreq)
        {
            sb.Add(n, f);
        }

        return sb.Sum();
    }
public:
    vector<long long> findXSum(vector<int>& nums, int k, int x)
    {
        int n = nums.size();
        int answerSize = n - k + 1;
        vector<long long> res;

        // Initial i = 0, length k, case here
        unordered_map<int, long long> numFreq;
        vector<int> subVector(nums.begin(), nums.begin() + k);
        for (auto& n: subVector)
        {
            numFreq[n]++;
        }
        res.push_back(findXSum(x, numFreq));
        // Re-use same map for efficiency
        for (int i = 1; i < answerSize; i++)
        {
            // i = 0, k = 4, length = 5
            //   x x x x o
            // i = 1, k = 4, length = 5
            //   o x x x x
            //   Remove 0 (i - 1)
            //   Add 4 (i + k - 1)
            // Remove element i - 1, Add element i + k - 1
            numFreq[nums[i-1]]--;
            numFreq[nums[i+k-1]]++;
            res.push_back(findXSum(x, numFreq));
        }

        return res;
    }
};

int main(int argc, char* argv[])
{
    cout << "3318-find-x-sum-of-all-k-long-subarr-I\n";

    vector<int> nums;
    int k;
    int x;
    if (argc > 3)
    {
        for (int i = 1; i < argc-2; i++)
        {
            nums.push_back(stoi(argv[i]));
        }
        k = stoi(argv[argc-2]);
        x = stoi(argv[argc-1]);
    }
    else
    {
        nums = { 1,1,2,2,3,4,2,3 };
        k = 6;
        x = 2;
    }
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

