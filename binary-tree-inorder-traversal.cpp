//https://leetcode.com/problems/binary-tree-inorder-traversal/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


class Solution {
std::vector<int> vtr;
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root)
            return {};
        inorderTraversal(root->left);
        vtr.push_back(root->val);
        inorderTraversal(root->right);
        vector<int>temp=vtr;
        return temp;
        
    }
};
