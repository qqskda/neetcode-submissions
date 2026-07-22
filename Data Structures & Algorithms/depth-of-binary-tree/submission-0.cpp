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
  int dfs(TreeNode* node, int currDepth) {
    if (!node) return currDepth;

    return max(dfs(node->left, currDepth + 1), dfs(node->right, currDepth + 1));
  }

    int maxDepth(TreeNode* root) {
      return dfs(root, 0);      
    }
};
