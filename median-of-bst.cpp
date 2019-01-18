//https://practice.geeksforgeeks.org/problems/median-of-bst/1


/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*
Structure of the binary Search Tree is as
struct Node
{
	int data;
	struct Node *left, *right;
};
*/
// your task is to complete the Function
// Note: Function should return median of the BST

void find(struct Node*root,int n,int* count,float* res){
    if(!root)
        return;
    find(root->left,n,count,res);
    if((*count)==(n-1)/2)
        (*res)+=root->data;
    if(*(count)==n/2){
        *(res)+=root->data;
        (*res)=(*res)/(float)2;
    }
    (*count)++;
    
    find(root->right,n,count,res);
}

int size(struct Node* root){
    if(!root)
        return 0;
    return size(root->left)+size(root->right)+1;
}

float findMedian(struct Node *root,int n)
{
      //Code here
      n=size(root);
      float res=0;
      int count=0;
      find(root,n,&count,&res);
      return res;
}
