#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

/*
Given an integer n, return the decimal value of the binary string formed by
concatenating the binary representations of 1 to n in order, modulo 10^9 + 7.
*/

class Solution
{
private:
    string numToBin(int n)
    {
        string s = "";
        //cout << "DEBUG: n = " << n;
        while (n > 0)
        {
            if (n & 1)
            {
                s.insert(0, "1");
            }
            else
            {
                s.insert(0, "0");
            }
            n >>= 1;
        }
        //cout << " -> s = " << s << "\n";
        return s;
    }
    long long binToNum(string s)
    {
        long long pow2 = 1;
        long long MAX = pow(10, 9) + 7;
        long long num = 0;
        for (auto it = s.rbegin(); it != s.rend(); it++)
        {
            if (*it == '1')
            {
                num += (pow2 % MAX);
            }
            pow2 <<= 1;
            while (num >= MAX)
            {
                num -= MAX;
            }
        }
        return num;
    }
public:
    int concatenatedBinary(int n)
    {
        stringstream ss;
        for (int i = 1; i <= n; i++)
        {
            ss << numToBin(i);
        }
        return binToNum(ss.str());
    }
};

int main(int argc, char* argv[])
{
    cout << "1680-concat-consecutive-bin-num\n";
    int n, exp;
    if (argc > 2)
    {
        n = stoi(argv[1]);
        exp = stoi(argv[2]);
    }
    else
    {
        n = 3;
        exp = 27;
    }
    cout << "Input: n = " << n << ", exp = " << exp << "\n";

    Solution sol;
    int res = sol.concatenatedBinary(n);
    cout << "Output: res = " << res << "\n";
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

