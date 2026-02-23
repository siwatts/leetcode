#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

/*
Given a binary string s and an integer k, return true if every binary code of
length k is a substring of s. Otherwise, return false.
*/

class Solution
{
private:
    int binaryStringToInt(string s)
    {
        int exp = 0;
        int res = 0;
        for (auto it = s.rbegin(); it != s.rend(); it++)
        {
            if (*it == '1')
            {
                res += pow(2,exp);
            }
            exp++;
        }
        return res;
    }
public:
    bool hasAllCodes(string s, int k)
    {
        if (k >= s.size())
            return false;

        int N = 1 << k;
        vector<bool> found(N, false);
        // Scan string once
        for (int i = 0; i < s.size()+1-k; i++)
        {
            // Log this substring as found
            int dec = binaryStringToInt(s.substr(i, k));
            found[dec] = true;
        }
        // Are we missing any numbers
        for (int i = 0; i < N; i++)
        {
            if (!found[i])
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

