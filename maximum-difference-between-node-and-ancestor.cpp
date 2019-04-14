//https://leetcode.com/contest/weekly-contest-132/problems/maximum-difference-between-node-and-ancestor/

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
    vector<int> maxAnc(TreeNode* root, int &maxi){
        if(root==NULL)
            return {INT_MAX,INT_MIN};
        
        vector<int> L = maxAnc(root->left, maxi);
        vector<int> R = maxAnc(root->right, maxi);
        
        if(L[0]!=INT_MAX)
            maxi=max(maxi,abs(root->val-L[0]));
        if(L[1]!=INT_MIN)
            maxi=max(maxi,abs(root->val-L[1]));
        if(R[0]!=INT_MAX)
            maxi=max(maxi,abs(root->val-R[0]));
        if(R[1]!=INT_MIN)
            maxi=max(maxi,abs(root->val-R[1]));
       
        return {min(root->val,min(L[0],R[0])),max(root->val,max(L[1],R[1]))};
    }
    
    int maxAncestorDiff(TreeNode* root) {
        int maxi=INT_MIN;
        maxAnc(root,maxi);
        return maxi;
    }
    
    
    
};
