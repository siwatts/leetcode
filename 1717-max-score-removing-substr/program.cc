#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

/*
You are given a string s and two integers x and y. You can perform two types of
operations any number of times.

- Remove substring "ab" and gain x points.
    - For example, when removing "ab" from "cabxbae" it becomes "cxbae".
                                             ^^
- Remove substring "ba" and gain y points.
    - For example, when removing "ba" from "cabxbae" it becomes "cabxe".
                                                ^^
Return the maximum points you can gain after applying the above operations on s.
*/

/*
 * Notes:
 * - The string is mutated by each operation and this changes which operations
 *   are possible, so it is not as simple as counting the ab and ba combinations
 *   beforehand, which are chosen and their order of application also matters
*/

class Solution
{
private:
    int processSubstring(string s, string highmatch, int highscore, string lowmatch, int lowscore)
    {
        if (s.size() < 2)
            return 0;

        int score = 0;
        // Find all instances of 'ab' and 'ba'
        int pos = s.find(highmatch);
        while (pos != string::npos)
        {
            // While loop because multiple may be needed, e.g. removing ab from aabb -> ab
            s.erase(pos, highmatch.size());
            score += highscore;
            pos = s.find(highmatch);
        }
        // It can be shown (somehow) that once all high matches are removed, only
        // low matches remain and no matter how many are removed there will never be
        // any more highmatches in the string e.g. abab, removing ba will never create
        // another ab, because we would have just removed 2x ab already
        pos = s.find(lowmatch);
        while (pos != string::npos)
        {
            s.erase(pos, lowmatch.size());
            score += lowscore;
            pos = s.find(lowmatch);
        }

        return score;
    }
public:
    int maximumGain(string s, int x, int y)
    {
        // We need to break the string into substrings and treat them individually
        // Each individual section of a/b characters may have multiple different
        // ways of removing ab/ba and it is not as simple as choosing the highest
        // scoring first, as the string is mutated which can unlocked different
        // possible continuations. So we need a recursive function. But regions
        // separated by characters other than a/b can be treated completely
        // independently as they will never interfere with each other
        // In fact we can drop other char. entirely
        stringstream ss;
        vector<string> subs;
        bool capture = false;
        for (char c : s)
        {
            if (c == 'a' || c == 'b')
            {
                ss << c;
                if (!capture)
                    capture = true;
            }
            else if (capture)
            {
                subs.push_back(ss.str());
                ss.str(string());
                ss.clear();
                capture = false;
            }
        }
        if (capture)
        {
            subs.push_back(ss.str());
        }

        string highmatch, lowmatch;
        int highscore, lowscore;
        if (x > y)
        {
            highmatch = "ab";
            highscore = x;
            lowmatch = "ba";
            lowscore = y;
        }
        else
        {
            highmatch = "ba";
            highscore = y;
            lowmatch = "ab";
            lowscore = x;
        }

        int score = 0;
        for (auto sub : subs)
        {
            score += processSubstring(sub, highmatch, highscore, lowmatch, lowscore);
        }

        return score;
    }
};

int main(int argc, char* argv[])
{
    cout << "1717-max-score-removing-substr\n";
    string s;
    int x, y;
    int exp;
    if (argc > 4)
    {
        s = argv[1];
        x = atoi(argv[2]);
        y = atoi(argv[3]);
        exp = atoi(argv[4]);
    }
    else
    {
        s = "cdbcbbaaabab";
        x = 4;
        y = 5;
        exp = 19;
    }

    Solution sol;
    int res = sol.maximumGain(s, x, y);

    cout << "Input: s = '" << s << "', x = " << x << ", y = " << y << ", exp = " << exp << "\n";
    cout << "Output: res = " << res << "\n";
    if (exp == res)
    {
        cout << "Test: PASS\n";
    }
    else
    {
        cout << "Test: FAIL\n";
    }

    return 0;
}

