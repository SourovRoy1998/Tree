//https://leetcode.com/problems/unique-binary-search-trees-ii/

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
    vector<TreeNode*> generate(int start, int end){
        vector<TreeNode*> result;
        if(start>end){
            result.push_back(NULL);
            return result;
        }
        for(int i=start;i<=end;i++){
            vector<TreeNode*> leftTrees=generate(start,i-1);
            vector<TreeNode*> rightTrees=generate(i+1,end); 
            for(int j=0;j<leftTrees.size();j++)
                for(int k=0;k<rightTrees.size();k++){
                    TreeNode* node=new TreeNode(i);
                    node->left=leftTrees[j];
                    node->right=rightTrees[k];
                    result.push_back(node);
                }
            
        }
        return result;
    } 
    
    
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0) return vector<TreeNode*>(0);
        return generate(1,n);
    }
};
