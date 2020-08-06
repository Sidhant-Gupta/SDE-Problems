// link to video
// https://www.youtube.com/watch?v=AuYujVj646Q


#include <iostream>
using namespace std;
#define ll long long int

int main() {
    ll t;
    cin>>t;
    while(t--){
        ll p,q;
        cin>>p>>q;
        string s1,s2;
        cin>>s1>>s2;
        int dp[p+1][q+1];
        for(int i=0;i<=q;i++)
            dp[0][i]=i;
        for(int i=0;i<=p;i++)
            dp[i][0]=i;
        for(int i=1;i<=p;i++){
            for(int j=1;j<=q;j++){
                if(s1[i-1]==s2[j-1])
                    dp[i][j]=dp[i-1][j-1];
                else{
                    dp[i][j]=min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]))+1;
                }
            }
        }
        // for(int i=0;i<=p;i++){
        //     for(int j=0;j<=q;j++)
        //         cout<<dp[i][j]<<" ";
        //     cout<<endl;
        // }
        cout<<dp[p][q]<<endl;
    }
	return 0;
}