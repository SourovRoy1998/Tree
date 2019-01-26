//https://practice.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* A binary tree node has data, pointer to left child
   and a pointer to right child 
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */
void vOrder(Node* root, int hd, map<int,vector<int>>&hmap){
    if(root==NULL)
        return;
    hmap[hd].push_back(root->data);
    
    vOrder(root->left,hd-1,hmap);
    vOrder(root->right,hd+1,hmap);
    
}


void verticalOrder(Node *root)
{
    map<int,vector<int>> hmap;
    int hd=0;
    vOrder(root,hd,hmap);
    
    for(auto x:hmap){
        for(int i=0;i<x.second.size();i++)
            cout<<x.second[i]<<" ";
    }
    
}
