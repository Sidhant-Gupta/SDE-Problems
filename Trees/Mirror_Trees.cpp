// https://practice.geeksforgeeks.org/problems/two-mirror-trees/1/?track=ppc-trees&batchId=221

// RECURSIVE APPROACH
int areMirror(Node* a, Node* b) {
    if(a==NULL && b==NULL)
        return 1;
    if(a==NULL || b==NULL)
        return 0;
    if(a->data != b->data)
        return 0;
    return areMirror(a->right,b->left) && areMirror(a->left,b->right);
}



// ITERATIVE
int areMirror(Node* a, Node* b) {
    queue<Node *>q1;
    queue<Node *>q2;
    q1.push(a);
    q2.push(b);
    
    bool flag=1;
    while(!q1.empty() && !q2.empty()){
        Node *temp1=q1.front();
        Node *temp2=q2.front();
        q1.pop();
        q2.pop();
        // cout<<temp1->data<<" "<<temp2->data<<endl;
        if(temp1->data!=temp2->data){
            flag=0;
            break;
        }
        
        if(temp1->right)
            q1.push(temp1->right);
        if(temp1->left)
            q1.push(temp1->left);
        if(temp2->left)
            q2.push(temp2->left);
        if(temp2->right)
            q2.push(temp2->right);
    }
    return flag;
}
