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

    bool verifySubtree(TreeNode* root, TreeNode* subRoot)
    {
        // base case
        if (!root && !subRoot) return true;
        if (root && !subRoot) return false;
        if (!root && subRoot) return false;

        // check value
        if (root->val != subRoot->val) return false;

        // go deeper
        return (verifySubtree(root->left, subRoot->left) && verifySubtree(root->right, subRoot->right));
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root && !subRoot) return true;
        if (root && !subRoot) return false;
        if (!root && subRoot) return false;

        // check value
        if (root->val == subRoot->val)
        {
            bool isSub = verifySubtree(root, subRoot);
            if (isSub) return true;
        }

        // go deeper
        return (isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot));

    }
};
