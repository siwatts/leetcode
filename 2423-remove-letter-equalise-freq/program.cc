#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

/*
You are given a 0-indexed string word, consisting of lowercase English
letters. You need to select one index and remove the letter at that index from
word so that the frequency of every letter present in word is equal.

Return true if it is possible to remove one letter so that the frequency of all
letters in word are equal, and false otherwise.

Note:
 - The frequency of a letter x is the number of times it occurs in the string.
 - You must remove exactly one letter and cannot choose to do nothing.
*/

class Solution
{
public:
    bool equalFrequency(string word)
    {
        unordered_map<char,int> charFrequency;
        for (int i = 0; i < word.length(); i++)
        {
            charFrequency[word[i]]++;
        }

        // Need at least 1 char
        if (charFrequency.size() < 1)
        {
            return false;
        }

        // Yet another special case
        if (word.length() == 2)
        {
            return true;
        }

        // 2+ elements, so we require 1 count to be 1 higher than all the others which are the same
        //      - 'aabbccc', count 2 frequency 2, count 3 frequency 1, remove the 'c'
        // OR we require 1 count to be frequency 1, and all others (2 minimum) which are the same
        //      - 'abbcc', count 1 frequency 1, count 2 frequency 2, remove the 'a'
        // OR we require 3+ elements to be frequency 1
        //      - 'abc', count 1 frequency 3, remove any of 'a' 'b' 'c'
        // OR we require 2 elements of anything
        //      - 'aa', count 2 frequency 1, remove 'a'
        unordered_map<int,int> countFrequency;
        for (auto &[c, n] : charFrequency)
        {
            countFrequency[n]++;
        }

        // Now we have map of countFrequency, ie. how many times that character count has occurred
        // We want to see
        // - 2 entries, a count with frequency of 2+, and a {count 1 higher OR count == 1} with frequency of 1
        //      - This means there's either a character with 1 more occurance than all the others which can be removed
        //      - Or a character with a single occurance which can be removed
        // - 1 entry, a count of 1 with a freq. of N > 1 (the special case mentioned above 'abc')
        //      - This means there's 2 or more different characters all of which occur once, remove any to pass
        if (countFrequency.size() == 1)
        {
            if (countFrequency[1] > 1)
            {
                // Count 1 = string of single letters, as long as this occurs more than once (freq > 1) so there is at least
                // one letter left afterwards then the string consists of char with equal freq. no matter which
                // you remove
                return true;
            }
            else
            {
                return false;
            }
        }
        else if (countFrequency.size() != 2)
        {
            return false;
        }
        // We now know we have exactly 2 different counts in our countFrequency map
        vector<int> counts;
        for (auto &[count, freq] : countFrequency)
        {
            counts.push_back(count);
        }
        int lowCount = min(counts[0], counts[1]);
        int highCount = max(counts[0], counts[1]);
        // Several edge cases to check
        if (lowCount == 1 && countFrequency[lowCount] == 1)
        {
            // The lower of the 2 counts is an occurance of 1, and it only occurs once
            // So we simply remove that one char e.g. 'aaabbbcccdddeeef', remove an 'f'
            return true;
        }

        if (highCount - lowCount == 1)
        {
            // Mix of 2 different character counts
            // If one of them (higher) only occurs once (freq 1), we can equalise by getting
            // rid of that 1
            // I.e. 10 char counts of 3 ('aaa', 'bbb', ...) and only 1 char count of 4 ('xxxx')
            // then we can remove an x
            if (countFrequency[highCount] == 1)
                return true;
        }

        return false;
    }
};

int main(int argc, char* argv[])
{
    cout << "2423-remove-letter-equalise-freq\n";
    string input = "test";
    bool exp = true;
    if (argc > 1)
    {
        input = argv[1];
        if (argc > 2)
        {
            exp = atoi(argv[2]) == 1;
        }
    }

    Solution sol;
    bool result = sol.equalFrequency(input);
    cout << "Input: '" << input << "'\n";
    cout << "Output: '" << (result ? "True" : "False") << "'\n";
    if (argc > 2)
    {
        cout << "Expected: '" << (exp ? "True" : "False") << "'\n";
        if (exp == result)
        {
            cout << "PASS\n";
        }
        else
        {
            cout << "FAIL\n";
        }
    }

    return 0;
}

