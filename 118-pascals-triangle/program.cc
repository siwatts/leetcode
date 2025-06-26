#include <iostream>
#include <vector>

using namespace std;

/*
Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:
*/

class Solution
{
public:
    void populateRow(int n, vector<int>& prevRow, vector<int>& row)
    {
        if (n == 0)
        {
            throw logic_error("n == 0");
        }
        else if (prevRow.size() != n)
        {
            throw logic_error("prevRow.size() != n");
        }
        else
        {
            for (int i = 0; i < n+1; i++)
            {
                row[i] = (i-1 < 0 ? 0 : prevRow[i-1]) + (i >= n ? 0 : prevRow[i]);
            }
        }
    }
    vector<vector<int>> generate(int numRows)
    {
        // First number in 1st row of 1, is 1
        // Each row is bounded by 1s at either end which can either be coded in
        // or we handle out of bounds addition
        // Each row element i is the sum of the previous row's elements i-1 and i

        // Seed with first row
        vector<vector<int>> res;
        res.push_back( { 1 } );

        for (int row = 1; row < numRows; row++)
        {
            vector<int> newRow(row+1);
            populateRow(row, res[row-1], newRow);
            res.push_back(newRow);
        }

        return res;
    }
};

int main(int argc, char* argv[])
{
    cout << "118-pascals-triangle\n";

    int numRows;
    if (argc > 1)
    {
        numRows = atoi(argv[1]);
    }
    else
    {
        numRows = 5;
    }

    cout << "Input: numRows = " << numRows << "\n";
    Solution sol;
    vector<vector<int>> res = sol.generate(numRows);

    cout << "Output: [";
    for (auto v : res)
    {
        cout << "[";
        for (auto i : v)
        {
            cout << i << ",";
        }
        cout << "],";
    }
    cout << "]";

    return 0;
}

