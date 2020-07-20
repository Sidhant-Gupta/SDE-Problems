// https://practice.geeksforgeeks.org/problems/vertical-sum/1/?track=ppc-trees&batchId=221

unordered_map<int,int>mp;int mini=0,maxi=0;

void preorder(Node *root,int sideLevel){
    if(root==NULL)
        return;
    mp[sideLevel]=mp.find(sideLevel)==mp.end() ? root->data : mp[sideLevel] + root->data;
    mini=min(mini,sideLevel);
    maxi=max(maxi,sideLevel);

    preorder(root->left,sideLevel-1);
    preorder(root->right,sideLevel+1);
}

vector <int> verticalSum(Node *root) {
    vector<int>sol;mini=0,maxi=0;mp.clear();

    preorder(root,0);
    for(int i=mini;i<=maxi;i++)
        sol.push_back(mp[i]);
    return sol;
}