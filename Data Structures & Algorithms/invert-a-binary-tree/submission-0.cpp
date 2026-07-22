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
    TreeNode* invertTree(TreeNode* root) {
        // BFS sounds logical to me
        // BFS, we can do via queue, and since order does not matter here, stack as well

        queue<TreeNode*> q;

        if (root) q.push(root);

        while (!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();

            // 1. Invert its child
            TreeNode* temp = node->left;
            node->left = node->right;
            node->right = temp;

            // 2. Push its child
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        return root;
    }
};
