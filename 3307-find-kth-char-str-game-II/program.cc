#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>

using namespace std;

class Solution
{
public:
    string operation(string word, int op)
    {
        stringstream next;
        next << word;
        switch (op)
        {
            case 0:
                // Duplicate and append word
                next << word;
                break;
            case 1:
                // "Forever" operation from 3304 part I, increment each char. then append to word
                for (char c : word)
                {
                    if (c == 'z')
                        next << 'a';
                    else
                        next << (char)(c+1);
                }
                break;
            default:
                cout << "Invalid operation code '" << op << "'\n";
                throw invalid_argument("op");
                break;
        }
        return next.str();
    }
    char kthCharacter(int k, vector<int> operations)
    {
        string word = "a";

        // n operations required to generate char k are ceil(log2(k)) = (int)log2(k)+1
        // Add +1 to make sure k is in the 1st half of the resulting string, after this
        // point all remaining operations do not affect char at k
        int n = (int)(log2(k)+1)+1;

        // Generate new string by appending next char in alphabet to word
        // for *every* char in the word at once, repeat
        // until we hit at least length k, return kth char
        // Wrap around from z -> a
        int i = 0;
        for (auto op : operations)
        {
            if (i++ == n)
                break;
            word = operation(word, op);
        }

        return word[k-1];
    }
};

int main(int argc, char* argv[])
{
    cout << "3304-find-kth-char-str-game-I\n";

    int k;
    vector<int> operations;
    string exp;
    if (argc > 3)
    {
        k = atoi(argv[1]);
        // operations from 2 to argc-2
        for (int i = 2; i < argc-2; i++)
        {
            operations.push_back(atoi(argv[i]));
        }
        exp = argv[argc-1];
    }
    else
    {
        k = 5;
        operations = { 0,0,0 };
        exp = "a";
    }
    cout << "Input: k = " << k << ", operations = [";
    for (auto o : operations)
    {
        cout << o << ",";
    }
    cout << "], exp = '" << exp << "'\n";
    Solution sol;
    char res = sol.kthCharacter(k, operations);
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

