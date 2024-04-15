// https://www.geeksforgeeks.org/topological-sorting/
// https://www.naukri.com/code360/problems/topological-sort_982938?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&leftPanelTabValue=PROBLEM

#include <bits/stdc++.h> 
using namespace std;
void dfs(unordered_map<int,list<int>> &adj,vector<bool> &visited,int src,stack<int> &s){
    visited[src]=true;

    for(auto neighbour:adj[src]){
        if(!visited[neighbour])
            dfs(adj,visited,neighbour,s);
    }

    s.push(src);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    unordered_map<int,list<int>> adj;

    for(int i=0;i<e;i++){
        int u=edges[i][0];
        int v=edges[i][1];

        adj[u].push_back(v);
    }

    vector<bool> visited(v);
    stack<int> s;

    for(int i=0;i<v;i++){
        if(!visited[i]){
            dfs(adj,visited,i,s);
        }
    }

    vector<int> ans;
    while(!s.empty()){
        int top=s.top();
        s.pop();
        ans.push_back(top);
    }
    
    return ans;
};