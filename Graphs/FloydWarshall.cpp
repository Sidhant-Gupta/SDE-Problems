// n vertices,m edges, m lines follow->edges. (enter u,v, cost)
// enter q.q queries follow. enter src and destination .tell shortest dist between src and dest for all queries.


#include<bits/stdc++.h>
using namespace std;
#define tezz_chal ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long int

ll adj_mat[100][100];

void floyd_warshall(int n){
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(adj_mat[i][j]>adj_mat[i][k]+adj_mat[k][j]){
                    adj_mat[i][j]=adj_mat[i][k]+adj_mat[k][j];
                }
            }
        }
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            adj_mat[i][j]=1e9;
        }
    }
    int u,v,d;
    for(int i=0;i<m;i++){
        cin>>u>>v>>d;
        adj_mat[u-1][v-1]=d;
        adj_mat[v-1][u-1]=d;
    }

    floyd_warshall(n);

    int q;
    cin>>q;
    while(q--){
        string src,dest;
        cin>>src>>dest;
        cout<<adj_mat[mp[src]][mp[dest]]<<endl;
    }


}