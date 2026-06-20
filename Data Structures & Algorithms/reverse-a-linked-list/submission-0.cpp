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
    ListNode* reverseList(ListNode* head) {
        // Singly linked list; it only knows what is next.
        // To reverse, you have to know 
        // 1. Save the last one so current one can point
        // 2. Save the next one so I can work on it next
        // 3. Make the current one to point the previous one.

        if (!head) return head;
        if (!head->next) return head;

        // We now have at least two to swap the order
        ListNode *prev = NULL;
        ListNode *curr = head;
        ListNode *next = NULL;

        while (curr)
        {
            // 1. Save next
            next = curr->next;

            // 2. Point prev
            curr->next = prev;

            // 3. now I am the prev
            prev = curr;

            // 4. Moving forward
            curr = next;
        }
        return prev;
    }
};
