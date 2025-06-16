#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int maximumDifference(vector<int>& nums)
    {
        int n = nums.size();
        int diff = -1;
        int thisdiff;
        int minSoFar;

        for (int i = 0; i < n-1; i++)
        {
            if (i == 0 || nums[i] < minSoFar)
            {
                minSoFar = nums[i];
            }
            else
            {
                // Can skip this num[i] check as we've already tested a smaller num[i] against this num[j]
                continue;
            }
            for (int j = i+1; j < n; j++)
            {
                thisdiff = nums[j] - nums[i];
                if (thisdiff > 0 && thisdiff > diff)
                {
                    diff = thisdiff;
                }
            }
        }

        return diff;
    }
};

int main(int argc, char* argv[])
{
    cout << "2016-max-diff-increasing-elements\n";

    int n;
    vector<int> nums;
    int exp;
    if (argc > 1)
    {
        // Last user arg = expected answer
        n = argc - 2;
        for (int i = 0; i < n; i++)
        {
            // Shift by 1, 1st arg is program name
            nums.push_back(atoi(argv[i+1]));
        }
        // Last user arg = expected answer
        exp = atoi(argv[argc-1]);
    }
    else
    {
        nums = { 7, 1, 5, 4 };
        n = nums.size();
        exp = 4;
    }

    Solution sol;
    int result = sol.maximumDifference(nums);

    cout << "nums = [";
    for (auto x : nums)
    {
        cout << x << ",";
    }
    cout << "]\n";
    cout << "n = " << n << "\n";
    cout << "expected answer = " << exp << "\n";
    cout << "actual answer = " << result << "\n";
    if (result == exp)
    {
        cout << "Test case: PASS\n";
    }
    else
    {
        cout << "Test case: FAIL\n";
    }

    return 0;
}

