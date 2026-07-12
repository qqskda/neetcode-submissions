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

    void dfs(vector<int>& ret, TreeNode* root)
    {
      if (!root) return;

      // left
      dfs(ret, root->left);

      // right
      dfs(ret, root->right);

      // mid
      ret.emplace_back(root->val);

    }
    vector<int> postorderTraversal(TreeNode* root) {
        // left right mid => postorder
        vector<int> vec;
        dfs(vec, root);
        return vec;
        
    }
};