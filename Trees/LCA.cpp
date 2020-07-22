// https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1/?track=ppc-trees&batchId=221

Node* lca(Node* root ,int n1 ,int n2 )
{
    if(root==NULL)
        return NULL;
    if(root->data==n1 || root->data==n2)
        return root;
    Node *llca=lca(root->left,n1,n2);
    Node *rlca=lca(root->right,n1,n2);
    if(llca && rlca)
        return root;
    return llca!=NULL? llca:rlca;
}