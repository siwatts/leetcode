#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k)
    {
        // since arrays are sorted, kth smallest gives k options to consider
        // e.g. k = 1
        //     [0,0]
        // k = 4:
        //     [0,3] OR [1,2] OR [2,1] OR [3,0]
        // So for the kth smallest, we loop every combination that sums to k-1
        bool first = true;
        int smallestVal;
        for (int i = 0; i < k-1; i++)
        {
            int j = (k-1) - i;
            int val = nums1[i] * nums2[j];
            if (first)
            {
                first = false;
                smallestVal = val;
            }
            else
            {
                if (val < smallestVal)
                {
                    smallestVal = val;
                }
            }
        }
        return smallestVal;
    }
};

int main(int argc, char* argv[])
{
    cout << "2040-kth-smallest-prod-two-sorted-arrays\n";

    vector<int> nums1 = { -2,-1,0,1,2 };
    vector<int> nums2 = { -3,-1,2,4,5 };
    long long k = -3;
    long long exp = -6;

    Solution sol;
    long long res = sol.kthSmallestProduct(nums1, nums2, k);

    cout << "Input: nums1 = [";
    for (auto i : nums1)
    {
        cout << i << ",";
    }
    cout << "], nums2 = [";
    for (auto i : nums2)
    {
        cout << i << ",";
    }
    cout << "], k = " << k << "\n";
    cout << "Output: exp = " << exp << ", res = " << res << "\n";
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

