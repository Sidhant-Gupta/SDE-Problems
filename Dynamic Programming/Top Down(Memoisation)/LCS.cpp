// LINK TO PROBLEM
// https://practice.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/1/?track=ppc-dp&batchId=221

int dp[100][100];
int rec(int i,int j,int x,int y,string s1,string s2){
    if(i==x || j==y)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
        
    if(s1[i]==s2[j])
        dp[i][j]= 1+rec(i+1,j+1,x,y,s1,s2);
    else
       dp[i][j]=max(rec(i,j+1,x,y,s1,s2),rec(i+1,j,x,y,s1,s2)); 
    return dp[i][j];
}

int lcs(int x, int y, string s1, string s2){
    for(int i=0;i<x;i++)
        for(int j=0;j<y;j++)
            dp[i][j]=-1;
    return rec(0,0,x,y,s1,s2);
}