//https://leetcode.com/problems/convert-bst-to-greater-tree/submissions/

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
    void utility(TreeNode* root, int& sum){
        if(root==NULL)
            return;
        utility(root->right,sum);
        sum+=root->val;
        root->val=sum;
        utility(root->left,sum);
    }

    TreeNode* convertBST(TreeNode* root) {
        int sum=0;
        utility(root,sum);
        return root;
    }
};
