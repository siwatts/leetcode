#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
private:
    unordered_set<int> numSet;
    bool containsNum(int n)
    {
        return numSet.contains(n);
    }
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head)
    {
        // Store nums in a set for fast lookup
        for (auto& n: nums)
        {
            numSet.insert(n);
        }

        // Special case for head of the list, since we need to keep hold of it
        while (containsNum(head->val))
        {
            head = head->next;
        }
        ListNode* node = head;
        while (node)
        {
            while (node->next && containsNum(node->next->val))
            {
                // Skip it
                node->next = node->next->next;
            }
            node = node->next;
        }

        return head;
    }
};

int main(int argc, char* argv[])
{
    cout << "3217-delete-nodes-from-linked-list-present-in-array\n";

    // Input:
    vector<int> headVec = { 1,2,3,4,5 };
    vector<int> nums = { 1,2,3 };

    // Process input
    ListNode* head = nullptr;
    for (int i = headVec.size() - 1; i >= 0; i--)
    {
        ListNode* prev = head;
        head = new ListNode(headVec[i], prev);
    }

    // Print input
    ListNode* node = head;
    cout << "Input: head = [ ";
    while (node)
    {
        cout << node->val << ",";
        node = node->next;
    }
    cout << " ]\n";

    // Run solution
    Solution sol;
    ListNode* res = sol.modifiedList(nums, head);

    // Print output
    node = res;
    cout << "Output: res = [ ";
    while (node)
    {
        cout << node->val << ",";
        node = node->next;
    }
    cout << " ]\n";

    return 0;
}

