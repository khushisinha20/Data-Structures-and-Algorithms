//practice.geeksforgeeks.org/problems/topological-sort/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
	void fillIndegree(vector<int> adj[], vector<int>& indegree, int& V) {
	    for (int i = 0; i < V; ++i) {
	        for (auto adjacentVertex: adj[i]) {
	            ++indegree[adjacentVertex];
	        }
	    }
	}
	
	void storeNodesHavingZeroIndegree(queue<int>& zeroIndegreeNodes, vector<int>& indegree) {
	    for (int vertex = 0; vertex < indegree.size(); ++vertex)
	        if (indegree[vertex] == 0)
	            zeroIndegreeNodes.push(vertex);
	}
	
	void bfs(queue<int>& zeroIndegreeNodes, vector<int>& indegree, vector<int> adj[], vector<int>& topologicalSortedNodes) {
	    while (!zeroIndegreeNodes.empty()) {
	        int currentNode = zeroIndegreeNodes.front();
	        zeroIndegreeNodes.pop();
	        topologicalSortedNodes.push_back(currentNode);
	        for (auto adjacentVertex: adj[currentNode]) {
	            --indegree[adjacentVertex];
	            if (indegree[adjacentVertex] == 0)
	                zeroIndegreeNodes.push(adjacentVertex);
	        }
	    }
	}
	
	vector<int> topoSort(int V, vector<int> adj[]) {
	    vector<int> indegree(V, 0);
	    fillIndegree(adj, indegree, V);
	    queue<int> zeroIndegreeNodes;
	    storeNodesHavingZeroIndegree(zeroIndegreeNodes, indegree);
	    vector<int> topologicalSortedNodes;
	    bfs(zeroIndegreeNodes, indegree, adj, topologicalSortedNodes);
	    return topologicalSortedNodes;
	}
};