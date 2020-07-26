int minValue(Node* root)
{
    if(root==NULL)
        return -1;
    int ans=root->data;
    while(root->left){
        root=root->left;
        ans=root->data;
    }
    return ans;
}