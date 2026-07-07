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
  int rangeSumBST(TreeNode* root, int low, int high) {
    // Binary search Tree meaning the tree is ordered already.
    // Left is smaller than my umber, right is bigger than my number

    // BFS soumds good
    int sum = 0;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
      TreeNode* temp = q.front();
      q.pop();
      if (!temp) continue;

      if (temp->val >= low && temp->val <= high) sum += temp->val;

      if (temp->val > low) q.push(temp->left);
      if (temp->val < high) q.push(temp->right);
    }
    return sum;
  }
};