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
    unordered_map<int, long long> numFreq;
    // The key is the freq!
    // The map is sorted so the minFreq is the first key
    map<long long, set<int>> freqToNum;
    map<long long, set<int>> topFreqToNum;
    int count = 0;
    long long sum;
    void ExtractTopFreq()
    {
        // Extract the top x entries, and keep a rolling sum
        while (count < x && freqToNum.size() > 0)
        {
            // Extract highest freq.
            auto it = freqToNum.rbegin(); // freq, set_of_num pair
            long long freq = it->first;
            while (count < x && it->second.size() > 0)
            {
                // Extract highest num first, from freq if more than 1
                int num = *(it->second.rbegin());
                it->second.erase(num);
                topFreqToNum[freq].insert(num);
                sum += num * freq;
                count++;
            }
            if (it->second.size() == 0)
            {
                // Don't leave behind a frequency entry with an empty set
                freqToNum.erase(freq);
            }
        }
    }
public:
    SumBuilder(int x, vector<int>& numsSubarr) : x(x), sum(0)
    {
        for (auto& n : numsSubarr)
        {
            numFreq[n]++;
        }
        // Now make full inverted map
        for (auto& [n, f] : numFreq)
        {
            freqToNum[f].insert(n);
        }

        // Pull top frequencies and a rolling sum
        ExtractTopFreq();
    }
    void Remove(int num)
    {
        // Remove from numFreq array
        // Remove from top or ordinary freq array
        // Add another to top in replacement if necessary
        long long oldFreq = numFreq[num];
        numFreq[num]--;
        if (topFreqToNum[oldFreq].erase(num))
        {
            // It was in the top x, keep track and resync
            sum -= num * oldFreq;
            count--;
        }
        else
        {
            freqToNum[oldFreq].erase(num);
        }
        // Replace it
        if (oldFreq > 1)
        {
            freqToNum[oldFreq - 1].insert(num);
        }
        // Re-sync the top x and sum (it might be this modified record or a new different one)
        ExtractTopFreq();
    }
    void Add(int num)
    {
        // Add to the numFreq array
        // Add to top or ordinary freq array, removing another from top if necessary
        numFreq[num]++;
        long long oldFreq = numFreq[num] - 1;
        if (oldFreq > 0)
        {
            // There is an old record to remove
            if (topFreqToNum[oldFreq].erase(num))
            {
                sum -= num * oldFreq;
                count--;
            }
            else
            {
                freqToNum[oldFreq].erase(num);
                // Also remove the smallest top element because we might be bigger than it now
                auto it = topFreqToNum.begin();
                for (auto& setNum: it->second)
                {
                    freqToNum[it->first].insert(setNum);
                    sum -= it->first * setNum;
                }
                topFreqToNum.erase(it);
                count--;
            }
        }
        // Add or replace it
        freqToNum[oldFreq+1].insert(num);
        // Re-sync the top x and sum
        ExtractTopFreq();
    }
    long long Sum()
    {
        return this->sum;
    }
};

class Solution
{
public:
    vector<long long> findXSum(vector<int>& nums, int k, int x)
    {
        int n = nums.size();
        int answerSize = n - k + 1;
        if (x == 0)
            return vector<long long>(answerSize, 0);
        vector<long long> res;

        // Initial i = 0, length k, case here
        vector<int> subVector(nums.begin(), nums.begin() + k);
        SumBuilder sb(x, subVector);
        res.push_back(sb.Sum());
        // Re-use same object for efficiency
        for (int i = 1; i < answerSize; i++)
        {
            // i = 0, k = 4, length = 5
            //   x x x x o
            // i = 1, k = 4, length = 5
            //   o x x x x
            //   Remove 0 (i - 1)
            //   Add 4 (i + k - 1)
            // Remove element i - 1, Add element i + k - 1
            sb.Remove(nums[i-1]);
            sb.Add(nums[i+k-1]);
            res.push_back(sb.Sum());
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

