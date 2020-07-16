// LINK TO PROBLEM
// https://practice.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/1/?track=ppc-dp&batchId=221

int lcs(int x, int y, string s1, string s2){
    int dp[x+1][y+1];
    for(int i=0;i<=x;i++)
        dp[i][0]=0;
    for(int i=0;i<=y;i++)
        dp[0][i]=0;
    
    for(int i=1;i<=x;i++)
        for(int j=1;j<=y;j++)
            dp[i][j]=(s1[i-1]==s2[j-1]) ? dp[i-1][j-1]+1 : max(dp[i-1][j],dp[i][j-1]);
    return dp[x][y];
}