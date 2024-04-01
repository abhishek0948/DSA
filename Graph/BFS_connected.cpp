// https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/
#include <bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int> >& adjList, int startNode,
		vector<bool>& visited)
{
	queue<int> q;

	visited[startNode] = true;
	q.push(startNode);

	while (!q.empty()) {

		int currentNode = q.front();
		q.pop();
		cout << currentNode << " ";

		for (int neighbor : adjList[currentNode]) {
			if (!visited[neighbor]) {
				visited[neighbor] = true;
				q.push(neighbor);
			}
		}
	}
}

// Function to add an edge to the graph
void addEdge(vector<vector<int> >& adjList, int u, int v)
{
	adjList[u].push_back(v);
}

int main()
{
	// Number of vertices in the graph
	int vertices = 5;

	// Adjacency list representation of the graph
	vector<vector<int> > adjList(vertices);

	// Add edges to the graph
	addEdge(adjList, 0, 1);
	addEdge(adjList, 0, 2);
	addEdge(adjList, 1, 3);
	addEdge(adjList, 1, 4);
	addEdge(adjList, 2, 4);

	// Mark all the vertices as not visited
	vector<bool> visited(vertices, false);
	cout << "Breadth First Traversal starting from vertex "
			"0: ";
	bfs(adjList, 0, visited);

	return 0;
}
