#include <iostream>
#include <vector>

using namespace std;

/*
Alice has n balloons arranged on a rope. You are given a 0-indexed string colors
where colors[i] is the color of the ith balloon.

Alice wants the rope to be colorful. She does not want two consecutive balloons
to be of the same color, so she asks Bob for help. Bob can remove some balloons
from the rope to make it colorful. You are given a 0-indexed integer array
neededTime where neededTime[i] is the time (in seconds) that Bob needs to remove
the ith balloon from the rope.

Return the minimum time Bob needs to make the rope colorful.
*/

class Solution
{
public:
    int minCost(string colors, vector<int>& neededTime)
    {
        char prev = colors[0];
        int prevCost = neededTime[0];
        int totalCost = 0;
        for (unsigned int i = 1; i < colors.length(); i++)
        {
            if (prev == colors[i])
            {
                // Remove one
                totalCost += min(neededTime[i], prevCost);
                // Remember the other in case there are more than 2 in a row
                prevCost = max(neededTime[i], prevCost);
            }
            else
            {
                // Else set next loop
                prevCost = neededTime[i];
                prev = colors[i];
            }
        }

        return totalCost;
    }
};

int main(int argc, char* argv[])
{
    cout << "1578-min-time-to-make-rope-colorful\n";

    string colors = "abaac";
    vector<int> neededTime = { 1,2,3,4,5 };
    int exp = 3;

    cout << "Input: colors = '" << colors << "', neededTime = [ ";
    for (auto& t: neededTime)
    {
        cout << t << ",";
    }
    cout << " ], exp = " << exp << "\n";

    Solution sol;
    int res = sol.minCost(colors, neededTime);

    cout << "Output: res = " << res << "\n";
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

