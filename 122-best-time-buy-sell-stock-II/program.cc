#include <iostream>
#include <vector>

using namespace std;

/*
You are given an integer array prices where prices[i] is the price of a given
stock on the ith day.

On each day, you may decide to buy and/or sell the stock. You can only hold at
most one share of the stock at any time. However, you can buy it then
immediately sell it on the same day.

Find and return the maximum profit you can achieve.
*/

class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        int profit = 0;
        if (prices.size() < 2)
            return profit;

        auto it1 = prices.begin();
        auto it2 = prices.begin() + 1;
        while (it1 != prices.end() && it2 != prices.end())
        {
            if (*it2 > *it1)
            {
                // Buy day1 and sell day2
                profit += *it2 - *it1;
            }
            it1++;
            it2++;
        }

        return profit;
    }
};

int main(int argc, char* argv[])
{
    cout << "122-best-time-buy-sell-stock-II\n";

    vector<int> prices;
    int exp;
    if (argc > 2)
    {
        for (int i = 1; i < argc-1; i++)
        {
            prices.push_back(atoi(argv[i]));
        }
        exp = atoi(argv[argc-1]);
    }
    else
    {
        prices = { 7,1,5,3,6,4 };
        exp = 7;
    }
    Solution sol;
    int res = sol.maxProfit(prices);

    if (exp == res)
        cout << "Test: PASS\n";
    else
        cout << "Test: FAIL\n";

    return 0;
}

