//https://leetcode.com/problems/validate-binary-search-tree/

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
    bool helper(TreeNode* root, long long int left, long long int right){
        if(root==NULL) return true;
        if(root->val<left || root->val>right) return false;
        if(helper(root->left,left,(long long)root->val-1) && helper(root->right,(long long)root->val+1,right)) return true;
        return false;
    }
    
    bool isValidBST(TreeNode* root) {
        return helper(root, INT_MIN, INT_MAX);
    }
};
