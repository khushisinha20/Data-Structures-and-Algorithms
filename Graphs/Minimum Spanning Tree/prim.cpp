#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
	int spanningTree(int V, vector<vector<int>> adj[]) {
	    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
	    minHeap.push({0, 0});
	    
	    int weightOfMST = 0;
	    vector<bool> visited(V, false);
	    
	    while (!minHeap.empty()) {
	        int currentVertex = minHeap.top().second;
	        int edgeWeight = minHeap.top().first;
	        minHeap.pop();
	        
	        if (visited[currentVertex])
	            continue;
	        visited[currentVertex] = true;
	        weightOfMST += edgeWeight;
	        
	        for (auto neighbour: adj[currentVertex]) {
	            int adjacentVertex = neighbour[0];
	            int weight = neighbour[1];
	            
	            minHeap.push({weight, adjacentVertex});
	        }
	    }
	    
	    return weightOfMST;
    }
};
	        