#include <iostream>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    // Prior solution from 3442
    int maxDifference(string s)
    {
        //cout << "Given test string '" << s << "'" << endl;

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

        pair<char,int> maxOdd {'\0', 0}; // a1
        pair<char,int> minEven {'\0', 0}; // a2

        // Fancy new iterator looping
        for (auto& it: letters)
        {
            // Log each letter keeping the best count we've seen so far
            char c = it.first;
            int n = it.second;
            if (n % 2 == 0)
            {
                // Keep smallest even (that's not the initial 0)
                if (minEven.second == 0 || minEven.second > n)
                {
                    minEven = {c, n};
                }
            }
            else
            {
                // Keep max odd
                if (maxOdd.second < n)
                {
                    maxOdd = {c, n};
                }
            }
        }

        if (maxOdd.first == '\0')
        {
            //cout << "Didn't find a char. with odd freq. occurance\n";
            return -999;
        }
        if (minEven.first == '\0')
        {
            //cout << "Didn't find a char. with even freq. occurance\n";
            return -999;
        }
        //cout << "The highest odd freq. char. count we found was for char '" << maxOdd.first << "' freq. " << maxOdd.second << endl;
        //cout << "The lowest even freq. char. count we found was for char '" << minEven.first << "' freq. " << minEven.second << endl;

        return maxOdd.second - minEven.second;
    }
    int maxDifference(string s, int k)
    {
        /*
            You are given a string s and an integer k. Your task is to find the
            maximum difference between the frequency of two characters, freq[a] - freq[b],
            in a subs of s, such that:
               - subs has a size of at least k.
               - Character a has an odd frequency in subs.
               - Character b has an even frequency in subs.
            Return the maximum difference.
            Note that subs can contain more than 2 distinct characters

            So our constraints:
            - f_a is odd
            - f_b is even
            - max possible f_a
            - min possible f_b
            - substring of at least size k

            Code naive approach and test every possible substring?
        */

        int result = -999;
        int thisresult;
        for (int len = s.length(); len >= k; len--)
        {
            // Substring length - len
            for (int start = 0; start <= ( s.length() - len ); start++)
            {
                // Substring start position - start
                thisresult = maxDifference(s.substr(start, len));
                if (thisresult > result)
                {
                    // Keep the highest one we've seen so far
                    result = thisresult;
                }
            }
        }

        return result;
    }
};

int main(int argc, char* argv[])
{
    cout << "3445-max-diff-even-odd-freq-II\n";

    string s = "1122211";
    int k = 3;
    int expected = 1;

    Solution soln;
    int result = soln.maxDifference(s, k);

    cout << "Answer: " << result << endl;
    if (result != expected)
    {
        cout << "Wrong answer, expected " << expected << endl;
    }

}

