#include <iostream>
#include <string>

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
        // Process as a string
        // Exploit binary number represenation
        // If even (last digit is 0), divide by 2 (shift to right by 1)
        // Else add 1 (binary addition)
        int steps = 0;
        while (s.size() > 1)
        {
            unsigned long long N = s.size();
            if (s[N-1] == '0')
            {
                // Even, divide by 2
                // 110 -> 11
                s.erase(N-1, string::npos);
            }
            else
            {
                // Odd, add 1
                unsigned long long pos = s.find_last_of('0');
                if (pos == string::npos)
                {
                    // All 1s, so 1 + N 0s
                    // 111 -> 1000
                    s = '1' + string(N, '0');
                }
                else
                {
                    // Replace 0 at pos with 1
                    s[pos] = '1';
                    // Replace all 1s after pos with 0s
                    // There are N-pos-1 char. after pos
                    // 10101 -> 10110
                    // 10111 -> 11000
                    s.erase(pos+1, string::npos);
                    s.append(string(N-pos-1, '0'));
                }
            }
            steps++;
        }
        if (s != "1")
        {
            cout << "Didn't end up with a 1\n";
            return -1;
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

