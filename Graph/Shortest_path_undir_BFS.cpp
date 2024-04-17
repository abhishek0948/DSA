//https://www.naukri.com/code360/problems/shortest-path-in-an-unweighted-graph_981297?leftPanelTab=0&leftPanelTabValue=PROBLEM

#include <bits/stdc++.h>
using namespace std;
vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	
	unordered_map<int,list<int>> adj;

	for(int i=0;i<edges.size();i++){
		int u=edges[i].first ;
		int v=edges[i].second ;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	unordered_map<int,int> parent;
	unordered_map<int ,bool> visited;
	
	queue<int> q;
	q.push(s);

	parent[s]=-1;
	visited[s]=true;

	while(!q.empty()){

		int front=q.front();
		q.pop();

		for(auto neighbour:adj[front]){
			if(!visited[neighbour]){
				parent[neighbour]=front;
				visited[neighbour]=true;
				q.push(neighbour);
			}
		}

	}

	vector<int> ans;
	int currnode=t;
	ans.push_back(t);

	while(currnode != s){
		currnode=parent[currnode];
		ans.push_back(currnode);
	}

	reverse(ans.begin(),ans.end());
	return ans;

}
