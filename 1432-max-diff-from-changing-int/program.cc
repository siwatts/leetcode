#include <iostream>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int maxDiff(int num)
    {
        // Find max difference from substituting digit x -> y independently twice
        // to generate two numbers a, b where diff is a - b
        // Constraints:
        //     - There CANNOT be a leading 0 in a, b
        //     - a, b cannot be 0
        //     - digit can substitute to itself ie. x==y
        //
        // So:
        //     - Get a from substituting leading digit with 9
        //         - Unless it is already a 9, in which case the next non-9 digit to 9
        //         - e.g. 8777 we should do 8->9, 9777
        //         - but 9777 we should do 7->9, 9999
        //         - if there are no other digits than 9s, do nothing (i.e. 9->9)
        //     - Get b from substituting leading digit with 1
        //         - Unless it is already a 1, then the next non-1 (AND non-0!) digit to 0 (not 1 this time!)
        //         - If we blindly do the next digit, it may also be a 1, so we'd produce
        //           an illegal b with leading 0
        //         - e.g. 1199 -> 1100 (9->0)
        //         - if there are no other digits than 1s, do nothing (i.e. 1->1)

        // String method
        string s;
        char x, y;
        int a, b;

        // Max (i.e. a)
        s = to_string(num);
        auto pos = s.find_first_not_of('9');
        if (pos != string::npos)
        {
            x = s[pos];
            y = '9';
            replace(s.begin(), s.end(), x, y);
            a = stoi(s);
        }
        else
        {
            a = num;
        }

        // Min (i.e. b)
        s = to_string(num);
        pos = s.find_first_not_of("01");
        if (pos != string::npos)
        {
            x = s[pos];
            if (pos == 0)
            {
                // No leading 0s
                y = '1';
            }
            else
            {
                y = '0';
            }
            replace(s.begin(), s.end(), x, y);
            b = stoi(s);
        }
        else
        {
            b = num;
        }

        return a - b;
    }
};

int main(int argc, char* argv[])
{
    cout << "1432-max-diff-from-changing-int\n";
    int in;
    int exp;
    if (argc > 1)
    {
        cout << "Taking user input\n";
        in = stoi(argv[1]);
        if (argc > 2)
        {
            exp = stoi(argv[2]);
        }
        else
        {
            exp = -999;
        }
    }
    else
    {
        in = 555;
        exp = 888;
    }

    Solution sol;
    int out = sol.maxDiff(in);

    cout << "In: " << in << "\nOut: " << out << "\n";
    if (exp != -999)
    {
        cout << "Expected: " << exp << "\n";
        if (out == exp)
            cout << "PASS\n";
        else
            cout << "FAIL\n";
    }

    return 0;
}

