// https://practice.geeksforgeeks.org/problems/root-to-leaf-path-sum/1/?track=ppc-trees&batchId=221

bool flag=false;
void trav(Node *root,int add,int sum){
    if(root==NULL){
        if(add==sum)
            flag=true;
        return;
    }
    root->data=root->data +add;
    trav(root->left,root->data,sum);
    trav(root->right,root->data,sum);
    
}
bool hasPathSum(Node *node, int sum) {
    flag=false;
    trav(node,0,sum);
    return flag;
}