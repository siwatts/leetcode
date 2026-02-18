#include <iostream>
#include <cmath>

using namespace std;

class Solution
{
public:
    bool hasAlternatingBits(int n)
    {
        // Get bit count of number
        int pow = ceil(log2(n));

        bool prev = (n & 1) == 1;
        n = n >> 1;
        pow--;
        while (pow > 0)
        {
            bool curr = (n & 1) == 1;
            if (prev == curr)
                return false;
            prev = curr;
            n = n >> 1;
            pow--;
        }

        return true;
    }
};

int main(int argc, char *argv[])
{
    cout << "693-binary-num-alternating-bits\n";
    int n;
    bool exp;
    if (argc > 2)
    {
        n = stoi(argv[1]);
        exp = stoi(argv[2]) == 1;
    }
    else
    {
        n = 5;
        exp = true;
    }
    cout << "Input: n = " << n << ", exp = " << (exp ? "True" : "False") << "\n";

    Solution sol;
    bool res = sol.hasAlternatingBits(n);
    cout << "Output: res = " << (res ? "True" : "False") << "\n";
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

