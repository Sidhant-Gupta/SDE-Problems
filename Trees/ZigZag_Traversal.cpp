// https://practice.geeksforgeeks.org/problems/zigzag-tree-traversal/1/?track=ppc-trees&batchId=221

vector <int> zigZagTraversal(Node* root)
{
    vector<int>sol;sol.clear();
    if(root==NULL)
        return sol;
    
    queue<Node* >q;
    q.push(root);
    vector<int>level[10000];
    unordered_map<Node *,int>lev;
    int maxi=0;
    lev[root]=0;
    while(!q.empty()){
        Node *temp=q.front();
        q.pop();
        level[lev[temp]].push_back(temp->data);
        
        if(temp->left){
            maxi=max(maxi,lev[temp]+1);
            q.push(temp->left);
            lev[temp->left]=lev[temp]+1;
        }
        if(temp->right){
            maxi=max(maxi,lev[temp]+1);
            q.push(temp->right);
            lev[temp->right]=lev[temp]+1;
        }
        
    }
    bool flag=true;
    for(int i=0;i<=maxi;i++){
        int n=level[i].size();
        if(flag)
            for(int j=0;j<n;j++)
                sol.push_back(level[i][j]);
        else
            for(int j=n-1;j>=0;j--)
                sol.push_back(level[i][j]);
        flag=!flag;
    }
    
    
}