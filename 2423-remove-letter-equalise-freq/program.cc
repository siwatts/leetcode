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

        // Need at least 2 different char
        if (charFrequency.size() < 2)
        {
            return false;
        }

        // 2+ elements, so we require 1 count to be 1 higher than all the others which are the same
        // OR we require 3 elements to be 1 e.g. 'abc' where any 1 can be removed
        unordered_map<int,int> countFrequency;
        for (auto &[c, n] : charFrequency)
        {
            countFrequency[n]++;
        }

        // Now we have map of countFrequency, ie. how many times that character count has occurred
        // We want to see 2 entries, a count with frequency of 2+, and a count 1 higher with frequency of 1
        // OR we require 1 entry, a count of 1 with a freq. of 3 (the special case mentioned above 'abc')
        if (countFrequency.size() == 1)
        {
            return countFrequency[1] == 3;
        }
        else if (countFrequency.size() != 2)
        {
            return false;
        }
        vector<int> counts;
        for (auto &[count, freq] : countFrequency)
        {
            counts.push_back(count);
        }
        int lowCount = min(counts[0], counts[1]);
        int highCount = max(counts[0], counts[1]);
        if (highCount - lowCount != 1)
        {
            return false;
        }
        else if (countFrequency[highCount] != 1)
        {
            return false;
        }
        else if (countFrequency[lowCount] < 2)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
};

int main(int argc, char* argv[])
{
    cout << "2423-remove-letter-equalise-freq\n";

    Solution sol;
    bool result = sol.equalFrequency("test");
    cout << "Input: 'test'\n";
    if (result)
        cout << "True\n";
    else
        cout << "False\n";
    result = sol.equalFrequency("abcc");
    cout << "Input: 'abcc'\n";
    if (result)
        cout << "True\n";
    else
        cout << "False\n";

    return 0;
}

