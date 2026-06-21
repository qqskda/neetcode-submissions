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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Edge case where [] [a] since n >= 1
        if (!head || !head->next) return NULL;

        ListNode dummy(0, head);
        ListNode *fast = &dummy;
        ListNode *slow = &dummy;

        for (int i = 0; i <= n; ++i)
        {
            // since n <= sz, we do not need to check if node exists
            // fast may be the last node 
            fast = fast->next;
        }

        while (fast)
        {
            fast = fast->next;
            slow = slow->next;
        }

        // fast reached the end
        slow->next = slow->next->next;

        return dummy.next;
    }
};
