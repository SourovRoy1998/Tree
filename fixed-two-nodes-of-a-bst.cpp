//https://practice.geeksforgeeks.org/problems/fixed-two-nodes-of-a-bst/1

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*Complete the function
Node is as follows:
struct node
{
    int data;
    struct node *left, *right;
};
*/
void inorder(struct node* root, struct node*  &first_node, struct node*  &second_node, struct node* &prev_node){
    if(root==NULL)
        return;
    inorder(root->left, first_node, second_node, prev_node);
    
    if(prev_node!=NULL && prev_node->data>root->data){
        if(first_node==NULL)
            first_node=prev_node;
        second_node=root;
    }
    prev_node=root;
    inorder(root->right, first_node, second_node, prev_node);
}


struct node *correctBST( struct node* root )
{
//add code here.
    struct node* first_node=NULL;
    struct node* second_node=NULL;
    struct node* prev_node=NULL;
    inorder(root, first_node, second_node, prev_node);
    swap(first_node->data, second_node->data);
    return root;
}    
