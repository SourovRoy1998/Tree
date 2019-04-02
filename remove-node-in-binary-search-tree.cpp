//https://www.lintcode.com/problem/remove-node-in-binary-search-tree/description


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
    /*
     * @param root: The root of the binary search tree.
     * @param value: Remove the node with given value.
     * @return: The root of the binary search tree after removal.
     */
    TreeNode * removeNode(TreeNode * root, int value) {
        // write your code here
        if(root==NULL)
            return NULL;
            
            
        TreeNode* temp;    
        if(root->val>value)
            root->left=removeNode(root->left, value);
        else if(root->val<value)
            root->right=removeNode(root->right, value);
        
        else{
            
            if(root->left==NULL){
                temp= root->right;
                free(root);
                return temp;
            }
            
            else if(root->right==NULL){
                temp=root->left;
                free(root);
                return temp;
            }
            
            else{
                temp=root->right;
                while(temp->left)
                    temp=temp->left;
                root->val=temp->val;
                root->right=removeNode(root->right, temp->val);
            }
            
            return root;
        }
        
    }
};
