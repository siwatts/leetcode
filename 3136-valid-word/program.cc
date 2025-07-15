#include <iostream>
#include <string>
#include <algorithm> // transform
#include <cctype> // ::tolower

using namespace std;

/*
A word is considered valid if:

- It contains a minimum of 3 characters.
- It contains only digits (0-9), and English letters (uppercase and lowercase).
- It includes at least one vowel.
- It includes at least one consonant.

You are given a string word.

Return true if word is valid, otherwise, return false.
*/

class Solution
{
public:
    bool isValid(string word)
    {
        if (word.length() < 3)
            return false;

        // We don't care about case so make everything lowercase for simplicity
        // ::tolower is a C std library function from <cctype>
        transform(word.begin(), word.end(), word.begin(), ::tolower);

        // Vowels, at least one
        string v = { "aeiou" };
        int pos = word.find_first_of(v);
        if (pos == string::npos)
            return false;

        // Consonants, at least one
        string c = { "bcdfghjklmnpqrstvwxyz" };
        pos = word.find_first_of(c);
        if (pos == string::npos)
            return false;

        // Allowed characters only
        string allowed = { "0123456789abcdefghijklmnopqrstuvwxyz" };
        pos = word.find_first_not_of(allowed);
        if (pos != string::npos)
            return false;

        return true;
    }
};

int main(int argc, char* argv[])
{
    cout << "3136-valid-word\n";

    string word;
    bool exp;
    if (argc > 2)
    {
        word = argv[1];
        exp = argv[2][0] == '1';
    }
    else
    {
        word = "234Adas";
        exp = true;
    }

    Solution sol;
    bool res = sol.isValid(word);

    cout << "Input: word = '" << word << "', exp = " << (exp ? "True" : "False") << "\n";
    cout << "Output: res = " << (res ? "True" : "False") << "\n";

    return 0;
}
