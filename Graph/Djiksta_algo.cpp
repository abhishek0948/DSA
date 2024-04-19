// https://www.naukri.com/code360/problems/dijkstra-s-shortest-path_920469?leftPanelTab=0&leftPanelTabValue=PROBLEM
#include <bits/stdc++.h> 
using namespace std;
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    unordered_map< int , list< pair<int,int> > > adj;

    for(int i=0; i<edges; i++){
        int u = vec[i][0];
        int v = vec[i][1];
        int wt = vec[i][2];

        adj[u].push_back(make_pair(v,wt));
        adj[v].push_back(make_pair(u,wt));
    }

    vector<int> dist(vertices);
    for(int i=0; i<vertices ; i++)
        dist[i]=INT_MAX;
    
    dist[source]=0;
    
    set<pair<int,int>> djk;
    djk.insert(make_pair(0,source));

    while(!djk.empty()){

        auto top = *(djk.begin());
        djk.erase(djk.begin());
        
        int nodedist = top.first;
        int topnode = top.second;

        for(auto neighbour : adj[topnode]){

            if( nodedist + neighbour.second < dist[neighbour.first] ){

                auto record= djk.find(make_pair(dist[neighbour.first],neighbour.first));

                if(record!=djk.end()){
                    djk.erase(record);
                }
                
                dist[neighbour.first] = nodedist + neighbour.second;

                djk.insert(make_pair(dist[neighbour.first],neighbour.first));

            }
        }  
         
    }
    
    return dist;
}
