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
    int dfs(TreeNode* root, const int k, int& curr)
    {
        if (!root) return -1;

        int val = dfs(root->left, k, curr);
        if (val != -1) return val;

        ++curr;
        if (curr == k) // I am the chosen one
            return root->val;
        
        val = dfs(root->right, k, curr);
        if (val != -1) return val;

        return -1;
    }
    int kthSmallest(TreeNode* root, int k) {
        // Given tree is BST
        // First intuition:
        // DFS will give us the total list of values so we can count K.
        // we can stop at kth element.

        // we do not know which position is root taking, BST does not mean it is balanced tree.
        int curr = 0;
        return dfs(root, k, curr);
    }
};
