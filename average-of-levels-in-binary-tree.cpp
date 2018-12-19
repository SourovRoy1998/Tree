//https://leetcode.com/problems/average-of-levels-in-binary-tree/

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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>vtr;
        queue<TreeNode*>q;
        q.push(root);
        q.push(nullptr);
        long int temp=0;
        long int count=0;
        TreeNode* prev=nullptr;
        while(!q.empty()){
            if(prev==nullptr && q.front()==nullptr)
                break;
            
            if(q.front()==nullptr){
                vtr.push_back(temp/(double)count);
                temp=0;
                count=0;
                q.push(nullptr);
                q.pop();
                prev=nullptr;
            }
            else{
                TreeNode* newNode=q.front();
                temp+=newNode->val;
                count+=1;
                if(newNode->left)
                    q.push(newNode->left);
                if(newNode->right)
                    q.push(newNode->right);
                prev=newNode;
                q.pop();
                    
            }
            
            
            
            
        }
        return vtr;
        
        
    }
};
