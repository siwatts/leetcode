#include <iostream>

using namespace std;

/*
Hercy wants to save money for his first car. He puts money in the Leetcode bank
every day.

He starts by putting in $1 on Monday, the first day. Every day from Tuesday to
Sunday, he will put in $1 more than the day before. On every subsequent Monday,
he will put in $1 more than the previous Monday.

Given n, return the total amount of money he will have in the Leetcode bank at
the end of the nth day.
*/

class Solution
{
private:
    int day = 1;
    int moneyTotal = 0;
    int moneyDay = 1;
public:
    int totalMoney(int n)
    {
        for (int i = 1; i <= n; i++)
        {
            moneyTotal += moneyDay;

            if (day == 7)
            {
                // Next day will be the following Monday, reset
                day = 1;
                moneyDay -= 5;
            }
            else
            {
                day++;
                moneyDay++;
            }
        }

        return moneyTotal;
    }
};

int main(int argc, char* argv[])
{
    cout << "1716-calc-money-leetcode-bank\n";

    int n = 10;
    int exp = 37;

    Solution sol;
    int res = sol.totalMoney(n);

    cout << "Input: n = " << n << ", exp = " << exp << "\n";
    cout << "Output: res = " << res << "\n";
    if (res == exp)
        cout << "Test: PASS\n";
    else
        cout << "Test: FAIL\n";

    return 0;
}

