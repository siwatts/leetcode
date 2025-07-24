#include <iostream>

using namespace std;

/*
Given an integer x, return true if x is a palindrome, and false otherwise.
*/

class Solution
{
public:
    bool isPalindrome(int x)
    {
        // Negative sign automatically means no palindrome
        if (x < 0)
            return false;

        // We can either convert to string, or strip digits one by one
        // Can we reverse the number mathematically to compare that way without
        // stripping individual digits?
        const int before = x;
        long long after = 0;
        int digit;
        while (x > 0)
        {
            digit = x % 10;
            x /= 10;
            after *= 10;
            after += digit;
        }

        return before == after;
    }
};

int main(int argc, char* argv[])
{
    cout << "9-palindrome-num\n";

    int x;
    bool exp;
    if (argc > 2)
    {
        x = atoi(argv[1]);
        exp = atoi(argv[2]) == 1 ? true : false;
    }
    else
    {
        x = 121;
        exp = true;
    }

    Solution sol;
    bool res = sol.isPalindrome(x);

    cout << "Input: x = " << x << ", exp = " << (exp ? "True" : "False") << "\n";
    cout << "Output: res = " << (res ? "True" : "False") << "\n";
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

