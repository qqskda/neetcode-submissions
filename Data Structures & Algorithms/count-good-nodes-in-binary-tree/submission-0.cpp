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
    int dfs(TreeNode* root, int soFarMax)
    {
        if (!root) return 0;

        int ret = 0;
        if (root->val >= soFarMax)
        {
            ++ret;
            soFarMax = root->val;
        }

        ret += dfs(root->left, soFarMax);
        ret += dfs(root->right, soFarMax);
        return ret;
    }

    int goodNodes(TreeNode* root) {
        // DFS, and I need to know what is the max of the path that I took
        return dfs(root, INT_MIN);
    }
};
