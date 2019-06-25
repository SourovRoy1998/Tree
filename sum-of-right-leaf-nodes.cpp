//https://practice.geeksforgeeks.org/problems/sum-of-right-leaf-nodes/1

/*This is a function problem.You only need to complete the function given below*/
/*Structure of the node of the binary tree is as
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
*/
// function should return the sum of all 
// right leaf nodes
void sumRight(Node* root,int &sum){
    if(root==NULL)
        return ;
    if(root->right!=NULL && root->right->left==NULL && root->right->right==NULL)
        sum+=root->right->data;
    sumRight(root->left,sum);
    sumRight(root->right,sum);
}

int rightLeafSum(Node* root)
{
     //Code here
     int sum=0;
     sumRight(root,sum);
     return sum;
}
