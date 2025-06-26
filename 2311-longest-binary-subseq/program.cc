#include <iostream>
#include <cmath>

using namespace std;

/*
You are given a binary string s and a positive integer k.

Return the length of the longest subsequence of s that makes up a binary number
less than or equal to k.

Note:
- The subsequence can contain leading zeroes.
- The empty string is considered to be equal to 0.
- A subsequence is a string that can be derived from another string by deleting
some or no characters without changing the order of the remaining characters.
*/

class Solution
{
public:
    int longestSubsequence(string s, int k)
    {
        if (s.length() == 0)
            return 0;

        int len = 0;
        int ksub = 0;
        for (int i = s.length()-1; i >= 0; i--)
        {
            // Backwards over string
            if (s[i] == '0')
            {
                // Keep all 0s
                len++;
            }
            else if (s[i] == '1')
            {
                // In the substring we're building, this 1 adds the value
                // of 2^len.
                // E.g. len == 0, '' -> '1'
                //                       ^--- +1 (2^0)
                // E.g. len == 2, '10 -> '110'
                //                        ^----- +4 (2^2)
                if (ksub + pow(2, len) > k)
                {
                    // Taking this '1' would send us over the value of k, so don't take it
                    // But continue the loop looking for leading 0s
                    continue;
                }
                else
                {
                    // Take the 1
                    ksub += pow(2, len);
                    len++;
                }
            }

        }

        return len;
    }
};

int main(int argc, char* argv[])
{
    cout << "2311-longest-binary-subseq\n";

    string s;
    int k;
    int exp;
    if (argc > 3)
    {
        s = argv[1];
        k = atoi(argv[2]);
        exp = atoi(argv[3]);
    }
    else
    {
        s = "1001010";
        k = 5;
        exp = 5;
    }

    Solution sol;
    int res = sol.longestSubsequence(s, k);

    cout << "Input: s = '" << s << "', k = " << k << ", exp = " << exp << "\n";
    cout << "Output: res = " << res << "\n";
    if (exp == res)
        cout << "Test: PASS\n";
    else
        cout << "Test: FAIL\n";

    return 0;
}

