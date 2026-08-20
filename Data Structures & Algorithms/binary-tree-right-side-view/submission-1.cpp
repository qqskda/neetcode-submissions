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
    vector<int> rightSideView(TreeNode* root) {
        // BFS, but takes right to left.
        // In each level, just get the first one (the right most one)
        // push_back in the vector, but queue right, left child

        if (!root) return {};

        queue<TreeNode *> q;

        q.push(root);
        vector<int> ret;
        TreeNode *head = nullptr;
        while (!q.empty())
        {
            int sz = q.size();
            // push_back only the first one (right most)
            head = q.front();
            ret.push_back(head->val);
            while (sz-- > 0)
            {
                head = q.front();
                q.pop();
                if(head->right) q.push(head->right);
                if(head->left) q.push(head->left);
            }
        }
        return ret;
    }
};
