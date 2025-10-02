#include <iostream>

using namespace std;

/*
You are given two integers numBottles and numExchange.

numBottles represents the number of full water bottles that you initially have.
In one operation, you can perform one of the following operations:

- Drink any number of full water bottles turning them into empty bottles.
- Exchange numExchange empty bottles with one full water bottle. Then, increase
numExchange by one.

Note that you cannot exchange multiple batches of empty bottles for the same
value of numExchange. For example, if numBottles == 3 and numExchange == 1, you
cannot exchange 3 empty water bottles for 3 full bottles.

Return the maximum number of water bottles you can drink.
*/

class Solution
{
public:
    int maxBottlesDrunk(int numBottles, int numExchange)
    {
        int drank = numBottles;

        while (numBottles >= numExchange)
        {
            drank++;
            numBottles -= numExchange - 1; // Minus the 1 we get back in exchange and drink
            numExchange++;
        }

        return drank;
    }
};

int main(int argc, char* argv[])
{
    cout << "3100-water-bottles-II\n";

    int numBottles, numExchange, exp;
    if (argc > 3)
    {
        numBottles = stoi(argv[1]);
        numExchange = stoi(argv[2]);
        exp = stoi(argv[3]);
    }
    else
    {
        numBottles = 13;
        numExchange = 6;
        exp = 15;
    }
    cout << "numBottles = " << numBottles << ", numExchange = " << numExchange << ", exp = " << exp << "\n";

    Solution sol;
    int res = sol.maxBottlesDrunk(numBottles, numExchange);

    cout << "res = " << res << "\n";
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

