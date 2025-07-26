#include <iostream>
#include <deque>

using namespace std;

/*
Given two non-negative integers num1 and num2 represented as strings, return the
product of num1 and num2, also represented as a string.

Note: You must not use any built-in BigInteger library or convert the inputs to
integer directly.
*/

class Solution
{
private:
    const char zero = '0';
public:
    string add(string num1, string num2, int powTen)
    {
        cout << "add('" << num1 << "', '" << num2 << "', " << powTen << ")\n";
        // 2nd argument raised to the power of ten provided
        // i.e. append that many 0s
        for (int i = 0; i < powTen; i++)
        {
            num2 += "0";
        }
        //
        auto it1 = num1.rbegin();
        auto it2 = num2.rbegin();
        bool carry = false;
        char d1, d2;
        deque<char> result;
        // No easy way to add to beginning of sstream, so let's use a collection
        // insert at the beginning as we go, then convert to string at the end
        while (it1 != num1.rend() && it2 != num2.rend())
        {
            if (it1 != num1.rend())
            {
                d1 = *it1;
                d1 = d1-zero;
            }
            else
            {
                d1 = 0;
            }
            if (it2 != num2.rend())
            {
                d2 = *it2;
                d2 = d2-zero;
            }
            else
            {
                d2 = 0;
            }
            d2 = d1 + d2 + (carry ? 1 : 0);
            if (d2 >= 10)
            {
                carry = true;
                d2 -= 10;
            }
            else
            {
                carry = false;
            }
            d2 = d2 + zero;
            result.push_front(d2);
            if (it1 != num1.rend())
            {
                it1++;
            }
            if (it2 != num2.rend())
            {
                it2++;
            }
        }
        if (carry)
        {
            result.push_front('1');
        }
        // Now convert it to a string
        string res = string(result.begin(), result.end());
        cout << "add() = " << res << "\n";
        return res;
    }
    string multiply(char num1, char num2)
    {
        cout << "multiply(char '" << num1 << "', char '" << num2 << "')\n";
        num1 = num1-zero;
        num2 = num2-zero;
        char res = num1 * num2;
        res += zero;
        cout << "multiply() = " << res << "\n";
        return to_string(res);
    }
    string multiply(string num1, string num2)
    {
        // To multiply 2 numbers we go digit by digit, we sum the result
        // of every digit of num1 multiplied by every digit of num2
        string result = "0";
        int i = 0, j = 0;
        auto it1 = num1.rbegin();
        auto it2 = num2.rbegin();
        while (it1 != num1.rend() && it2 != num2.rend())
        {
            result = add(result, multiply(*it1, *it2), i+j);
            if (it1 != num1.rend())
            {
                it1++;
                i++;
            }
            if (it2 != num2.rend())
            {
                it2++;
                j++;
            }
        }
        return result;
    }
};

int main(int argc, char* argv[])
{
    cout << "43-multiply-strings\n";

    string num1, num2, exp;
    if (argc > 3)
    {
        num1 = argv[1];
        num2 = argv[2];
        exp = argv[3];
    }
    else
    {
        num1 = "123";
        num2 = "456";
        exp = "56088";
    }
    Solution sol;
    string res = sol.multiply(num1, num2);

    cout << "Input: num1 = '" << num1 << "', num2 = '" << num2 << "', exp = '" << exp << "'\n";
    cout << "Output: res = '" << res << "'\n";

    return 0;
}

