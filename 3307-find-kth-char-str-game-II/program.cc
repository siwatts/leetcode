#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>

using namespace std;

class Solution
{
public:
    char operation(char c, int op)
    {
        switch (op)
        {
            case 0:
                // Duplicate and append word
                // Char remains unchanged
                return c;
            case 1:
                // "Forever" operation from 3304 part I, increment each char. then append to word
                if (c == 'z')
                    return 'a';
                else
                    return (char)(c+1);
            default:
                cout << "Invalid operation code '" << op << "'\n";
                throw invalid_argument("op");
                break;
        }
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
        //
        // Actually we only need to track 1 ancestor char for each operation
        // We know whether or not the operation will be applied to our char based
        // on the binary representation of k
        int i = 0;
        char c = word[0];
        for (auto op : operations)
        {
            if (i++ == n)
                break;
            // Operation only applied if the nth digit of k as a binary number is 1
            // as this shows the common ancestor char. in each operation (whether it comes from
            // the 1st or 2nd half of the string)
            if (k & (1 << i))
                c = operation(c, op);
        }

        return c;
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

