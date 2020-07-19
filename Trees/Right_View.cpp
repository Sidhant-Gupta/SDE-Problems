//https://practice.geeksforgeeks.org/problems/right-view-of-binary-tree/1/?track=ppc-trees&batchId=221
void rightView(Node *root)
{
    if(root==NULL)
        return;

    queue<Node *>q;
    q.push(root);

    map<int,Node *>mp;
    unordered_map<Node *,int>level;

    level[root]=1;mp[1]=root; 

    while(!q.empty()){
        Node *temp=q.front();
        q.pop();
        
        if(temp->left){
            mp[level[temp]+1]=temp->left;
            q.push(temp->left);
            level[temp->left]=level[temp]+1;
        }
        if(temp->right){
            mp[level[temp]+1]=temp->right;
            q.push(temp->right);
            level[temp->right]=level[temp]+1;
        }
    }
    for(auto i=mp.begin();i!=mp.end();i++){
        cout<<i->second->data<<" ";
    }
    
}