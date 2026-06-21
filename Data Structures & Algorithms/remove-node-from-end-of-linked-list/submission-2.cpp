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
        // [] n -> []
        // [a] 1 -> []
        if (!head || !head->next) return NULL;
        // [a,b] 1 -> [a]
        // [a,b] 2 -> [b]

        // To know the ListNode at NthFromEnd, we need to know where is the end.
        // Efficient way is to keep track of two pointers; fast and slow where distance is n.
        // However, slow is pointing prev of NthFromEnd
        // [a,b] 1 -> fast: b slow: a -> a->next = b->next which is NULL
        // [a,b,c] 2 -> fast:c slow: a -> a->next = b->next which is C

        // 1. Forward fast to have distance of n from slow
        int distance = n;
        ListNode* fast = head;
        while(distance > 0)
        {
            if (fast->next) fast = fast->next;
            else
            {
                head = head->next;
                return head;
            }
            distance--;
        }

        // 2. Forward fast and slow together. As soon as fast reaches end. 
        // 2.1 Update slow->next = fast->next and return head.
        ListNode* slow = head;
        while (fast)
        {
            if (!fast->next)
            {
                // reached the end
                slow->next = slow->next->next;
                return head;
            }
            fast = fast->next;
            slow = slow->next;
        }
        return head;
    }
};
