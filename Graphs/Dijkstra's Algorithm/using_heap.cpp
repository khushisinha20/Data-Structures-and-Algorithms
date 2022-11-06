#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
	vector <int> dijkstra(int V, vector<vector<int>> adj[], int S) {
	    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
	    minHeap.push({0, S});
	    vector<int> shortestDistance(V, INT_MAX);
	    shortestDistance[S] = 0;
	    while (!minHeap.empty()) {
	        int currentNode = minHeap.top().second;
	        int currentDistance = minHeap.top().first;
	        minHeap.pop();
	        for (auto neighbours: adj[currentNode]) {
	            int edgeWeight = neighbours[1];
	            int adjacentNode = neighbours[0];
	            if (edgeWeight + currentDistance < shortestDistance[adjacentNode]) {
	                shortestDistance[adjacentNode] = edgeWeight + currentDistance;
	                minHeap.push({shortestDistance[adjacentNode], adjacentNode});
	            }
	        }
	    }
	    return shortestDistance;
    }
};