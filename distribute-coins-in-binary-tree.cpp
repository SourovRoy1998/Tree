//https://leetcode.com/problems/distribute-coins-in-binary-tree/


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
    int distributeCoins(TreeNode* root) {
        int ans=0;
        distribute(root,ans);
        return ans;
    }
    
    int distribute(TreeNode* root, int& ans) {
        if(root==NULL) return 0;
        int L=distribute(root->left,ans);
        int R=distribute(root->right,ans);
        ans+=abs(L)+abs(R);
        return L+R+root->val-1;
    }
};
