#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
You are given an integer array target. You have an integer array initial of the
same size as target with all elements initially zeros.

In one operation you can choose any subarray from initial and increment each
value by one.

Return the minimum number of operations to form a target array from initial.

The test cases are generated so that the answer fits in a 32-bit integer.
*/

class Solution
{
public:
    int minNumberOperations(vector<int>& target)
    {
        // While target.contains(x => x > 0)
        // then: +1 for every continuous region of non-zero elements we find
        //       then decrease their values by 1
        // E.g. [0,1,2,1,0,1,1]
        //      [0,0,1,0,0,0,0] +2
        //      [0,0,0,0,0,0,0] +1
        //      3 total

        // Recursive method call, break into subarrays until we get a number back
        // Firstly if there are no non-zero elements, we can add the minimum
        // element value onto the result and reduce all elements accordingly
        // E.g. 2,3,4,3,4 we can +2 and recursively call on 0,1,2,1,2

        // Actually don't need this
        // It's caught by the min element and the zeros checks
        // But good for clarity
        if (target.size() == 1)
        {
            return target[0];
        }

        // Strip leading and trailing 0s
        int start = 0;
        while (start < target.size() && target[start] == 0)
        {
            start++;
        }
        if (start == target.size())
        {
            // We have only 0s
            return 0;
        }
        int end = target.size() - 1;
        while (end >= 0 && target[end] == 0)
        {
            end--;
        }
        // We already checked for all 0s
        // They could be the same element instead
        if (start == end)
        {
            // One non-zero element
            return target[start];
        }
        // Call recursively on subarray if we have leading 0s
        if (start != 0 || end != target.size() - 1)
        {
            vector<int> subarray(target.begin() + start, target.begin() + end + 1);
            return minNumberOperations(subarray);
        }

        // From this point on we know we have no leading or trailing 0s

        // Find minimum element
        int min = *min_element(target.begin(), target.end());
        if (min > 0)
        {
            // Non-zero so we can add that to the count and reduce each value accordingly
            for (int i = 0; i < target.size(); i++)
            {
                target[i] -= min;
            }
            return min + minNumberOperations(target);
        }

        // Otherwise we must remove and split on the zeros
        // Just find the first 0 and split on that, the rest will be handled recursively
        int i = 0;
        while (target[i] != 0 && i < target.size())
        {
            i++;
        }
        if (i == target.size())
        {
            throw runtime_error("Didn't find a 0 when expected");
        }

        vector<int> t1(target.begin(), target.begin()+i);
        vector<int> t2(target.begin()+i+1, target.end());

        return minNumberOperations(t1) + minNumberOperations(t2);
    }
};

int main(int argc, char* argv[])
{
    cout << "1526-min-num-incr-on-subarr-to-form-target\n";

    vector<int> target;
    int exp;
    if (argc > 3)
    {
        for (int i = 1; i < argc-1; i++)
        {
            target.push_back(stoi(argv[i]));
        }
        exp = stoi(argv[argc-1]);
    }
    else
    {
        target = { 1,2,3,2,1 };
        exp = 3;
    }

    cout << "Input: target = [";
    for (auto& t : target)
    {
        cout << t << ",";
    }
    cout << "], exp = " << exp << "\n";

    Solution sol;
    int res = sol.minNumberOperations(target);

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

