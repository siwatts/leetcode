#include <iostream>
#include <vector>
#include <unordered_map>

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
                if (words[i].length() == words[i-1].length())
                {
                    // Check for anagram when length matches
                    unordered_map<char,int> char1;
                    for (char c : words[i])
                    {
                        char1[c]++;
                    }
                    unordered_map<char,int> char2;
                    for (char c : words[i-1])
                    {
                        char2[c]++;
                    }
                    if (char1.size() == char2.size())
                    {
                        anagram = true;
                        for (const auto& [c,n] : char1)
                        {
                            if (n != char2[c])
                                anagram = false;
                        }
                        if (anagram)
                        {
                            index = i;
                            break;
                        }
                    }
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

