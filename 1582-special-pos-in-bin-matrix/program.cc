#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*
Given an m x n binary matrix mat, return the number of special positions in mat.

A position (i, j) is called special if mat[i][j] == 1 and all other elements in
row i and column j are 0 (rows and columns are 0-indexed).
*/

class Solution
{
public:
    int numSpecial(vector<vector<int>>& mat)
    {
        // i row, j col
        // N rows, M cols
        int N = mat.size();
        int M = mat[0].size();
        // Lets find some candidate rows and columns that only contain one 1
        unordered_map<int,int> candidateRows;
        unordered_map<int,int> candidateCols;
        for (int i = 0; i < N; i++)
        {
            bool cand = false;
            int pos;
            // Scan this row
            for (int j = 0; j < M; j++)
            {
                if (mat[i][j] == 1)
                {
                    if (!cand)
                    {
                        cand = true;
                        pos = j;
                    }
                    else // found > 1 so stop here
                    {
                        cand = false;
                        break;
                    }
                }
            }
            if (cand)
                candidateRows[i] = pos;
            else
                candidateRows[i] = -1;
        }
        for (int j = 0; j < M; j++)
        {
            bool cand = false;
            int pos;
            // Scan this column
            for (int i = 0; i < N; i++)
            {
                if (mat[i][j] == 1)
                {
                    if (!cand)
                    {
                        cand = true;
                        pos = i;
                    }
                    else // found > 1 so stop here
                    {
                        cand = false;
                        break;
                    }
                }
            }
            if (cand)
                candidateCols[j] = pos;
            else
                candidateCols[j] = -1;
        }
        int special = 0;
        for (auto& row: candidateRows)
        {
            if (row.second != -1)
            {
                // Row 'row.first' contains a candidate special value at
                // column 'row.second', is the inverse true?
                int i = row.first;
                int j = row.second;
                if (candidateCols[j] == i)
                {
                    special++;
                }
            }
        }
        return special;
    }
};

int main(int argc, char* argv[])
{
    cout << "1582-special-pos-in-bin-matrix\n";

    vector<vector<int>> mat = {{1,0,0},{0,0,1},{1,0,0}};
    int exp = 1;
    cout << "Input: mat = [";
    for (auto& ma: mat)
    {
        cout << "[";
        for (auto& m: ma)
        {
            cout << m << ",";
        }
        cout << "],";
    }
    cout << "], exp = " << exp << "\n";

    Solution sol;
    int res = sol.numSpecial(mat);

    cout << "Output: res = " << res << "\n";
    if (res == exp)
        cout << "Test: PASS\n";
    else
        cout << "Test: FAIL\n";

    return 0;
}

