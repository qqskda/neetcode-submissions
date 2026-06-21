class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Edge case: 0 or 1 node
        if (!head || !head->next) return NULL;

        // Use two pointers (fast, slow) with a gap of n between them.
        // When fast reaches the last node, slow is pointing to the node
        // just before the one we want to remove.

        // Step 1: Advance fast by n steps.
        // If fast falls off the end, the head itself is the Nth from end — remove it.
        int distance = n;
        ListNode* fast = head;
        while (distance > 0)
        {
            if (fast->next) fast = fast->next;
            else
            {
                head = head->next;
                return head;
            }
            distance--;
        }

        // Step 2: Advance both pointers until fast reaches the last node.
        // slow->next is then the node to remove.
        ListNode* slow = head;
        while (fast)
        {
            if (!fast->next)
            {
                slow->next = slow->next->next;
                return head;
            }
            fast = fast->next;
            slow = slow->next;
        }
        return head;
    }
};