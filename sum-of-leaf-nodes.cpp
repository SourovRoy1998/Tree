//https://practice.geeksforgeeks.org/problems/sum-of-leaf-nodes/1


/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*Structure of the node of the binary tree is as
struct Node
{
	int data;
	Node *left, *right;
};*/
// function should return the sum of all the 
// leaf nodes of the binary tree 

void L_sum(Node* root,int &ans){
    if(!root)
        return;
    if(!root->left && !root->right)
        ans+=root->data;
    L_sum(root->left,ans);
    L_sum(root->right,ans);
}

int sumLeaf(Node* root)
{
    // Code here
    int ans=0;
    L_sum(root,ans);
    return ans;
}
