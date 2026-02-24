#include <iostream>
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
You are given the root of a binary tree where each node has a value 0 or 1. Each
root-to-leaf path represents a binary number starting with the most significant
bit.

- For example, if the path is 0 -> 1 -> 1 -> 0 -> 1, then this could represent
  01101 in binary, which is 13.

For all leaves in the tree, consider the numbers represented by the path from
the root to that leaf. Return the sum of these numbers.

The test cases are generated so that the answer fits in a 32-bits integer.
*/

class Solution
{
public:
    int sumRootToLeaf(TreeNode* root, int sum)
    {
        if (!root)
        {
            return 0;
        }
        sum <<= 1;
        sum += root->val;
        if (root->left || root->right)
        {
            return sumRootToLeaf(root->left, sum) + sumRootToLeaf(root->right, sum);
        }
        else
        {
            return sum;
        }
    }
    int sumRootToLeaf(TreeNode* root)
    {
        int sum = sumRootToLeaf(root, 0);
        return sum;
    }
};

int main(int argc, char *argv[])
{
    cout << "1022-sum-root-to-leaf-bin-numbers\n";

    // Manually construct a test case ?
    //            1
    //           / \
    //          0   1
    //         /|   |\
    //        0 1   0 1
    //
    // root = [1,0,1,0,1,0,1]
    // exp = 22
    // expl. (100) + (101) + (110) + (111) = 4 + 5 + 6 + 7 = 22

    return 0;
}

