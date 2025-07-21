#include <iostream>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
Given the root of a binary tree, check whether it is a mirror of itself (i.e.,
symmetric around its center).
*/

class Solution
{
public:
    bool checkNodes(TreeNode* one, TreeNode* two)
    {
        if (one == nullptr && two == nullptr)
        {
            return true;
        }
        else if ((one != nullptr && two == nullptr) || (one == nullptr && two != nullptr))
        {
            return false;
        }
        else if (one->val != two->val)
        {
            return false;
        }
        else
        {
            // Check both children recursively
            // But we are checking for symmetry so _reflect left and right_!
            return (checkNodes(one->left, two->right) && checkNodes(one->right, two->left));
        }
    }
    bool isSymmetric(TreeNode* root)
    {
        // To be symmetric, we must take both child nodes and check that they are exactly equal
        // (actually they must be mirror images of each other!)
        return checkNodes(root->left, root->right);
    }
};

int main(int argc, char* argv[])
{
    cout << "101-symmetric-tree\n";

    return 0;
}

