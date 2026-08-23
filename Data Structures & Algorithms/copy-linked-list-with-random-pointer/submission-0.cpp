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
    Node* copyNode(Node* src, unordered_map<Node*, Node*>& visited)
    {
        if (!src) return nullptr;

        if (visited.contains(src)) return visited[src];

        Node *dest = new Node(src->val);

        visited[src] = dest;

        dest->next = copyNode(src->next, visited);
        dest->random = copyNode(src->random, visited);

        return dest;
    }
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> visited;

        return copyNode(head, visited);
    }
};
