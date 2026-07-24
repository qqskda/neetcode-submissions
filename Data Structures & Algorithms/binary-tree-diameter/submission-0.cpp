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
    int maxPath = 0;
public:
    // return max depth
    // update maxPath
    int getPath(TreeNode* root)
    {
        if (!root) return 0;

        int left = getPath(root->left);
        int right = getPath(root->right);

        maxPath = max(maxPath, left+right);

        return max(left, right) + 1;
        
    }
    int diameterOfBinaryTree(TreeNode* root) {
        getPath(root);
        return maxPath;
    }
};
