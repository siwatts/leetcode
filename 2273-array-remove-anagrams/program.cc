#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<string> removeAnagrams(vector<string>& words)
    {
        int index;
        bool anagram;
        do
        {
            anagram = false;
            for (int i = 1; i < words.size(); i++)
            {
                if (words[i] == words[i-1])
                {
                    anagram = true;
                    index = i;
                    break;
                }
            }
            if (anagram)
            {
                words.erase(words.begin() + index);
            }
        }
        while (anagram);

        return words;
    }
};

int main(int argc, char* argv[])
{
    cout << "2273-array-remove-anagrams\n";

    vector<string> words;
    vector<string> exp;
    if (argc > 1)
    {
        for (int i = 1; i < argc; i++)
        {
            words.push_back(argv[i]);
        }
    }
    else
    {
        words = { "abba","baba","bbaa","cd","cd" };
        exp = { "abba","cd" };
    }

    Solution sol;
    vector<string> res = sol.removeAnagrams(words);

    if (argc > 1)
    {
        bool correct = false;
        if (exp.size() == res.size())
        {
            correct = true;
            for (int i = 0; i < exp.size(); i++)
            {
                if (exp[i] != res[i])
                {
                    correct = false;
                }
            }
        }
        cout << "Test: " << (correct ? "PASS\n" : "FAIL\n");
    }
    cout << "Result: res = {";
    for (auto r : res)
    {
        cout << "\"" << r << "\",";
    }
    cout << "}\n";

    return 0;
}

