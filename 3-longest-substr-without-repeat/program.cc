#include <iostream>
#include <set>

using namespace std;

/*
Given a string s, find the length of the longest without duplicate characters.
*/

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        if (s.length() < 2)
        {
            // There is a 0 length string in the test cases...
            return s.length();
        }

        // Two pointers
        auto first = s.begin();
        auto second = s.begin() + 1;
        int len = 1;
        int maxLen = len;
        set<char> seen;
        seen.insert(*first);
        while (first != s.end() && second != s.end())
        {
            if (seen.count(*second) == 0)
            {
                seen.insert(*second);
                second++;
                len++;
                maxLen = max(maxLen, len);
            }
            else
            {
                // We have seen this char before so move left pointer
                // forwards until it is gone
                while (first != s.end() && first <= second && *first != *second)
                {
                    seen.erase(*first);
                    len--;
                    first++;
                }
                // Found it, can go past it
                first++;
                second++;
            }

        }

        return maxLen;
    }
};

int main(int argc, char* argv[])
{
    cout << "3-longest-substr-without-repeat\n";

    string s;
    int exp;
    if (argc > 2)
    {
        s = argv[1];
        exp = atoi(argv[2]);
    }
    else
    {
        s = "abcabcbb";
        exp = 3;
    }

    Solution sol;
    int res = sol.lengthOfLongestSubstring(s);

    cout << "Input: s = '" << s << "', exp = " << exp << "\n";
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

