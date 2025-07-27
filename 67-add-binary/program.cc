#include <iostream>
#include <deque>

using namespace std;

/*
Given two binary strings a and b, return their sum as a binary string.
*/

class Solution
{
public:
    string addBinary(string a, string b)
    {
        deque<char> res;
        int i = 0;
        int N = a.length();
        int M = b.length();
        int carry = 0;
        int digit;
        while (i < N || i < M)
        {
            digit = carry;
            carry = 0;
            if (i < N)
                digit += a[N-1-i] - '0';
            if (i < M)
                digit += b[M-1-i] - '0';
            // Binary number so digit can be at most 1, store remainder in the carry bit
            if (digit > 1)
            {
                carry = 1;
                digit = digit % 2;
            }
            res.push_front(digit+'0');
            i++;
        }
        if (carry)
        {
            res.push_front('1');
        }

        return string(res.begin(), res.end());
    }
};

int main(int argc, char* argv[])
{
    cout << "\n";

    string a { "11" };
    string b { "1" };
    string exp { "100" };

    Solution sol;
    string res = sol.addBinary(a,b);

    cout << "Input: a = '" << a << "', b = '" << b << "', exp = '" << exp << "'\n";
    cout << "Output: res = '" << res << "'\n";
    if (exp == res )
    {
        cout << "Test: PASS\n";
    }
    else
    {
        cout << "Test: FAIL\n";
    }

    return 0;
}

