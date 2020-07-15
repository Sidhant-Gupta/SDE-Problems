// https://practice.geeksforgeeks.org/problems/subset-sum-problem2643/1/?track=ppc-dp&batchId=221

bool findPartition(int a[], int n) {
    int s=0;
    for(int i=0;i<n;i++)
        s+=a[i];
    if(s%2!=0)return false;
    s=s/2;
    bool dp[n+1][s+1];
    
    for(int i=0;i<=s;i++)
        dp[0][i]=false;
    for(int i=0;i<=n;i++)
        dp[i][0]=true;
        
    for(int i=1;i<=n;i++)
        for(int j=0;j<=s;j++)
            dp[i][j]= a[i-1]<=s ? (dp[i-1][j-a[i-1]] || dp[i-1][j]) : dp[i-1][j];
            
    return dp[n][s];
}