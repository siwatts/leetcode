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
    vector<int> getRow(int rowIndex, vector<int>& prevRow)
    {
        if (rowIndex == 0)
        {
            throw logic_error("rowIndex == 0");
        }
        else if (prevRow.size() != rowIndex)
        {
            throw logic_error("prevRow.size() != rowIndex");
        }
        else
        {
            vector<int> row(rowIndex+1);
            for (int i = 0; i < rowIndex+1; i++)
            {
                row[i] = (i-1 < 0 ? 0 : prevRow[i-1]) + (i >= rowIndex ? 0 : prevRow[i]);
            }
            return row;
        }
    }
    vector<int> getRow(int rowIndex)
    {
        // First number in 1st row of 1, is 1
        // Each row is bounded by 1s at either end which can either be coded in
        // or we handle out of bounds addition
        // Each row element i is the sum of the previous row's elements i-1 and i

        // Seed with first row
        vector<int> row = { 1 };
        vector<int> prevRow;

        if (rowIndex == 0)
        {
            return row;
        }

        for (int i = 1; i <= rowIndex; i++)
        {
            prevRow = row;
            row = getRow(i, prevRow);
        }

        return row;
    }
};

int main(int argc, char* argv[])
{
    cout << "118-pascals-triangle\n";

    int rowIndex;
    if (argc > 1)
    {
        rowIndex = atoi(argv[1]);
    }
    else
    {
        rowIndex = 5;
    }

    cout << "Input: rowIndex = " << rowIndex << "\n";
    Solution sol;
    vector<int> res = sol.getRow(rowIndex);

    cout << "Output: [";
    for (auto n : res)
    {
        cout << n << ",";
    }
    cout << "]";

    return 0;
}

