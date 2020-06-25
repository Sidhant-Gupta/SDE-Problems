// You are given 2 integers(N,M) , N is the number of vertices, M is the number of edges. You'll also be given  ai,bi , wi where ai and bi represents an edge from a
//  vertex ai to a vertex bi  and  wi respresents the weight of that edge.
// Task is to find the shortest path from source vertex (vertex number 1) to all other vertices (vi) where ()
// Input:
// First line contains two space separated integers,(N,M)  Then M lines follow, each line has 3 space separated integers ai ,bi ,wi .


#include<bits/stdc++.h>
using namespace std;
#define tezz_chal ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

vector<pair<int,int> >adj[1000001];
int dist[1000001];

int main(){
    tezz_chal;
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        adj[i].clear();
        dist[i]=2e9;
    }
    
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u-1].push_back(make_pair(v-1,w));
    }
    dist[0]=0;
    priority_queue< pair<int,int> ,vector< pair<int,int> >, greater< pair<int,int>> >pq;
    pq.push(make_pair(0,0));

    while(!pq.empty()){
        int u=pq.top().second;
        pq.pop();
        int n=adj[u].size();
        for(int i=0;i<n;i++){
            if(dist[adj[u][i].first] >adj[u][i].second +dist[u]  ){
                dist[adj[u][i].first]=adj[u][i].second +dist[u];
                pq.push(make_pair(dist[adj[u][i].first],adj[u][i].first));
            }
        }
    }
    for(int i=1;i<n;i++){
       cout<<dist[i]<<" ";
    }


}