//https://leetcode.com/problems/increasing-order-search-tree/

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
public:
    TreeNode* inorder(TreeNode* root,TreeNode* &temp){
        if(!root)
            return NULL;
        inorder(root->left,temp);
        temp->right=new TreeNode(root->val);
        temp=temp->right;
        inorder(root->right,temp);
        return NULL;
    }
    
    
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode head(0);
        TreeNode* temp=&head;
        inorder(root, temp);
        return head.right;
    }
};

