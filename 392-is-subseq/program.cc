#include <iostream>

using namespace std;

/*
Given two strings s and t, return true if s is a subsequence of t, or false
otherwise.

A subsequence of a string is a new string that is formed from the original
string by deleting some (can be none) of the characters without disturbing the
relative positions of the remaining characters. (i.e., "ace" is a subsequence of
"abcde" while "aec" is not).
*/

class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        int pos = 0;
        for (char c : s)
        {
            //if (pos == t.length())
            //    return false;
            pos = t.find_first_of(c, pos);
            if (pos == string::npos)
                return false;
            else
                pos++;
        }

        return true;
    }
};

int main(int argc, char* argv[])
{
    cout << "392-is-subseq\n";

    string s { "abc" };
    string t { "ahbgdc" };
    bool exp { true };

    Solution sol;
    bool res = sol.isSubsequence(s, t);

    cout << "Input: s = '" << s << "', t = '" << t << "', exp = " << (exp ? "True" : "False") << "\n";
    cout << "Output: res = " << (res ? "True" : "False") << "\n";


    return 0;
}
