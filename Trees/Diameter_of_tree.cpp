// https://practice.geeksforgeeks.org/problems/diameter-of-binary-tree/1/?track=ppc-trees&batchId=221

int maxi=0;
int store_ht(Node *root){
    if(root==NULL)
        return 0;
    int left_ht=store_ht(root->left);
    int right_ht=store_ht(root->right);
    maxi=max(maxi,1+left_ht+right_ht);
    return 1+max(left_ht,right_ht);
        
}
int diameter(Node* node) {
    maxi=0;
    store_ht(node);
    return maxi;
}