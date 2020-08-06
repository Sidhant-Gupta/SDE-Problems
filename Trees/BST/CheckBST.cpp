// https://practice.geeksforgeeks.org/problems/check-for-bst/1

vector<int>sol;
void inorder(Node* root){
    if(root==NULL)
        return;
    inorder(root->left);
    sol.push_back(root->data);
    inorder(root->right);
}
bool isBST(Node* root) {
    sol.clear();
    inorder(root);
    for(int i=1;i<sol.size();i++){
        if(sol[i]<=sol[i-1])
            return false;
    }
    return true;
}