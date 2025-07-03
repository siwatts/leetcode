#include <iostream>
#include <sstream>

using namespace std;

class Solution
{
public:
    string forever(string word)
    {
        stringstream next;
        next << word;
        for (char c : word)
        {
            if (c == 'z')
                next << 'a';
            else
                next << (char)(c+1);
        }
        return next.str();
    }
    char kthCharacter(int k)
    {
        string word = "a";

        // Generate new string by appending next char in alphabet to word
        // for *every* char in the word at once, repeat
        // until we hit at least length k, return kth char
        // Wrap around from z -> a
        while (word.length() < k)
        {
            word = forever(word);
        }

        return word[k-1];
    }
};

int main(int argc, char* argv[])
{
    cout << "3304-find-kth-char-str-game-I\n";

    int k;
    string exp;
    if (argc > 2)
    {
        k = atoi(argv[1]);
        exp = argv[2];
    }
    else
    {
        k = 5;
        exp = "b";
    }
    cout << "Input: k = " << k << "\n";
    Solution sol;
    char res = sol.kthCharacter(k);
    cout << "Output: '" << res << "'\n";

    if (exp[0] == res)
    {
        cout << "Test: PASS\n";
    }
    else
    {
        cout << "Test: FAIL\n";
    }

    return 0;

}

