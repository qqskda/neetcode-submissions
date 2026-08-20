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
    vector<vector<int>> levelOrder(TreeNode* root) {
        // Level order => BFS => Queue
        if (!root) return {};

        queue<TreeNode*> treeq;
        treeq.push(root);

        vector<vector<int>> ret;

        while (!treeq.empty())
        {
            int sz = treeq.size(); // # of nodes in a level
            vector<int> level;
            level.reserve(sz);

            while (sz-- > 0)
            {
                TreeNode* tree = treeq.front();
                treeq.pop();
                level.push_back(tree->val);

                if (tree->left) treeq.push(tree->left);
                if (tree->right) treeq.push(tree->right);
            }
            ret.push_back(level);
        }
        return ret;

    }
};
