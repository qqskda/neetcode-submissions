/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // What about get the list of stacks, and pop together?

        stack<int> stack1;
        stack<int> stack2;

        while (l1)
        {
            stack1.push(l1->val);
            l1 = l1->next;
        }

        while (l2)
        {
            stack2.push(l2->val);
            l2 = l2->next;
        }

        ListNode *head = nullptr;
        int carry = 0;
        while (!stack1.empty() || !stack2.empty() || carry)
        {
            int val = carry;

            if (!stack1.empty())
            {
                val += stack1.top();
                stack1.pop();
            }

            if (!stack2.empty())
            {
                val += stack2.top();
                stack2.pop();
            }

            carry = val / 10;
            val = val % 10;
            head = new ListNode(val, head);
        }

        return head;
    }
};