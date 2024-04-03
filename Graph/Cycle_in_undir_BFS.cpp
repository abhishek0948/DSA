// https://takeuforward.org/data-structure/detect-cycle-in-an-undirected-graph-using-bfs/

#include <bits/stdc++.h>
using namespace std;
bool isCycle(int src,unordered_map<int,list<int>> &adj,unordered_map<int,bool> &visited){
    unordered_map<int , int> parent;

    parent[src]=-1;
    visited[src]=1;

    queue<int> q;
    q.push(src);

    while(!q.empty()){
        int front=q.front();
        q.pop();

        for(auto neighbour:adj[front]){
            if(visited[neighbour] && neighbour!=parent[front])
                return true;
            else if(!visited[neighbour]){
                q.push(neighbour);  
                visited[neighbour]=true;
                parent[neighbour]=front;
            }
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

    unordered_map<int,bool> visited;

    for(int i=0;i<n;i++){
        if(!visited[i]){
            bool ans=isCycle(i,adj,visited);

            if(ans)
                return "Yes";
        }
    }

    return "No";
}
