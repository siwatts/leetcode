#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    return { i, j };
                }
            }
        }

        throw new runtime_error("Found no solution");
    }
};

int main(int argc, char* argv[])
{
    cout << "1-two-sum-cpp\n";

    vector<int> nums;
    int target;
    vector<int> exp = {};
    if (argc > 2)
    {
        // 1->argc-2, nums
        // argc-1, target
        for (int i = 1; i < argc-1; i++)
        {
            nums.push_back(stoi(argv[i]));
        }
        target = stoi(argv[argc-1]);
    }
    else
    {
        nums = {3,2,4};
        target = 6;
        exp = {1,2};
    }
    cout << "Input: nums = [ ";
    for (auto n: nums)
    {
        cout << n << ",";
    }
    cout << " ], target = " << target << ", exp = [ ";
    for (auto e : exp)
    {
        cout << e << ",";
    }
    cout << " ]\n";

    Solution sol;
    vector<int> res = sol.twoSum(nums, target);

    cout << "Output: res = [ ";
    for (auto r: res)
    {
        cout << r << ",";
    }
    cout << " ]\n";

    return 0;
}

