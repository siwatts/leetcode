#include <iostream>

using namespace std;

/*
Given the binary representation of an integer as a string s, return the number
of steps to reduce it to 1 under the following rules:

- If the current number is even, you have to divide it by 2.
- If the current number is odd, you have to add 1 to it.

It is guaranteed that you can always reach one for all test cases.
*/

class Solution
{
public:
    int numSteps(string s)
    {
        int pow2 = 1;
        int num = 0;
        for (auto it = s.rbegin(); it != s.rend(); it++)
        {
            if (*it == '1')
                num += pow2;
            pow2 <<= 1;
        }

        int steps = 0;
        while (num > 1)
        {
            if (num % 2 == 0)
            {
                num /= 2;
            }
            else
            {
                num++;
            }
            steps++;
        }

        return steps;
    }
};

int main(int argc, char* argv[])
{
    cout << "1404-num-steps-reduce-binary-num-to-one\n";

    string s;
    int exp;
    if (argc > 2)
    {
        s = argv[1];
        exp = stoi(argv[2]);
    }
    else
    {
        s = "1101";
        exp = 6;
    }
    cout << "Input: s = '" << s << "', exp = " << exp << "\n";

    Solution sol;
    int res = sol.numSteps(s);

    cout << "Output: res = " << res << "\n";
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

