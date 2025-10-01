#include <iostream>

using namespace std;

/*
There are numBottles water bottles that are initially full of water. You can
exchange numExchange empty water bottles from the market with one full water
bottle.

The operation of drinking a full water bottle turns it into an empty bottle.

Given the two integers numBottles and numExchange, return the maximum number of
water bottles you can drink.
*/

class Solution
{
public:
    int numWaterBottles(int numBottles, int numExchange)
    {
        if (numExchange == 0)
        {
            return numBottles;
        }

        // If more empties than required for exchange, exchange all we can iteratively
        int res = 0;
        int full = numBottles;
        while (full > 0)
        {
            // Add full bottle count to total
            res += full;
            // How many more can we get by exchange
            full = numBottles / numExchange;
            // How many in total we are left with = those from the exchange
            // plus the remainder that weren't exchanged
            numBottles = full + (numBottles % numExchange);
        }

        return res;
    }
};

int main(int argc, char* argv[])
{
    cout << "1518-water-bottles\n";

    int numBottles, numExchange, exp;
    if (argc > 3)
    {
        numBottles = stoi(argv[1]);
        numExchange = stoi(argv[2]);
        exp = stoi(argv[3]);
    }
    else
    {
        numBottles = 9;
        numExchange = 3;
        exp = 13;
    }
    cout << "numBottles = " << numBottles << ", numExchange = " << numExchange << ", exp = " << exp << "\n";

    Solution sol;
    int res = sol.numWaterBottles(numBottles, numExchange);

    cout << "Res = " << res << "\n";
    if (res == exp)
    {
        cout << "Test: PASS\n";
    }
    else
    {
        cout << "Test: FAIL\n";
    }

    return 0;
}

