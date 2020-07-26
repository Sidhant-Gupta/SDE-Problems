// https://practice.geeksforgeeks.org/problems/kth-largest-element-in-bst/1/?track=ppc-bst&batchId=221

// O(h+k) time ,O(1)
int ans;int c;
void inorder(Node *root,int k){
    if(root==NULL)
        return;
    if(root->right)  
        inorder(root->right,k);
    c++;
    if(c==k){
        ans=root->data;
        return;
    }
    if(root->left)
        inorder(root->left,k);
}
int kthLargest(Node *root, int K)
{
    ans=-1;c=0;
    inorder(root,K);
    return ans;
}