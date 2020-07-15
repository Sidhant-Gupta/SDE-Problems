// LINK TO THE PROBLEM
// https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1/?track=ppc-dp&batchId=221

int dp[1000][1000];
int kp(int ind,int wt[],int val[],int n,int cap){
    if(ind==n || cap==0)
        return 0;
    if(dp[ind][cap]!=-1)
        return dp[ind][cap];
    int ans1,ans2;
    ans1= wt[ind]<=cap ? val[ind]+kp(ind+1,wt,val,n,cap-wt[ind]) : 0;
    ans2=kp(ind+1,wt,val,n,cap);
    dp[ind][cap]= max(ans1,ans2);
    return dp[ind][cap];
}

int knapSack(int W, int wt[], int val[], int n) 
{ 
    for(int i=0;i<n;i++)
        for(int j=0;j<=W;j++)
            dp[i][j]=-1;
    return kp(0,wt,val,n,W);
}