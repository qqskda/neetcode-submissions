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
    TreeNode* binaryTree(const vector<int>& preorder, int& pi, const int left, const int right, unordered_map<int,int>& inordermap)
    {
        // base
        if (left > right) return nullptr;

        // we have root
        int rootval = preorder[pi];
        TreeNode *root = new TreeNode(rootval);

        // update next pi
        ++pi;

        // root is in the middle of the inorder's perspective.
        // Meaning, find the index of the new root, and set it as left/right divider
        int mid = inordermap[rootval];
        root->left = binaryTree(preorder, pi, left, mid-1, inordermap);
        root->right = binaryTree(preorder, pi, mid+1, right, inordermap);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // preorder = [3, 9, 20, 15, 7]
        // inorder  = [9, 3, 15, 20, 7]

        // [3]
        // [9][15, 20, 7]

        // 0
        // [-1] [2 3 4]

        // Need to know the preorder index to know which root are we working on
        // Use left and right to set the rande of nodes in inorder
        unordered_map<int,int> inordermap;

        for (int i = 0; i < inorder.size(); ++i)
        {
            // Update the map so that value = index
            inordermap[inorder[i]] = i;
        }
        int pi = 0;
        int left = 0, right = inorder.size()-1;
        return binaryTree(preorder, pi, left, right, inordermap);
    }
};
