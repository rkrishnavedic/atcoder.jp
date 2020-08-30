#include<bits/stdc++.h>
using namespace std;

#define int long long


const int N=1e5+5;

vector<int> graph[N];
vector<int> in_degree(N,0); //number of edges to i
vector<bool> visited(N, false);
vector<int> dist(N,0);


void dfs(int a){
    visited[a]=true;
    for(auto b: graph[a]){
        //we visit the node 'b' and if there is no in_edges then we go deep othewise wait for all incoming edges to be processed....
        dist[b]=max(dist[b], dist[a]+1);
        --in_degree[b];
        if(in_degree[b]==0){
            dfs(b);
        }
    }
}

int32_t main(){
    
    
    int n,m;cin>>n>>m;
    
    for(int i=0;i<m;i++){
        int x, y;cin>>x>>y;
        graph[x].push_back(y);
        ++in_degree[y];
    }
    
    for(int i=1;i<=n;i++){
        if(!visited[i] and in_degree[i]==0){
            dfs(i);
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        ans=max(ans, dist[i]);
    }
    cout<<ans<<endl;
    
    return 0;
}
