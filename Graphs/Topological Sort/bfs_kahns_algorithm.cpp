//practice.geeksforgeeks.org/problems/topological-sort/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
	vector<int> getIndegree(int V, vector<int> adj[]) {
	    vector<int> indegree(V, 0);
	    for (int node = 0; node < V; ++node) {
	        for (auto adjacentNode: adj[node]) {
	            ++indegree[adjacentNode];
	        }
	    }
	    
	    return indegree;
	}
	
	queue<int> getZeroIndegreeNodes(vector<int>& indegree) {
	    queue<int> zeroIndegreeNodes;
	    for (int node = 0; node < indegree.size(); ++node)
	        if (indegree[node] == 0)
	            zeroIndegreeNodes.push(node);
	    return zeroIndegreeNodes;
	}
	
	vector<int> getTopologicallySortedNodes(queue<int>& zeroIndegreeNodes, vector<int>& indegree, vector<int> adj[]) {
	    vector<int> result;
	    
	    while (!zeroIndegreeNodes.empty()) {
	        int currentNode = zeroIndegreeNodes.front();
	        zeroIndegreeNodes.pop();
	        
	        result.push_back(currentNode);
	        
	        for (auto adjacentNode: adj[currentNode]) {
	            --indegree[adjacentNode];
	            if (indegree[adjacentNode] == 0)
	                zeroIndegreeNodes.push(adjacentNode);
	        }
	    }
	    
	    return result;
	}
	
	vector<int> topoSort(int V, vector<int> adj[]) {
	    vector<int> indegree = getIndegree(V, adj);
	    queue<int> zeroIndegreeNodes = getZeroIndegreeNodes(indegree);
	    return getTopologicallySortedNodes(zeroIndegreeNodes, indegree, adj);
	}
};