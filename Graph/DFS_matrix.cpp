// https://www.geeksforgeeks.org/implementation-of-dfs-using-adjacency-matrix/?ref=lbp
#include <bits/stdc++.h>
using namespace std;

// adjacency matrix
vector<vector<int> > adj;

void addEdge(int x, int y)
{
	adj[x][y] = 1;
	adj[y][x] = 1;
}

void dfs(int start, vector<bool>& visited)
{

	// Print the current node
	cout << start << " ";

	// Set current node as visited
	visited[start] = true;

	// For every node of the graph
	for (int i = 0; i < adj[start].size(); i++) {

		if (adj[start][i] == 1 && (!visited[i])) {
			dfs(i, visited);
		}
	}
}

int main()
{
	int v = 5;
	int e = 4;

	adj = vector<vector<int> >(v, vector<int>(v, 0));

	addEdge(0, 1);
	addEdge(0, 2);
	addEdge(0, 3);
	addEdge(0, 4);

	vector<bool> visited(v, false);

	dfs(0, visited);

    return 0;
}
