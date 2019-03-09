//https://www.lintcode.com/problem/find-largest-value-in-each-tree-row/description

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
     * @param root: a root of integer
     * @return: return a list of integer
     */
    vector<int> largestValues(TreeNode * root) {
        // write your code here
        vector<int> result;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        int curr_max=INT_MIN;
        
        while(true){
            TreeNode* x = q.front();
            q.pop();
            
            if(x==NULL){
                result.push_back(curr_max);
                q.push(NULL);
                if(q.front()==NULL)
                    break;
                curr_max=INT_MIN;
            }
            
            else{
                curr_max=max(curr_max,x->val);
                if(x->left)
                    q.push(x->left);
                if(x->right)
                    q.push(x->right);
                
            }
            
            
            
        }
        return result;
    }
};
