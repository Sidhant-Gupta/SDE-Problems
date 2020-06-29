// Given a Directed and Acyclic Graph having N vertices and M edges, print topological sorting of the vertices.

// Input:
// First line consists of two space separated integers denoting N and M.
// Each of the following M lines consists of two space separated integers X and Y denoting there is an from X directed towards Y.

// Output:
// Print N space separated integers denoting the topological sort, if there are multiple ordering print the lexicographically smallest one.

// Constraints:
// 1<=n<=10
// 1<=M<=20
// 1<=X,Y<=10


#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define tezz_chal ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

vector<int>adj[11];
bool visited[11];
vector<int>sol;

void topo_sort(ll src){
	visited[src]=true;
	ll n=adj[src].size();
	for(ll i=0;i<n;i++){
		if(!visited[adj[src][i]])
			topo_sort(adj[src][i]);
	}
	sol.insert(sol.begin(),src+1);

}

int main(){
	tezz_chal;
	ll n,m;
	cin>>n>>m;
	sol.clear();
	ll in_deg[n];
	for(ll i=0;i<n;i++){
		visited[i]=false;
		adj[i].clear();
		in_deg[i]=0;
	}
	for(ll i=0,i<m;i++){
		ll x,y;
		cin>>x>>y;
		adj[x-1].push_back(y-1);
		in_deg[y-1]++;
	}
	
	for(ll i=n-1;i>=0;i--){
		if(in_deg[i]==0 && visited[i]==false){
			topo_sort(i);
		}
	}
	for(ll i=0;i<sol.size();i++)
		cout<<sol[i]<<" ";
	cout<<endl;

}


// SAMPLE INPUT
// 5 6
// 1 2
// 1 3
// 2 3
// 2 4
// 3 4
// 3 5

// OUTPUT
// 1 2 3 4 5 