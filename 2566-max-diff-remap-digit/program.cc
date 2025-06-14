#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

/*
You are given an integer num. You know that Bob will sneakily remap one of the 10 possible digits (0 to 9) to another digit.
Return the difference between the maximum and minimum values Bob can make by remapping exactly one digit in num.
Notes:
- When Bob remaps a digit d1 to another digit d2, Bob replaces all occurrences of d1 in num with d2.
- Bob can remap a digit to itself, in which case num does not change.
- Bob can remap different digits for obtaining minimum and maximum values respectively.
- The resulting number after remapping can contain leading zeroes.
*/

class Solution
{
public:
    int minMaxDifference(int num)
    {
        // Is there a better way than just brute force trying all 10 digits with 9 replacements each?
        // Smallest will be first non-zero digit -> 0 and largest will be first non-zero digit -> 9
        // Unless it is already a 9, in which case it will be the first digit not a 9 after any 0's -> 9
        // TODO: Would it be faster to replace digits numerically? Powers of ten and modulo
        string numString = to_string(num);
        string replaceString;
        int min;
        int max;

        auto pos = numString.find_first_not_of('0');
        if (pos == string::npos)
        {
            // We have the number 0 as input
            min = 0;
            max = 9;
        }
        else
        {
            char a = numString[pos];
            // Minimum
            replaceString = numString;
            replace(replaceString.begin(), replaceString.end(), a, '0');
            min = stoi(replaceString);
            // Maximum
            // If the first digit is already a 9, then we need to find the next digit after that which
            // is not a 9 and replace that
            // We offset the search because the next number may be a 0, but we don't want to hit any leading 0s
            if (a == '9')
            {
                pos = numString.find_first_not_of('9', pos);
                if (pos != string::npos)
                {
                    a = numString[pos];
                }
            }
            replaceString = numString;
            replace(replaceString.begin(), replaceString.end(), a, '9');
            max = stoi(replaceString);
        }

        int result = max - min;
        return result;
    }
};

int main(int argc, char* argv[])
{
    cout << "2566-max-diff-remap-digit\n";

    int num = 11891;
    int expected = 99009;

    Solution soln;
    int result = soln.minMaxDifference(num);

    cout << "Answer: " << result << endl;
    if (result != expected)
    {
        cout << "Wrong answer, expected " << expected << endl;
    }

}

