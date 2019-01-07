//https://leetcode.com/problems/minimum-depth-of-binary-tree/

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
    int minDepth(TreeNode* root) {
        if(!root)
            return 0;
        
        int L=minDepth(root->left);
        int R=minDepth(root->right);
        if(L==0 || R==0)
            return max(L,R)+1;
        return min(L,R)+1;
        
        
        
    }
};
