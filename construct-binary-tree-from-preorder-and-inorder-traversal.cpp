//https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

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
    int curr=0;
public:
    TreeNode* build(vector<int>& preorder, vector<int>& inorder,int start,int end,unordered_map<int,int>& hmap){
        if(end<start)
            return NULL;
        TreeNode* root=new TreeNode(preorder[curr++]);
        
        if(end==start)
            return root;
        int index=hmap[preorder[curr-1]];
        
        root->left=build(preorder, inorder,start,index-1,hmap);
        root->right=build(preorder, inorder,index+1,end,hmap);
        
        return root;
        
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=inorder.size();
        
        unordered_map<int,int> hmap;
        for(int i=0;i<n;i++)
            hmap[inorder[i]]=i;
        
        TreeNode* root=build(preorder, inorder,0,n-1,hmap);
        return root;
    }
};
