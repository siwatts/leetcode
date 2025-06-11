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
        void printList(ListNode* list)
        {
            //cout << "Printing list contents\n";
            cout << "[";
            printNode(list);
            cout << "]\n";
        }
        void printNode(ListNode* node)
        {
            cout << node->val;
            // Recursive
            if (node->next != nullptr)
            {
                cout << ",";
                printNode(node->next);
            }
        }
        ListNode* makeListFromNumber(double input)
        {
            // 1st (biggest) digit of input is the last element of list
            // Since we make list starting from last element and link each next element
            // to the previous, we need to start with the most significant bit
            //
            // The digits are pulled off starting from the least significant, so use a
            // stack to hold them and flip the order
            //cout << "Given " << input << " to parse\n";
            stack<int> digits;
            int digit;
            if (input == 0)
            {
                // Special case if we get a 0 in the first place, need to output at least one digit!
                digits.push(0);
            }
            while (input != 0)
            {
                // Pull off least significant digit
                digit = (int) fmod(input, 10.0); // floating pt. modulo (%)
                digits.push(digit);
                //cout << "Found digit " << digit << endl;
                // Shift back by 10
                input -= digit;
                input = trunc(input / 10.0);
                //cout << "Now " << input << endl;
            }
            //cout << "Done parsing input\n" << endl;
            // Make linked list, starting with last element (most significant bit)
            ListNode* prev = nullptr;
            while (!digits.empty())
            {
                digit = digits.top();
                digits.pop();
                //cout << "Making node from digit " << digit << endl;
                ListNode* n = new ListNode(digit, prev);
                prev = n;
            }
            // List complete, and first node is the previously created one
            return prev;
        }
        void deleteList(ListNode* list)
        {
            if (list->next != nullptr)
            {
                // Call recursively, so it starts with the final element
                deleteList(list->next);
            }
            delete list;
        }
        // Solution
        double numberFromList(ListNode* list)
        {
            // Traverse over list which starts with the least signifcant bit
            // Increase the power of 10 for each digit we read by 1
            int powerten = 0;
            double result = 0;
            while (list != nullptr)
            {
                result += pow(10, powerten) * list->val;
                powerten++;
                // Get next node ready
                list = list->next;
            }
            return result;
        }
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
        {
            double n1 = numberFromList(l1);
            double n2 = numberFromList(l2);
            double res = n1 + n2;
            //cout << "Decoding list addition: " << n1 << " + " << n2 << " = " << res << "\n";
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

    Solution soln;

    cout << "Test case 1\n";
    ListNode* l1 = soln.makeListFromNumber(342);
    ListNode* l2 = soln.makeListFromNumber(465);
    cout << "l1 =  ";
    soln.printList(l1);
    cout << "l2 =  ";
    soln.printList(l2);

    // Add together
    ListNode* output = soln.addTwoNumbers(l1, l2);
    // Display output
    cout << "out = ";
    soln.printList(output);

    // Cleanup
    soln.deleteList(l1);
    soln.deleteList(l2);
    soln.deleteList(output);

    return 0;
}

