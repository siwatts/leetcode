#include <iostream>
#include <stack>
#include <sstream>

using namespace std;

/*
 * 12. Integer to Roman
 *
 * Seven different symbols represent Roman numerals with the following values:
 *
 *   Symbol  Value
 *   I       1
 *   V       5
 *   X       10
 *   L       50
 *   C       100
 *   D       500
 *   M       1000
 *
 * Roman numerals are formed by appending the conversions of decimal place
 * values from highest to lowest. Converting a decimal place value into a Roman
 * numeral has the following rules:
 *
 *  - If the value does not start with 4 or 9, select the symbol of the maximal
 *    value that can be subtracted from the input, append that symbol to the result,
 *    subtract its value, and convert the remainder to a Roman numeral.
 *  - If the value starts with 4 or 9 use the subtractive form representing one
 *    symbol subtracted from the following symbol, for example, 4 is 1 (I) less than
 *    5 (V): IV and 9 is 1 (I) less than 10 (X): IX. Only the following subtractive
 *    forms are used: 4 (IV), 9 (IX), 40 (XL), 90 (XC), 400 (CD) and 900 (CM).
 *  - Only powers of 10 (I, X, C, M) can be appended consecutively at most 3
 *    times to represent multiples of 10. You cannot append 5 (V), 50 (L), or 500 (D)
 *    multiple times. If you need to append a symbol 4 times use the subtractive
 *    form.
 *
 * Given an integer, convert it to a Roman numeral.
*/

class Solution
{
public:
    string digitToRoman(int digit, char one)
    {
        if (digit >= 4)
        {
            throw invalid_argument("Number out of range (0-3999)");
        }

        return digitToRoman(digit, one, '\0', '\0');
    }
    string digitToRoman(int digit, char one, char five, char ten)
    {
        stringstream ss;
        switch (digit)
        {

            case 3:
                ss << one;
            case 2:
                ss << one;
            case 1:
                ss << one;
                break;
            case 4:
                ss << one << five;
                break;
            case 5:
                ss << five;
                break;
            case 6:
                ss << five << one;
                break;
            case 7:
                ss << five << one << one;
                break;
            case 8:
                ss << five << one << one << one;
                break;
            case 9:
                ss << one << ten;
                break;
            default:
                break;
        }
        return ss.str();
    }

    string intToRoman(int num)
    {
        // Number is constructed digit by digit
        // So pull them off one by one for processing
        if (num <= 0 || num >= 4000)
        {
            //throw runtime_error("Number out of range (0-3999)");
            // out_of_range, logic_error
            throw invalid_argument("Number out of range (0-3999)");
        }
        // Strip digits 1 by 1
        stack<int> digits;
        while (num > 0)
        {
            digits.push(num % 10);
            num = (int) ( num / 10.0 );
        }
        //cout << "Pulled " << digits.size() << " digits\n";

        stringstream out;
        int powTen = digits.size() - 1; // e.g. 3 digit number the 1st is 10^2
        while (digits.size() > 0)
        {
            int d = digits.top();
            digits.pop();
            // Convert digit to Roman numeral and append to string
            switch (powTen)
            {
                case 3:
                    // Thousands
                    out << digitToRoman(d, 'M');
                    break;
                case 2:
                    // Hundreds
                    out << digitToRoman(d, 'C', 'D', 'M');
                    break;
                case 1:
                    // Tens
                    out << digitToRoman(d, 'X', 'L', 'C');
                    break;
                case 0:
                    // Ones
                    out << digitToRoman(d, 'I', 'V', 'X');
                    break;
                default:
                    break;
            }

            powTen--;
        }

        return out.str();
    }
};

int main(int argc, char* argv[])
{
    cout << "12-integer-to-roman\n";
    Solution s;
    int in;
    string exp = "";

    // User input
    if (argc > 1)
    {
        in = stoi(argv[1]);
        if (argc > 2)
        {
            exp = argv[2];
        }
    }
    else
    {
        in = 3749;
        exp = "MMMDCCXLIX";
    }

    string out = s.intToRoman(in);

    cout << "in: " << in << "\nout: " << out << "\n";
    if (exp.length() != 0)
    {
        cout << "expected: " << exp << "\n";
        if (out == exp)
        {
            cout << "test: PASS\n";
        }
        else
        {
            cout << "test: FAIL\n";
        }
    }

    return 0;
}

