// https://practice.geeksforgeeks.org/problems/subset-sum-problem2643/1/?track=ppc-dp&batchId=221

int dp[100][100000];
int rec(int aval[],vector<int> chosen,int s,int ind,int n){
    int sum=accumulate(chosen.begin(),chosen.end(),0);
    if(sum==s)  return true;
    if(sum>s)   return false;
    if(ind==n)  return false;
    if(dp[ind][sum]!=-1)return dp[ind][sum];
    
    bool ans1=rec(aval,chosen,s,ind+1,n);
    chosen.push_back(aval[ind]);
    bool ans2=rec(aval,chosen,s,ind+1,n);
    dp[ind][sum]= ans1||ans2 ? 1:0;
    return dp[ind][sum];
}

bool findPartition(int a[], int n) {
    vector<int>chosen;
    int s=accumulate(a,a+n,0);
    if(s%2!=0)return false;
    // int dp[n][s/2];
    
    for(int i=0;i<n;i++)
        for(int j=0;j<s/2;j++)
            dp[i][j]=-1;
    return rec(a,chosen,s/2,0,n)?true:false;
}