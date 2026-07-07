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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // iteration using stack

        stack<pair<TreeNode*, TreeNode*>>stk;

        stk.push({p,q});

        while (!stk.empty())
        {
          auto [p, q] = stk.top();
          stk.pop();
          if ((!p && q) || (p && !q)) return false;
          if (!p && !q) continue;

          if (p->val != q->val) return false;

          stk.push({p->left, q->left});
          stk.push({p->right, q->right});
        }
        return true;
    }
};
