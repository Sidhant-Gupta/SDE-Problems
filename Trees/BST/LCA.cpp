// https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-bst/1/?track=ppc-bst&batchId=221
Node* lca(Node *root,int n1,int n2){
    if(root==NULL)
        return root;
   
    if(root->data > n1 && root->data > n2)
        return lca(root->left,n1,n2);
    else if(root->data <n1 && root->data <n2)
        return lca(root->right,n1,n2);
    return root;
}
Node* LCA(Node *root, int n1, int n2)
{
    if(n2>n1){
        int temp=n1;
        n1=n2;
        n2=temp;
    }
    return lca(root,n1,n2);
}