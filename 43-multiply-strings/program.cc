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
        //cout << "DEBUG: add(string '" << num1 << "', string '" << num2 << "', int " << powTen << ")\n";
        // 2nd argument raised to the power of ten provided
        // i.e. append that many 0s
        for (int i = 0; i < powTen; i++)
        {
            num2 += "0";
        }
        //cout << "DEBUG add(: num1 = '" << num1 << "', num2 = '" << num2 << "'\n";
        //
        int i = num1.length() - 1;
        int j = num2.length() - 1;
        bool carry = false;
        char d1, d2;
        deque<char> result;
        // No easy way to add to beginning of sstream, so let's use a collection
        // insert at the beginning as we go, then convert to string at the end
        while (i != -1 || j != -1)
        {
            //cout << "DEBUG add(: while\n";
            if (i != -1)
            {
                d1 = num1[i];
                d1 = d1-zero;
            }
            else
            {
                d1 = 0;
            }
            if (j != -1)
            {
                d2 = num2[j];
                d2 = d2-zero;
            }
            else
            {
                d2 = 0;
            }
            //cout << "DEBUG add(: (int)d1 = " << (int)d1 << ", (int)d2 = " << (int)d2 << "\n";
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
            //cout << "DEBUG add(: (int)d2 = " << (int)d2 << ", carry = " << (carry ? "True" : "False") << "\n";
            d2 = d2 + zero;
            //cout << "DEBUG add(: d2 = '" << d2 << "'\n";
            result.push_front(d2);
            //cout << "DEBUG add(: result = [";
            //for (auto d : result)
            //{
            //    cout << d << ",";
            //}
            //cout << "]\n";
            if (i != -1)
            {
                i--;
            }
            if (j != -1)
            {
                j--;
            }
        }
        if (carry)
        {
            result.push_front('1');
        }
        // Now convert it to a string
        string res = string(result.begin(), result.end());
        //cout << "DEBUG add(: result = '" << res << "'\n";
        return res;
    }
    string multiply(char num1, char num2)
    {
        //cout << "DEBUG: multiply(char '" << num1 << "', char '" << num2 << "')\n";
        num1 = num1-zero;
        num2 = num2-zero;
        char res = num1 * num2;
        //cout << "DEBUG: multiply() = " << (int)res << "\n";
        return to_string((int)res);
    }
    string multiply(string num1, string num2)
    {
        // To multiply 2 numbers we go digit by digit, we sum the result
        // of every digit of num1 multiplied by every digit of num2
        string result = "0";
        int N = num1.length();
        int M = num2.length();
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                result = add(result, multiply(num1[N-1-i], num2[M-1-j]), i+j);
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

