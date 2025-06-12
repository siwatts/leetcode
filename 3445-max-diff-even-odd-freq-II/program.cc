#include <iostream>

using namespace std;

class Solution
{
public:
    int maxDifference(string s, int k)
    {
      /*
      You are given a string s and an integer k. Your task is to find the
      maximum difference between the frequency of two characters, freq[a] - freq[b],
      in a subs of s, such that:
          - subs has a size of at least k.
          - Character a has an odd frequency in subs.
          - Character b has an even frequency in subs.
      Return the maximum difference.

      Note that subs can contain more than 2 distinct characters
      */
      return -999;
    }
};

int main(int argc, char* argv[])
{
    cout << "3445-max-diff-even-odd-freq-II\n";

    string s = "12233";
    int k = 4;
    int expected = -1;

    Solution soln;
    int result = soln.maxDifference(s, k);

    cout << "Answer: " << result << endl;
    if (result != expected)
    {
        cout << "Wrong answer, expected " << expected << endl;
    }

}

