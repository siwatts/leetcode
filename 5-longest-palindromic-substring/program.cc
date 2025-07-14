#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        // Seed solution with the first char.
        string res;
        int len = 1;
        int a = 0;
        int b = 0;
        // Try for a better one, around central char. at i
        for (int i = 1; i < s.length(); i++)
        {
            int newA = i-1;
            int newB = i+1;
            int newLen = newB-newA+1;
            while (newA >= 0 && newB < s.length() && s[newA] == s[newB])
            {
                if (newLen > len)
                {
                    a = newA;
                    b = newB;
                    len = newLen;
                }
                newA--;
                newB++;
                newLen += 2;
            }
        }
        // Make a second pass, with no central char. (i.e. cbbd -> bb)
        for (int i = 1; i < s.length(); i++)
        {
            int newA = i-1;
            int newB = i;
            int newLen = newB-newA+1;
            while (newA >= 0 && newB < s.length() && s[newA] == s[newB])
            {
                if (newLen > len)
                {
                    a = newA;
                    b = newB;
                    len = newLen;
                }
                newA--;
                newB++;
                newLen += 2;
            }
        }
        res = s.substr(a, len);
        return res;
    }
};

int main(int argc, char* argv[])
{
    cout << "5-longest-palindromic-substring\n";

    string in = "cbbd";
    string exp = "bb";

    Solution sol;
    string res = sol.longestPalindrome(in);

    cout << "Input: s = '" << in << "', exp = '" << exp << "'\n";
    cout << "Output: res = '" << res << "'\n";
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
