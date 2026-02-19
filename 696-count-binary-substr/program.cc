#include <iostream>
#include <vector>

using namespace std;

/*
Given a binary string s, return the number of non-empty substrings that have the
same number of 0's and 1's, and all the 0's and all the 1's in these substrings
are grouped consecutively.

Substrings that occur multiple times are counted the number of times they occur.
*/

class Solution
{
public:
    int countBinarySubstrings(string s)
    {
        // Keep the last seen consecutive 0, and consecutive 1 counts
        // We then count every equal combination, e.g. 000111 -> 3,3 so
        // we count 3, 2, and 1 (corresponding to 000111, 0011, 01)
        if (s.size() < 2)
        {
            // Need at least 2 elements to have any pairs and start our for loop
            return 0;
        }
        vector<pair<int,int>> consec;
        int consecZeroes = 0;
        bool zero;
        int consecOnes = 0;
        if (s[0] == '0')
        {
            consecZeroes = 1;
            zero = true;
        }
        else
        {
            consecOnes = 1;
            zero = false;
        }
        for (auto it = s.begin()+1; it != s.end(); it++)
        {
            char c = *it;
            if (c == '0')
            {
                if (zero)
                {
                    consecZeroes++;
                }
                else
                {
                    // Flipped back to 0, store and reset
                    consec.push_back({consecZeroes,consecOnes});
                    consecZeroes = 1;
                    zero = true;
                }
            }
            else // c == '1'
            {
                if (!zero)
                {
                    consecOnes++;
                }
                else
                {
                    // Flipped back to 1, store and reset
                    consec.push_back({consecZeroes, consecOnes});
                    consecOnes = 1;
                    zero = false;
                }
            }
        }
        // Run out of char. to compare but still have to store the last pairing
        consec.push_back({consecZeroes, consecOnes});

        // Iterate pair counts we found, add min of the two elements
        // e.g. 0,4 add 0, 3,4 add 3 (3,3 2,2 1,1)
        int count = 0;
        for (auto& p: consec)
        {
            count += min(p.first, p.second);
        }

        return count;
    }
};

int main(int argc, char *argv[])
{
    cout << "696-count-binary-substr\n";

    string s;
    int exp;
    if (argc > 2)
    {
        s = argv[1];
        exp = stoi(argv[2]);
    }
    else
    {
        s = "00110011";
        exp = 6;
    }
    cout << "Input: s = '" << s << "', exp = " << exp << "\n";

    Solution sol;
    int res = sol.countBinarySubstrings(s);
    cout << "Output: res = " << res << "\n";
    if (exp == res)
        cout << "Test: PASS\n";
    else
        cout << "Test: FAIL\n";

    return 0;
}

