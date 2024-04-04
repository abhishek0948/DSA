// https://takeuforward.org/data-structure/detect-a-cycle-in-directed-graph-using-dfs/

#include <bits/stdc++.h>
using namespace std;
bool findCycleDFS(int src,unordered_map<int,list<int>> &adj,unordered_map<int,bool> &vis,unordered_map<int,bool> &dfs){
  
  vis[src]=true;
  dfs[src]=true;

  for(auto neighbour:adj[src]){

    if(!vis[neighbour]){
      bool ispresent=findCycleDFS(neighbour,adj,vis,dfs);
      if(ispresent)
        return true;
    }

    else if(vis[neighbour] && dfs[neighbour]==true){
      return true;
    }

  }
  
  dfs[src]=false;
  return false;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  unordered_map<int,list<int>> adj;

  for(int i=0;i<edges.size();i++){
    int u=edges[i].first;
    int v=edges[i].second;

    adj[u].push_back(v);
  }

  unordered_map<int,bool> vis;
  unordered_map<int,bool> dfs;

  for(int i=0;i<n;i++){
    if(!vis[i]){
      bool ans=findCycleDFS(i,adj,vis,dfs);
      if(ans)
        return 1;
    }
  }

  return 0;
}