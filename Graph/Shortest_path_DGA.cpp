// https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1

#include <bits/stdc++.h>
using namespace std;

class graph{
    public:
    unordered_map<int,list<pair<int,int>>> adj;

    void addedge(int u,int v, int weight){
        pair<int,int> p=make_pair(v,weight);
        adj[u].push_back(p);
    }

    void print(){
        for(auto i:adj){
            cout<<i.first<<" -> ";
            for(auto j:i.second){
                cout<<"("<<j.first<<","<<j.second<<")";
            }cout<<endl;
        }
    }

    void topoutil(int src,vector<bool> &visited,stack<int> &s){
        visited[src]=true;

        for(auto neighbour:adj[src]){
            if(!visited[neighbour.first])
                topoutil(neighbour.first,visited,s);
        }

        s.push(src);
    }

    void topology(stack<int> &ans){
        
        vector<bool> visited(adj.size(),false);

        for(int i=0;i<adj.size();i++){
            if(!visited[i])
                topoutil(i,visited,ans);
        }

    }

    void getshortestpath(int src,vector<int> &dest,stack<int> &topo){
        dest[src]=0;
        
        while(!topo.empty()){
            int top=topo.top();
            topo.pop();
            
            if(dest[top]!=INT_MAX){
                for(auto i:adj[top]){
                    if(dest[top] + i.second < dest[i.first]){
                        dest[i.first]=dest[top] + i.second ;
                    }
                }
            }
            
        }
    }
};

int main(){
    graph g;
    g.addedge(0,1,5);
    g.addedge(0,2,3);
    g.addedge(1,2,2);
    g.addedge(1,3,6);
    g.addedge(2,3,7);
    g.addedge(2,4,4);
    g.addedge(2,5,2);
    g.addedge(3,4,-1);
    g.addedge(4,5,-2);

    stack<int> temp;
    g.topology(temp);
    
    
    vector<int> dist(temp.size());
    for(int i=0;i<dist.size();i++){
        dist[i]=INT_MAX;
    }
    
    int src=1;
    g.getshortestpath(src,dist,temp);
    
    for(auto i:dist)
        cout<<i<<" ";
    
    return 0;
}