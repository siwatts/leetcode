#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
Given an array of integers arr, a lucky integer is an integer that has a
frequency in the array equal to its value.

Return the largest lucky integer in the array. If there is no lucky integer
return -1.
*/

class Solution
{
public:
    int findLucky(vector<int>& arr)
    {
        sort(arr.begin(), arr.end());
        // Run backwards, counting instances of a digit
        // Exit the first time we encounter one with exactly the right count
        int val = arr.back();
        int count = 1;
        for (int i = arr.size()-2; i >= 0; i--)
        {
            if (arr[i] == val)
            {
                count++;
            }
            else
            {
                // We now know how many of the value val we counted
                if (count == val)
                {
                    // Lucky number!
                    return val;
                }
                else
                {
                    // Maybe this one will be lucky, start counting it
                    val = arr[i];
                    count = 1;
                }
            }
        }
        // Catch the edge case that the last value we checked was the required one
        if (val == count)
        {
            return val;
        }
        else
        {
            // Found no match
            return -1;
        }
    }
};

int main(int argc, char* argv[])
{
    cout << "1394-find-lucky-int-in-array\n";

    vector<int> arr;
    int exp;
    if (argc > 2)
    {
        for (int i = 1; i < argc-1; i++)
        {
            arr.push_back(atoi(argv[i]));
        }
        exp = atoi(argv[argc-1]);
    }
    else
    {
        arr = { 2,2,3,4 };
        exp = 2;
    }

    Solution sol;
    int res = sol.findLucky(arr);

    cout << "Input: arr = [";
    for (auto a : arr)
    {
        cout << a << ",";
    }
    cout << "], exp = " << exp << "\n";
    cout << "Output: res = " << res << "\n";
    if (exp == res)
        cout << "Test: PASS\n";
    else
        cout << "Test: FAIL\n";

    return 0;
}

