#include <iostream>
#include <vector>

using namespace std;

/*
Given the root of a binary tree, return the inorder traversal of its nodes' values.

inorder traversal runs from left child -> root -> right child, recursively
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
    void processNode(vector<int>& res, TreeNode* node)
    {
        if (node == nullptr)
            return;

        // Recursively process leftmost elements
        processNode(res, node->left);

        // Add this root element to the list
        res.push_back(node->val);

        // Recursively process rightmost elements
        processNode(res, node->right);
    }
    vector<int> inorderTraversal(TreeNode* root)
    {
        vector<int> res;
        processNode(res, root);

        return res;
    }
};

int main(int argc, char* argv[])
{
    cout << "94-binary-tree-inorder-traversal\n";

    return 0;
}
