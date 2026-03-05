#include <iostream>

using namespace std;

/*
You are given a string s consisting only of the characters '0' and '1'. In one
operation, you can change any '0' to '1' or vice versa.

The string is called alternating if no two adjacent characters are equal. For
example, the string "010" is alternating, while the string "0100" is not.

Return the minimum number of operations needed to make s alternating.
*/

class Solution
{
public:
    int minOperations(string s)
    {
        int diffA = 0;
        for (size_t i = 0; i < s.size(); i++)
        {
            // Count the differences between string s and two candidate strings
            // string A starting "01010...", and B starting "10101..."
            // B is just the inverse of A ie. strlen - diffA
            char expected;
            if (i % 2 == 0)
            {
                expected = '0';
            }
            else
            {
                expected = '1';
            }
            if (s[i] != expected)
            {
                diffA++;
            }
        }
        int diffB = s.size() - diffA;

        return min(diffA, diffB);
    }
};

int main(int argc, char *argv[])
{
    cout << "1758-min-changes-to-make-alternating-bin-string\n";

    string s;
    int exp;
    if (argc > 2)
    {
        s = argv[1];
        exp = stoi(argv[2]);
    }
    else
    {
        s = "0100";
        exp = 1;
    }
    cout << "Input: s = '" << s << "', exp = " << exp << "\n";

    Solution sol;
    int res = sol.minOperations(s);

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

