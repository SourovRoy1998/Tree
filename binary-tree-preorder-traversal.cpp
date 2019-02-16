//https://leetcode.com/problems/binary-tree-preorder-traversal/

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
private:
    vector<int> vtr;
public:
    
   void preorder(TreeNode* root) {
        if(!root)
            return ;
        vtr.push_back(root->val);
        if(root->left)
            preorder(root->left);
        if(root->right)
            preorder(root->right);
   }
    
    
    
    vector<int> preorderTraversal(TreeNode* root) {
        preorder(root);
        return vtr;
    }
};
