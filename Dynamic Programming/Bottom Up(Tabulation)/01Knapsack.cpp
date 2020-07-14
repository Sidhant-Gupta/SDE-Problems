// LINK TO THE PROBLEM
// https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1/?track=ppc-dp&batchId=221

int knapSack(int W, int wt[], int val[], int n) 
{ 
    int dp[n+1][W+1];
    for(int i=0;i<=W;i++)
        dp[0][i]=0;
        
    for(int i=1;i<=n;i++){
        for(int j=0;j<=W;j++){
            dp[i][j]= (wt[i-1]<=j) ? max(dp[i-1][j-wt[i-1]]+val[i-1],dp[i-1][j]) : dp[i-1][j]; 
    
    return dp[n][W];
}