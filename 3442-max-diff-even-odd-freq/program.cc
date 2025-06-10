#include <iostream>
#include <unordered_map>
using namespace std;

/*
You are given a string s consisting of lowercase English letters.

Your task is to find the maximum difference diff = freq(a1) - freq(a2) between the frequency of characters a1 and a2 in the string such that:

    a1 has an odd frequency in the string.
    a2 has an even frequency in the string.

Return this maximum difference.
*/

class Solution
{
public:
    static int maxDifference(string s)
    {
        cout << "Given test string '" << s << "'" << endl;

        // Count letters with dictionary (hashmap)
        unordered_map<char, int> letters;

        for (int i = 0; i < s.length(); i++)
        {
            char c = s[i];
            if (letters.find(c) == letters.end())
            {
                // No entry for this char yet
                letters.insert({c,1});
            }
            else
            {
                // Increment the count
                letters[c] += 1;
            }
        }

        pair<char,int> maxOdd {'\0', 0};
        pair<char,int> maxEven {'\0', 0};

        // Fancy new iterator looping
        for (auto& it: letters)
        {
            // Log each letter keeping the highest count we've seen so far
            char c = it.first;
            int n = it.second;
            if (n % 2 == 0)
            {
                if (maxEven.second < n)
                {
                    maxEven = {c, n};
                }
            }
            else
            {
                if (maxOdd.second < n)
                {
                    maxOdd = {c, n};
                }
            }
        }

        cout << "The highest even freq. char. count we found was for char '" << maxEven.first << "' freq. " << maxEven.second << endl;
        cout << "The highest odd freq. char. count we found was for char '" << maxOdd.first << "' freq. " << maxOdd.second << endl;

        return abs(maxEven.second - maxOdd.second);
    }
};

int main(int argc, char* argv[])
{
    cout << "3442 - Maximum Difference Between Even and Odd Frequency I\n";

    // Test string
    string s = "aaaaabbc";
    // a1 = 5 ('a')
    // a2 = 2 ('b')
    // Difference = 3

    // User supplied
    if (argc > 1)
    {
        // User override test string
        string temp(argv[1]);
        s = temp;
    }

    int res = Solution::maxDifference(s);
    cout << "Freq. diff: " << res << endl;

    return 0;
}

