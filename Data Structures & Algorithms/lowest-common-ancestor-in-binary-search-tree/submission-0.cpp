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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Ancestor : have both p and q
        // p or q can be an ancestor of each

        if (p->val > q->val) swap(p, q);

        // 1. root < p < q (go to right)
        // 2. p < q < root (go to left)
        // 3. p < root < q (I am the root!)
        // 4. root == p < q (i am the root)
        // 5. p < q == root (i am the root)

        while(root)
        {
            if (root->val < p->val) // go to right
                root = root->right;
            else if (q->val < root->val) // go to left
                root = root->left;
            else // I am the root
                return root;
        }
        return root;
    }
};
