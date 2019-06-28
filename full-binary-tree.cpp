//https://practice.geeksforgeeks.org/problems/full-binary-tree/1


bool isFull(struct Node* root, bool& full){
    if(root==NULL)
        return 0;
    int left=isFull(root->left,full);
    int right=isFull(root->right,full);
    if(left!=right)
        full=false;
    return max(left,right)+1;
}


bool isFullTree (struct Node* root)
{
//add code here.
    bool full=true;
    isFull(root,full);
    return full;
}
