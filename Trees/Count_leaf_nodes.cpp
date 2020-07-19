// https://practice.geeksforgeeks.org/problems/count-leaves-in-binary-tree/1/?track=ppc-trees&batchId=221

int c=0; 
void inorder(Node *temp){
    if(temp->left==NULL && temp->right==NULL){
        c++;
        return;
    }
    if(temp->left)  inorder(temp->left);
    if(temp->right) inorder(temp->right);
}
int countLeaves(Node* root)
{
    c=0;
    inorder(root);
    return c;
}
