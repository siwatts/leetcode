#include <iostream>
#include <unordered_map>

using namespace std;

/*
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and
M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000

For example, 2 is written as II in Roman numeral, just two ones added together.
12 is written as XII, which is simply X + II. The number 27 is written as XXVII,
which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right.
However, the numeral for four is not IIII. Instead, the number four is written
as IV. Because the one is before the five we subtract it making four. The same
principle applies to the number nine, which is written as IX. There are six
instances where subtraction is used:

- I can be placed before V (5) and X (10) to make 4 and 9.
- X can be placed before L (50) and C (100) to make 40 and 90.
- C can be placed before D (500) and M (1000) to make 400 and 900.

Given a roman numeral, convert it to an integer.
*/

class Solution
{
private:
    unordered_map<char,int> values = {
        { 'I', 1 },
        { 'V', 5 },
        { 'X', 10 },
        { 'L', 50 },
        { 'C', 100 },
        { 'D', 500 },
        { 'M', 1000 },
    };
public:
    int romanToInt(string s)
    {
        int len = s.size();
        int sum = 0;
        int current, next;
        for (int i = len-1; i >= 0; i--)
        {
            current = values[s[i]];
            // If next value is smaller (ie. earlier in the number), we subtract it from this
            // char we're working on before proceeding and skipping it
            if (i > 0)
            {
                next = values[s[i-1]];
                if (next < current)
                {
                    current -= next;
                    i--;
                }
            }
            sum += current;
        }

        return sum;
    }
};

int main(int argc, char* argv[])
{
    cout << "13-roman-to-int\n";

    string in;
    int exp;
    if (argc > 2)
    {
        in = argv[1];
        exp = stoi(argv[2]);
    }
    else
    {
        in = "MCMXCIV";
        exp = 1994;
    }
    cout << "Input: in = '" << in << "', exp = " << exp << "\n";

    Solution sol;
    int res = sol.romanToInt(in);
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

