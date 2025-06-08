#include <iostream>
#include <stack>
#include <cmath>

using namespace std;

/*
 * You are given two non-empty linked lists representing two non-negative
 * integers. The digits are stored in reverse order, and each of their nodes
 * contains a single digit. Add the two numbers and return the sum as a linked
 * list.
 *
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 *
 * Example 1:
 * Input: l1 = [2,4,3], l2 = [5,6,4]
 * Output: [7,0,8]
 * Explanation: 342 + 465 = 807.
 */

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
    public:
        // Setup
        static void printList(ListNode* list)
        {
            cout << "Printing list contents\n";
            cout << "[";
            printNode(list);
            cout << "]\n";
        }
        static void printNode(ListNode* node)
        {
            cout << node->val;
            // Recursive
            if (node->next != nullptr)
            {
                cout << ",";
                printNode(node->next);
            }
        }
        static ListNode* makeListFromNumber(int input)
        {
            // 1st (biggest) digit of input is the last element of list
            // Since we make list starting from last element and link each next element
            // to the previous, we need to start with the most significant bit
            //
            // The digits are pulled off starting from the least significant, so use a
            // stack to hold them and flip the order
            cout << "Given " << input << " to parse\n";
            stack<int> digits;
            int digit;
            while (input != 0)
            {
                // Pull off least significant digit
                digit = input % 10;
                digits.push(digit);
                cout << "Found digit " << digit << endl;
                // Shift back by 10
                input -= digit;
                input = (int) (input / 10.0);
                cout << "Now " << input << endl;
            }
            cout << "Done parsing input\n" << endl;
            // Make linked list, starting with last element (most significant bit)
            ListNode* prev = nullptr;
            while (!digits.empty())
            {
                digit = digits.top();
                digits.pop();
                cout << "Making node from digit " << digit << endl;
                ListNode* n = new ListNode(digit, prev);
                prev = n;
            }
            // List complete, and first node is the previously created one
            return prev;
        }
        static void deleteList(ListNode* list)
        {
            if (list->next != nullptr)
            {
                // Call recursively, so it starts with the final element
                deleteList(list->next);
            }
            delete list;
        }
        // Solution
        static int numberFromList(ListNode* list)
        {
            // Traverse over list which starts with the least signifcant bit
            // Increase the power of 10 for each digit we read by 1
            int powerten = 0;
            int result = 0;
            while (list != nullptr)
            {
                result += pow(10, powerten) * list->val;
                powerten++;
                // Get next node ready
                list = list->next;
            }
            return result;
        }
        static ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
        {
            int n1 = numberFromList(l1);
            int n2 = numberFromList(l2);
            int res = n1 + n2;
            cout << "Decoding list addition: " << n1 << " + " << n2 << " = " << res << "\n";
            return makeListFromNumber(res);
        }
};

int main(int argc, char* argv[])
{
    cout << "Leetcode 2. Add Two Numbers\n";

    // // Linked list for testing
    // // Number 123
    // ListNode last(1);
    // ListNode mid(2, &last);
    // ListNode first(3, &mid);
    // Solution::printList(&first);

    ListNode* l1 = Solution::makeListFromNumber(342);
    ListNode* l2 = Solution::makeListFromNumber(465);
    Solution::printList(l1);
    Solution::printList(l2);

    // Add together
    ListNode* output = Solution::addTwoNumbers(l1, l2);
    // Display output
    Solution::printList(output);

    // Cleanup
    Solution::deleteList(l1);
    Solution::deleteList(l2);

    return 0;
}

