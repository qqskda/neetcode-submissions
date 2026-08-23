/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;
        unordered_map<Node*, Node*> visited;

        Node *curr = head;
        Node *copyHead = new Node(head->val);
        Node *copy = copyHead;
        visited[curr] = copy;
        curr = curr->next;
        while (curr)
        {
            copy->next = new Node(curr->val);
            copy = copy->next;
            visited[curr] = copy;
            curr = curr->next;
        }

        copy = copyHead;
        curr = head;

        while (curr)
        {
            if (curr->random)
                copy->random = visited[curr->random];

            curr = curr->next;
            copy = copy->next;
        }
        return copyHead;
    }
};
