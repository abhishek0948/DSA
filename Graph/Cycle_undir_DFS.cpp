// https://takeuforward.org/data-structure/cycle-detection-in-undirected-graph-using-dfs/
#include <bits/stdc++.h>
using namespace std;
bool isCycleDFS(int node,int parent,unordered_map<int,list<int>> &adj,unordered_map<int,bool> &vis){
    vis[node]=true;

    for(auto neighbour:adj[node]){
        if(!vis[neighbour]){
            bool ispresent=isCycleDFS(neighbour,node,adj,vis);
            if(ispresent)
                return true;
        }

        else if(neighbour!=parent){
            return true;
        }
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    unordered_map<int,list<int>> adj;

    for(int i=0;i<m;i++){
        int u=edges[i][0];
        int v=edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    unordered_map<int,bool> vis;
    
    for(int i=0;i<n;i++){
        if(!vis[i]){
            bool ans=isCycleDFS(i,-1,adj,vis);
            if(ans)
                return "Yes";
        }
    }
    return "No";
}
