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
        vector<int> out = { num };
        // TODO: Would it be faster to replace digits numerically? Powers of ten and modulo
        string numstring = to_string(num);
        string replacestring;
        for (int i = 0; i < 10; i++)
        {
            char a = to_string(i)[0];
            if (numstring.find(a) == string::npos)
            {
                cout << "Skip, no " << a << " digit found\n";
                continue;
            }
            for (int j = 0; j < 10; j++)
            {
                if (i == j)
                {
                    cout << "Skip case " << i << " -> " << j << "\n";
                    continue;
                }
                cout << "Testing " << i << " -> " << j << "\n";
                char b = to_string(j)[0];
                replacestring = numstring;
                replace(replacestring.begin(), replacestring.end(), a, b);
                cout << "Results: " << numstring << " -> " << replacestring;
                int replace = stoi(replacestring);
                cout << ", int: " << replace << "\n";
                out.push_back(replace);
            }
        }
        int min = *min_element(out.begin(), out.end());
        int max = *max_element(out.begin(), out.end());
        cout << "min: " << min << ", max: " << max << "\n";

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

