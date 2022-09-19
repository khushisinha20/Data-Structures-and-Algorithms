//practice.geeksforgeeks.org/problems/topological-sort/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
	void findTopoSort(vector<int>& topologicalSortedNodes, stack<int>& nodes) {
	    while (!nodes.empty()) {
	        topologicalSortedNodes.push_back(nodes.top());
	        nodes.pop();
	    }
	}
	
	void dfs(int source, stack<int>& nodes, vector<bool>& visited, vector<int> adj[]) {
	    visited[source] = true;
	    for (auto adjacentVertex: adj[source]) {
	        if (!visited[adjacentVertex])
	            dfs(adjacentVertex, nodes, visited, adj);
	    }
	    nodes.push(source);
	}
	
	vector<int> topoSort(int V, vector<int> adj[]) {
	    vector<int> topologicalSortedNodes;
	    stack<int> nodes;
	    vector<bool> visited(V, false);
	    for (int vertex = 0; vertex < V; ++vertex) {
	        if (!visited[vertex])
	            dfs(vertex, nodes, visited, adj);
	    }
	    findTopoSort(topologicalSortedNodes, nodes);
	    return topologicalSortedNodes;
	}
};