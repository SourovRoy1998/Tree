//https://www.lintcode.com/problem/find-bottom-left-tree-value/description



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
     * @param root: a root of tree
     * @return: return a integer
     */
    void find(TreeNode* root, int &value,int level, int &maxlevel){
        if(root==NULL)
            return;
        find(root->left,value, level+1, maxlevel);
        
        if(level>maxlevel){
            value=root->val;
            maxlevel=level;
        }
        find(root->right,value, level+1, maxlevel);
    } 
    
     
    int findBottomLeftValue(TreeNode * root) {
        // write your code here
        int value, maxlevel=0;
        find(root, value, 1, maxlevel);
        return value;
    }
};
