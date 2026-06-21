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
    bool hasCycle(ListNode* head) {
        // Cycle detection: two pointers; one travel by one, one travels by two.

        // 1. empty => False
        // 2. No cycle (reach the end) => False;

        // 3. Cycle => Two pointers
        // 3.1 if same node, return true;
        // 3.2 if one (fast) reaches the end, returns false;

        if (!head) return false;

        ListNode* fast_head = head->next;

        while (head && fast_head)
        {
            if (head == fast_head)
                return true;

            head = head->next;
            
            if (fast_head && fast_head->next && fast_head->next->next)
                fast_head = fast_head->next->next;
            else
                return false;
        }
        return false;
    }
};
