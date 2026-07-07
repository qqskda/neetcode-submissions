/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // To know if they are the same tree, we have to traverse each tree

        // Recursion
        // base
        if ((p && !q) || (!p && q)) return false;
        // check
        if (!p && !q) return true;
        if (p->val != q->val) return false;
        // call left and right
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);

    }
};
