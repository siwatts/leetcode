#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

/*
You have two fruit baskets containing n fruits each. You are given two 0-indexed
integer arrays basket1 and basket2 representing the cost of fruit in each
basket. You want to make both baskets equal. To do so, you can use the following
operation as many times as you want:

- Chose two indices i and j, and swap the ith fruit of basket1 with the jth
  fruit of basket2.
- The cost of the swap is min(basket1[i],basket2[j]).

Two baskets are considered equal if sorting them according to the fruit cost
makes them exactly the same baskets.

Return the minimum cost to make both the baskets equal or -1 if impossible.
*/

class Solution
{
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2)
    {
        unordered_map<int,int> costFreq;
        unordered_map<int,int> costFreqBasket1;
        unordered_map<int,int> costFreqBasket2;
        for (auto& b: basket1)
        {
            costFreq[b]++;
            costFreqBasket1[b]++;
        }
        for (auto& b: basket2)
        {
            costFreq[b]++;
            costFreqBasket2[b]++;
        }
        // Check pre-condition
        for (auto& [c,f]: costFreq)
        {
            if (f % 2 == 1)
            {
                // Any odd number of 1 cost of fruit = not possible to balance the baskets
                return -1;
            }
        }

        // We need to find out which fruits require balancing
        //sort(basket1.begin(), basket1.end());
        //sort(basket2.begin(), basket2.end());
        vector<int> costToMove;
        for (auto& [c,f] : costFreq)
        {
            if (costFreqBasket1[c] != costFreqBasket2[c])
            {
                // 1 { 3,3,3 }, 2 { 3 }
                // 1 { 3,3 },   2 { 3,3 }
                int n = abs(costFreqBasket1[c] - costFreqBasket2[c]) / 2.0;
                for (int i = 0; i < n; i++)
                {
                    costToMove.push_back(c);
                }
            }
        }
        int res = 0;
        if (costToMove.size() % 2 != 0)
        {
            throw runtime_error("costToMove.size() must be even");
        }
        int swaps = costToMove.size() / 2.0;
        sort(costToMove.begin(), costToMove.end());
        for (int i = 0; i < swaps; i++)
        {
            res += costToMove[i];
        }

        return res;
    }
};

int main(int argc, char* argv[])
{
    cout << "2561-rearranging-fruits\n";

    vector<int> basket1 { 4,2,2,2 };
    vector<int> basket2 { 1,4,1,2 };
    int exp = 1;

    cout << "Input: basket1 = [";
    for (auto& b: basket1)
    {
        cout << b << ",";
    }
    cout << "], basket2 = [";
    for (auto& b: basket2)
    {
        cout << b << ",";
    }
    cout << "], exp = " << exp << "\n";

    Solution sol;
    int res = sol.minCost(basket1, basket2);

    cout << "Output: res = " << res << "\n";
    if (res == exp)
        cout << "Test: PASS\n";
    else
        cout << "Test: FAIL\n";

    return 0;
}

