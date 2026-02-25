#include <iostream>
#include <vector>
#include <ranges>
#include <algorithm>

using namespace std;

/*
You are given an integer array arr. Sort the integers in the array in ascending
order by the number of 1's in their binary representation and in case of two or
more integers have the same number of 1's you have to sort them in ascending
order.

Return the array after sorting it.
*/

class Record
{
private:
    int getBitCount(int a)
    {
        int n = 0;
        while (a > 0)
        {
            if (a & 1)
                n++;
            a >>= 1;
        }
        return n;
    }
public:
    int val;
    int bitCount;
    Record(int val) : val(val), bitCount(getBitCount(val))
    {
    }
    bool operator < (const Record& right) const
    {
        if (bitCount != right.bitCount)
        {
            return bitCount < right.bitCount;
        }
        else
        {
            return val < right.val;
        }
    }
};

class Solution
{
public:
    vector<int> sortByBits(vector<int>& arr)
    {
        vector<Record> records = arr |
            views::transform([](int x) { return Record(x); }) |
            ranges::to<vector>();
        // ranges::to is C++23 only

        sort(records.begin(), records.end());

        vector<int> result = records |
            views::transform(&Record::val) |
            ranges::to<vector>();
        return result;
    }
};

int main(int argc, char* argv[])
{
    cout << "1356-sort-int-by-num-1-bits\n";

    vector<int> arr = { 0,1,2,3,4,5,6,7,8 };
    vector<int> exp = { 0,1,2,4,8,3,5,6,7 };
    cout << "Input: arr = [";
    for (auto& a: arr)
    {
        cout << a << ",";
    }
    cout << "], exp = [";
    for (auto& e: exp)
    {
        cout << e << ",";
    }
    cout << "]\n";

    Solution sol;
    auto res = sol.sortByBits(arr);

    cout << "Output: res = [";
    for (auto& r: res)
    {
        cout << r << ",";
    }
    cout << "]\n";

    return 0;
}

