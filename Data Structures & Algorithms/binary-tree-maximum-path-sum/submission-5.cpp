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
    // we need a function that returns the maxPath
    // that updates the maxPathSum
    int dfs(TreeNode* root, int& maxPathSum)
    {
        if (!root) return 0;

        int left = max(0, dfs(root->left, maxPathSum));
        int right = max(0, dfs(root->right, maxPathSum));

        // if my val is negative, dont bother updating maxPathSum
        maxPathSum = std::max(maxPathSum, left + root->val + right);
        return root->val + max(left, right);
    }
    int maxPathSum(TreeNode* root) {
        // it is not BST => meaning we have to visit all the node eventually

        // maxPathSum of root =>
        // left maxPath + root->val + right maxPath

        // Note that left maxPathSum is different from left maxPath
        if (!root) return 0;
        int ret = root->val;
        dfs(root, ret);
        return ret;
    }
};
