#include <iostream>
#include <vector>

using namespace std;

/*
You are given two integer arrays nums1 and nums2. You are tasked to implement a
data structure that supports queries of two types:

- Add a positive integer to an element of a given index in the array nums2.
- Count the number of pairs `(i, j)` such that `nums1[i] + nums2[j]` equals a given
  value (`0 <= i < nums1.length` and `0 <= j < nums2.length`).

Implement the FindSumPairs class:

- `FindSumPairs(int[] nums1, int[] nums2)` Initializes the `FindSumPairs` object
  with two integer arrays `nums1` and `nums2`.
- `void add(int index, int val)` Adds val to nums2[index], i.e., apply
  nums2[index] += val.
- `int count(int tot)` Returns the number of pairs (i, j) such that nums1[i] +
  nums2[j] == tot.

*/

class FindSumPairs
{
private:
    int n1size;
    int n2size;
    vector<vector<int>> sums;
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2)
    {
        n1size = nums1.size();
        n2size = nums2.size();
        // Empty matrix to contain results
        for (int i = 0; i < nums1.size(); i++)
        {
            vector<int> v(nums2.size());
            sums.push_back(v);
        }
        // Compute all sums and store result
        for (int i = 0; i < nums1.size(); i++)
        {
            for (int j = 0; j < nums2.size(); j++)
            {
                sums[i][j] = nums1[i] + nums2[j];
            }
        }
    }

    void add(int index, int val)
    {
        // Update cached sums too
        for (int i = 0; i < n1size; i++)
        {
            sums[i][index] += val;
        }
    }

    int count(int tot)
    {
        // Count the number of pairs (i, j) such that nums1[i] + nums2[j] equals a
        // given value (0 <= i < nums1.length and 0 <= j < nums2.length).
        int c = 0;
        for (auto vec : sums)
        {
            for (auto v : vec)
            {
                if (v == tot)
                {
                    c++;
                }
            }
        }
        return c;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */

int main(int argc, char* argv[])
{
    cout << "1865-finding-pairs-with-certain-sum\n";

    // Hardcode a test case because it is too complicated to accept user input
    vector<int> n1 = {1, 1, 2, 2, 2, 3};
    vector<int> n2 = {1, 4, 5, 2, 5, 4};
    FindSumPairs fsp(n1, n2);
    fsp.count(7);
    fsp.add(3, 2);
    fsp.count(8);
    fsp.count(4);
    fsp.add(0, 1);
    fsp.add(1, 1);
    fsp.count(7);

    return 0;
}

