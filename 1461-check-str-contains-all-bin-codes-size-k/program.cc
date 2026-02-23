#include <iostream>
#include <vector>
#include <cmath>
#include <ranges>

using namespace std;

/*
Given a binary string s and an integer k, return true if every binary code of
length k is a substring of s. Otherwise, return false.
*/

class Solution
{
private:
    vector<string> getCodesSizeK(int k)
    {
        vector<string> c;
        // Every binary number of length k, will be the decimal numbers
        // 0 to (2^k)-1, inclusive
        for (int i : std::views::iota(0, pow(2,k)))
        {
            c.push_back(toBinary(i, k));
        }
        return c;
    }
    string toBinary(int n, int k)
    {
        string s(k, '0');
        // String may be backwards but that doesn't matter
        for (int i = 0; i < k; i++)
        {
            if (n & 1)
            {
                s[i] = '1';
            }
            n = n >> 1;
        }
        return s;
    }
public:
    bool hasAllCodes(string s, int k)
    {
        if (k > s.size())
            return false;

        vector<string> codes = getCodesSizeK(k);
        int pos;
        for (auto& c: codes)
        {
            pos = s.find(c);
            if (pos == string::npos)
                return false;
        }
        return true;
    }
};

int main(int argc, char *argv[])
{
    cout << "1461-check-str-contains-all-bin-codes-size-k\n";

    string s;
    int k;
    bool exp;
    if (argc > 3)
    {
        s = argv[1];
        k = stoi(argv[2]);
        exp = stoi(argv[3]) == 1;
    }
    else
    {
        s = "00110110";
        k = 2;
        exp = true;
    }
    cout << "Input: s = '" << s << "', k = " << k << ", exp = " << (exp ? "True" : "False") << "\n";

    Solution sol;
    bool res = sol.hasAllCodes(s, k);

    cout << "Output: res = " << (res ? "True" : "False") << "\n";
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

