#include <iostream>
#include <vector>

using namespace std;

/*
Anti-theft security devices are activated inside a bank. You are given a
0-indexed binary string array bank representing the floor plan of the bank,
which is an m x n 2D matrix. bank[i] represents the ith row, consisting of '0's
and '1's. '0' means the cell is empty, while '1' means the cell has a security
device.

There is one laser beam between any two security devices if both conditions are
met:

- The two devices are located on two different rows: r1 and r2, where r1 < r2.
- For each row i where r1 < i < r2, there are no security devices in the ith
  row.

Laser beams are independent, i.e., one beam does not interfere nor join with
another.

Return the total number of laser beams in the bank.
*/

class Solution
{
public:
    int numberOfBeams(vector<string>& bank)
    {
        int beams = 0;
        int prev = 0;
        int count;

        for (auto& row: bank)
        {
            count = 0;
            for (char& c: row)
            {
                if (c == '1')
                    count++;
            }
            beams += count * prev;

            if (count != 0)
            {
                prev = count;
            }
        }

        return beams;
    }
};

int main(int argc, char* argv[])
{
    cout << "2125-num-laser-beams-in-bank\n";

    vector<string> bank = { "011001","000000","010100","001000" };
    int exp = 8;

    cout << "Input: bank = [ ";
    for (auto& s: bank)
    {
        cout << '"' << s << "\",";
    }
    cout << " ], exp = " << exp << "\n";

    Solution sol;
    int res = sol.numberOfBeams(bank);

    cout << "Output: res = " << res << "\n";
    if (exp == res)
        cout << "Test: PASS\n";
    else
        cout << "Test: FAIL\n";

    return 0;
}

