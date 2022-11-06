#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
	vector <int> dijkstra(int V, vector<vector<int>> adj[], int S) {
	    vector<int> shortestDistance(V, INT_MAX);
	    shortestDistance[S] = 0;
	    
	    set<pair<int, int>> nodes;
	    nodes.insert({0, S});
	    
	    while (!nodes.empty()) {
	        auto neighbour = *(nodes.begin());
	        int currentNode = neighbour.second;
	        int currentDistance = neighbour.first;
	        nodes.erase(nodes.begin());
	        
	        for (auto neighbours: adj[currentNode]) {
	            int adjacentNode = neighbours[0];
	            int edgeWeight = neighbours[1];
	            if (currentDistance + edgeWeight < shortestDistance[adjacentNode]) {
	                if (shortestDistance[adjacentNode] != INT_MAX)
	                    nodes.erase({shortestDistance[adjacentNode], adjacentNode});
	                shortestDistance[adjacentNode] = currentDistance + edgeWeight;
	                nodes.insert({shortestDistance[adjacentNode], adjacentNode});
	            }
	        }
	    }
	    return shortestDistance;
    }
};