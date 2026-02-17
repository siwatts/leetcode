#include <iostream>
#include <vector>
#include <unordered_map>
#include <ranges>
#include <sstream>
#include <unordered_set>
#include <iomanip>

using namespace std;

/*
A binary watch has 4 LEDs on the top to represent the hours (0-11), and 6 LEDs
on the bottom to represent the minutes (0-59). Each LED represents a zero or
one, with the least significant bit on the right.

    For example, the below binary watch reads "4:51".
    [Pic: H 0100, PM 1, M 110011]

Given an integer turnedOn which represents the number of LEDs that are currently
on (ignoring the PM), return all possible times the watch could represent. You
may return the answer in any order.

The hour must not contain a leading zero.

    For example, "01:00" is not valid. It should be "1:00".

The minute must consist of two digits and may contain a leading zero.

    For example, "10:2" is not valid. It should be "10:02".

*/

class Solution
{
private:
    unordered_map<int, unordered_set<int>> numberBits;
    vector<int> getHours(int turnedOn)
    {
        auto hrs = numberBits[turnedOn];
        vector<int> res;
        for (auto& h: hrs | views::filter([](int x){ return x < 12; }))
        {
            res.push_back(h);
        }
        return res;
    }
    vector<int> getMinutes(int turnedOn)
    {
        auto mins = numberBits[turnedOn];
        vector<int> res;
        for (auto& m: mins | views::filter([](int x){ return x < 60; }))
        {
            res.push_back(m);
        }
        return res;
    }
    vector<string> combineMinsHours(vector<int> hours, vector<int> mins)
    {
        if (hours.size() == 0 || mins.size() == 0)
        {
            return {};
        }
        vector<string> res;
        for (auto& h: hours)
        {
            for (auto& m: mins)
            {
                stringstream ss;
                ss << h << ":";
                ss << setw(2) << setfill('0') << m; // 0 pad to width 2
                res.push_back(ss.str());
            }
        }
        return res;
    }
    int getBitCount(int number)
    {
        // We know the biggest number we will see is 60, so that's 6 bits ie. 2^0 to 2^5
        int cnt = 0;
        for (int i = 0; i < 6; i++)
        {
            cnt += number & 1;
            number = number >> 1;
        }
        return cnt;
    }
public:
    Solution()
    {
        // Brute force it
        for (int i = 0; i < 60; i++)
        {
            // Get the number of bits and add it to the map
            int bitCount = getBitCount(i);
            numberBits[bitCount].insert(i);
        }
    }
    vector<string> readBinaryWatch(int turnedOn)
    {
        // Hours can be 0-4 LEDs (values 0-11, for some reason it's not a 12h clock with 12pm...)
        // Minutes can be 0-6 LEDs (0-59)
        // Leave out leading 0 for hours
        // Ignore PM LED
        vector<string> res;
        for (int i = 0; i <= turnedOn; i++)
        {
            int j = turnedOn - i;
            auto hrs = getHours(i);
            auto mins = getMinutes(j);
            auto time = combineMinsHours(hrs, mins);
            for (auto& t: time)
            {
                res.push_back(t);
            }
        }
        return res;
    }
};

int main(int argc, char **argv)
{
    cout << "401-binary-watch\n";

    int turnedOn = 1;
    vector<string> exp = {"0:01","0:02","0:04","0:08","0:16","0:32","1:00","2:00","4:00","8:00"};
    cout << "Input: turnedOn = " << turnedOn << "\n";
    cout << "Exp. Output: exp = [";
    for (auto& e: exp)
    {
        cout << "'" << e << "',";
    }
    cout << "]\n";

    Solution sol;
    vector<string> res = sol.readBinaryWatch(turnedOn);

    cout << "Output: res = [";
    for (auto& r: res)
    {
        cout << "'" << r << "',";
    }
    cout << "]\n";

    return 0;
}

