#include <iostream>

using namespace std;

class Solution
{
public:
    int minPartitions(string n)
    {
        int max = 0;
        for (auto& c: n)
        {
            int digit = c - '0';
            if (digit > max)
            {
                max = digit;
            }
        }
        return max;
    }
};

int main(int argc, char *argv[])
{
    cout << "1689-part-into-min-num-deci-bin\n";
    string s;
    int exp;
    if (argc > 2)
    {
        s = argv[1];
        exp = stoi(argv[2]);
    }
    else
    {
        s = "82734";
        exp = 8;
    }
    cout << "Input: s = '" << s << "', exp = " << exp << "\n";

    Solution sol;
    int res = sol.minPartitions(s);

    cout << "Output: res = " << res << "\n";
    if (exp == res)
        cout << "Test: PASS\n";
    else
        cout << "Test: FAIL\n";

    return 0;
}

