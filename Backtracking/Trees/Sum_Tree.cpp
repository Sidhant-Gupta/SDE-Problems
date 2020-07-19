// https://practice.geeksforgeeks.org/problems/sum-tree/1/?track=ppc-trees&batchId=221

// Write a function that returns true if the given Binary Tree of size N is SumTree else return false. A SumTree is a Binary Tree in which value of each node x 
// is equal to sum of nodes present in its left subtree and right subtree . An empty tree is SumTree and sum of an empty tree can be considered as 0.
//  A leaf node is also considered as SumTree.

bool flag=true;
int sum(Node *root){
    if(root==NULL)
        return 0;
    if(root->left==NULL && root->right==NULL)
        return root->data;
    int ans= sum(root->left)+sum(root->right);
    if(ans!=root->data)
        flag=false;
    return  root->data +ans;
}
bool isSumTree(Node* root)
{
    flag=true;
    sum(root);
    return flag;
}