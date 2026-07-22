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

    bool dfs(TreeNode* node, int targetSum, int currSum)
    {
      // Leaf : does not have any child
      if (!node) return false;

      currSum += node->val;
      if (!node->left && !node->right)
      {
        // leaf
        return (targetSum == currSum);
      }


      return (dfs(node->left, targetSum, currSum) || dfs(node->right, targetSum, currSum));
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        // root to leaf => DFS
      return dfs(root, targetSum, 0);

    }
};