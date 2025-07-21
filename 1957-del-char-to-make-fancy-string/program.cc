#include <iostream>
#include <sstream>

using namespace std;

/*
A fancy string is a string where no three consecutive characters are equal.

Given a string s, delete the minimum possible number of characters from s to
make it fancy.

Return the final string after the deletion. It can be shown that the answer will
always be unique.
*/

class Solution
{
public:
    string makeFancyString(string s)
    {
        stringstream ss;
        // Just go char by char?
        char prev = s[0];
        ss << prev;
        char c;
        int n = 1;
        for (int i = 1; i < s.size(); i++)
        {
            c = s[i];
            if (c == prev)
            {
                n++;
            }
            else
            {
                prev = c;
                n = 1;
            }

            if (n < 3)
            {
                ss << c;
            }
        }

        return ss.str();
    }
};

int main(int argc, char* argv[])
{
    cout << "1957-del-char-to-make-fancy-string\n";

    string s;
    string exp;
    if (argc > 2)
    {
        s = argv[1];
        exp = argv[2];
    }
    else
    {
        s = "leeetcode";
        exp = "leetcode";
    }

    Solution sol;
    string res = sol.makeFancyString(s);
    cout << "Input: s = '" << s << "', exp = '" << exp << "'\n";
    cout << "Output: res = '" << res << "'\n";
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
