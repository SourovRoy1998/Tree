//https://practice.geeksforgeeks.org/problems/convert-level-order-traversal-to-bst/1
//https://www.geeksforgeeks.org/construct-bst-given-level-order-traversal/



/*This is a function problem.You only need to complete the function given below*/
//User function Template for C++
/*
Structure of the Node of the node of the bst 
should be as
struct Node {
    int data;
    Node* right;
    Node* left;
    
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};
*/

Node* insert(Node* root, int val){
    if(root==NULL){
        Node* temp=new Node(val);
        return temp;
    }
    if(root->data>val)
        root->left=insert(root->left,val);
    else
        root->right=insert(root->right,val);
    return root;
}

// You are required to complete this function
Node* constructBst(int arr[], int n)
{
    if(n==0)
        return NULL;
    Node* root=NULL;
    for(int i=0;i<n;i++)
        root=insert(root,arr[i]);
    return root;
}
