// You are given 2 integers(N,M) , N is the number of vertices, M is the number of edges. You'll also be given  ai,bi , wi where ai and bi represents an edge from a
//  vertex ai to a vertex bi  and  wi respresents the weight of that edge.
// Task is to find the shortest path from source vertex (vertex number 1) to all other vertices (vi) where ()
// Input:
// First line contains two space separated integers,(N,M)  Then M lines follow, each line has 3 space separated integers ai ,bi ,wi .

#include<bits/stdc++.h>
using namespace std;
#define tezz_chal ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long int

vector<int>edges[1000001];
int dist[1000001];

void bellmanFord(int n){
    for(ll i=0;i<n-1;i++){
        int k=0;
        while(edges[k].size()>0){
            ll u=edges[k][1],v=edges[k][2],w=edges[k][0];
            if(dist[v]>dist[u]+w){
                dist[v]=dist[u]+w;
            }
            k++;
        }
    }
}

int main(){
    tezz_chal;
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        edges[i].clear();
        dist[i]=1e9;
    }
    
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        edges[i].push_back(w);
        edges[i].push_back(u-1);
        edges[i].push_back(v-1);
    }
    dist[0]=0;

    bellmanFord(n);

    for(int i=1;i<n;i++){
       cout<<dist[i]<<" ";
    }
}