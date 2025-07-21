#include <iostream>

using namespace std;

/*
Given the roots of two binary trees p and q, write a function to check if they
are the same or not.

Two binary trees are considered the same if they are structurally identical, and
the nodes have the same value.
*/

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    bool isSameTree(TreeNode* p, TreeNode* q)
    {
        // Terminate recursive calls first
        if (p == nullptr && q == nullptr)
            return true;
        else if ((p != nullptr && q == nullptr) || (p == nullptr && q != nullptr))
            return false;

        // Now we know both p and q aren't null, check them and their children recursively
        if (p->val != q->val)
            return false;

        // All good so far so the result is recursive check of their child nodes
        return (isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
    }
};

int main(int argc, char* argv[])
{
    cout << "100-same-tree\n";

    return 0;
}

