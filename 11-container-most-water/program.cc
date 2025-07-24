#include <iostream>
#include <vector>

using namespace std;

/*
You are given an integer array height of length n. There are n vertical lines
drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the
container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.
*/

class Solution
{
public:
    int maxArea(vector<int>& height)
    {
        // We are finding the max of 2 heights, such that we maximise min(h1,h2)*(x2-x1)

        // "2 pointers", come in from the outsides instead of recursively trying
        // every combination
        int n = height.size();
        int maxVol = 0;
        int vol;
        int i = 0;
        int j = n-1;
        while (i < n && j >= 0)
        {
            vol = min(height[i], height[j]) * (j - i);
            maxVol = max(maxVol, vol);
            if (height[i] < height[j])
            {
                i++;
            }
            else
            {
                j--;
            }
        }

        return maxVol;
    }
};

int main(int argc, char* argv[])
{
    cout << "\n";

    vector<int> height;
    int exp;
    if (argc > 2)
    {
        for (int i = 1; i < argc-1; i++)
        {
            height.push_back(atoi(argv[i]));
        }
        exp = atoi(argv[argc-1]);
    }
    else
    {
        height = { 1,8,6,2,5,4,8,3,7 };
        exp = 49;
    }

    Solution sol;
    int res = sol.maxArea(height);

    cout << "Input: height = [";
    for (auto h: height)
    {
        cout << h << ",";
    }
    cout << "], exp = " << exp << "\n";
    cout << "Output: res = " << res << "\n";
    if (res == exp)
    {
        cout << "Test: PASS\n";
    }
    else
    {
        cout << "Test: FAIL\n";
    }

    return 0;
}

