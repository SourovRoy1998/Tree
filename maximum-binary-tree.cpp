//https://www.lintcode.com/problem/maximum-binary-tree/description

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
     * @param nums: an array
     * @return: the maximum tree
     */
    TreeNode * constructMax(vector<int> &nums, int l, int r) {
        // Write your code here
        if(l>r)
            return NULL;
        int i=distance(nums.begin(), max_element(nums.begin()+l, nums.begin()+r+1));
        TreeNode* new_node = new TreeNode(nums[i]);
        new_node->left=constructMax(nums,l,i-1);
        new_node->right=constructMax(nums,i+1,r);
        return new_node;
        
    } 
     
    TreeNode * constructMaximumBinaryTree(vector<int> &nums) {
        // Write your code here
        return constructMax(nums, 0, nums.size()-1);
    }
};
