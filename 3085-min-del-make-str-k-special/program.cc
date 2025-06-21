#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

/*
You are given a string word and an integer k.

We consider word to be k-special if |freq(word[i]) - freq(word[j])| <= k for all
indices i and j in the string.

Here, freq(x) denotes the of the character x in word, and |y| denotes the
absolute value of y.

Return the minimum number of characters you need to delete to make word
k-special.
*/

class Solution
{
    // Original
    string originalWord;
    int k;
    // Dynamic
    //string word;
    queue<long> charCountsQueue;
    unordered_map<long,long> charCountFreq;

public:
    // Return the baseline min deletions required that can be achieved without
    // fully deleting an entire char entirely
    long minimumDeletionsNoCharRemove()
    {
        //cout << "Called 'long minimumDeletionsNoCharRemove()'\n";
        long min = charCountsQueue.front();

        //cout << "this min = " << min << "\n";
        // Whatever the min char. count is, is what we need every char to be
        // Within a tolerance of k
        long remove = 0;
        for (auto& [n, f] : charCountFreq)
        {
            long sub = max<long>(f * (n - min - k), 0);
            remove += sub;
        }
        return remove;
    }
    int minimumDeletions(string word, int k)
    {
        this->originalWord = word;
        this->k = k;
        // Build the char count map, so we can ignore the string from now on
        unordered_map<char,long> charCount;
        vector<long> charCounts;
        //cout << "Count char...\n";
        for (auto& c : word)
        {
            charCount[c]++;
        }
        //cout << "Count char freq...\n";
        for (auto& [c,n] : charCount)
        {
            charCounts.push_back(n);
            charCountFreq[n]++;
        }
        //cout << "Unique charcounts...\n";
        charCounts.erase( unique( charCounts.begin(), charCounts.end() ), charCounts.end() );
        //cout << "Sort charcounts...\n";
        sort( charCounts.begin(), charCounts.end() );
        //cout << "Push charcounts...\n";
        for (long i : charCounts)
        {
            charCountsQueue.push(i);
        }

        // Get a baseline
        long min = minimumDeletionsNoCharRemove();

        long charRemovalCost {0};
        // Should we iterate?
        long smallestCount;
        long thisScore;
        while (charCountsQueue.size() > 0 && charCountsQueue.front() < min)
        {
            // There may be a better solution we can find via brute force
            //cout << "smallestCharCount = " << smallestCharCount << " < min = " << min << "\n";
            //cout << "  Trying removal of smallest char = '" << smallestChar << "'\n";

            // Remove the chars which occurs the fewest times and try again
            smallestCount = charCountsQueue.front();
            charCountsQueue.pop();
            charRemovalCost += smallestCount * charCountFreq[smallestCount];
            charCountFreq.erase(smallestCount);
            // Keep a cumulative score that persists outside the loop
            // otherwise we forget the pre-baked in cost of prior char removals

            // Iterate next cost to see if it is better
            // This method has side effects to the class properties. Make this more clear?
            // Look at this one individually
            thisScore = charRemovalCost + minimumDeletionsNoCharRemove();
            //cout << "Combined score after removal of smallest char now = " << thisScore << "\n";

            // Only keep the new one if it is better!
            min = min < thisScore ? min : thisScore;
            //cout << "new min = " << min << "\n";
        }
        //cout << "While loop terminated because next smallestCharCount = " << smallestCharCount << "\n";
        //cout << "So best min we've seen is min = " << min << "\n";

        return min;
    }
};

int main(int argc, char* argv[])
{
    cout << "3085-min-del-make-str-k-special\n";
    cout << "   ./a.out [word] [k] [expected-answer]\n";

    string word;
    int k;
    int exp;
    if (argc > 3)
    {
        word = argv[1];
        k = atoi(argv[2]);
        exp = atoi(argv[3]);
    }
    else
    {
        word = "aabcaba";
        k = 0;
        exp = 3;
    }
    cout << "In: word = '" << word << "', k = " << k << "\n";

    Solution sol;
    int res = sol.minimumDeletions(word, k);

    cout << "Out: " << res << "\n";
    cout << "Expected: " << exp << "\n";
    if (res == exp)
    {
        cout << "Test: PASS /\n";
    }
    else
    {
        cout << "Test: FAIL X\n";
    }

    return 0;
}

