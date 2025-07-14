#include <iostream>
#include <vector>

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
public:
    int getDecimalValue(ListNode* head)
    {
        int res = head->val;
        while (head->next != nullptr)
        {
            // First list element is most significant bit, so keep
            // shifting to the left as we read in more digits
            res = res << 1;
            head = head->next;
            res += head->val;
        }

        return res;
    }
};

int main(int argc, char* argv[])
{
    cout << "1290-bin-num-linked-list-to-int\n";

    // Input
    vector<int> in = { 1,0,1 };
    cout << "Input: in = [";
    for (auto i : in)
    {
        cout << i << ",";
    }
    cout << "]\n";
    // Make linked list
    ListNode* head = nullptr;
    while (in.size() != 0)
    {
        int v = in.back();
        in.pop_back();
        ListNode* n = new ListNode(v, head);
        head = n;
    }

    // Solution
    Solution sol;
    int res = sol.getDecimalValue(head);

    // Output
    cout << "Output: res = " << res << "\n";

    return 0;
}
