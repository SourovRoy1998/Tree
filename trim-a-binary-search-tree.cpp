//https://www.lintcode.com/problem/trim-a-binary-search-tree/description


/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param root: given BST
     * @param minimum: the lower limit
     * @param maximum: the upper limit
     * @return: the root of the new tree 
     */
     
    void trim(TreeNode* &root, int minimum , int maximum){
        if(root==NULL)
            return;
        while(root && root->val>maximum)
            root=root->left;
        while(root && root->val<minimum)
            root=root->right;    
            
        if(root->left && root->left->val<minimum){
            root->left=root->left->right;
            trim(root,minimum,maximum);
        }
            
        if(root->right && root->right->val>maximum){
            root->right=root->right->left;
            trim(root,minimum,maximum);
        }
            
        trim(root->left,minimum,maximum);
        trim(root->right,minimum,maximum);
            
        
    } 
     

    TreeNode * trimBST(TreeNode * root, int minimum, int maximum) {
        // write your code here
        trim(root,minimum,maximum);
        return root; 
        
    }
};
