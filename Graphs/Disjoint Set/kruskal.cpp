#include<bits/stdc++.h>
using namespace std;

class Solution {
	public:
	class disjointSet {
        vector<int> parent;
        vector<int> rank;
        public:
        disjointSet(int n) {
            parent.resize(n + 1);
            rank.resize(n + 1, 0);
            for (int i = 0; i <= n; ++i)
                parent[i] = i;
        }
        
        int find(int x) {
            if (x == parent[x])
                return x;
            parent[x] = find(parent[x]);
            return parent[x];
        }
        
        void unionByRank(int x, int y) {
            int parentOfX = parent[x];
            int parentOfY = parent[y];
            if (parentOfX == parentOfY)
                return;
            if (rank[parentOfX] < rank[parentOfY])
                parent[parentOfX] = parentOfY;
            else if (rank[parentOfY] < rank[parentOfX])
                parent[parentOfY] = parentOfX;
            else {
                parent[parentOfY] = parentOfX;
                ++rank[parentOfX];
            }
        }
    };
	
	void findEdges(vector<pair<int, pair<int, int>>>& edges, vector<vector<int>> adj[], int& V) {
	    for (int i = 0; i < V; ++i) {
	        for (auto neighbour: adj[i]) {
	            int adjacentNode = neighbour[0];
	            int edgeWeight = neighbour[1];
	            int currentNode = i;
	            
	            edges.push_back({edgeWeight, {currentNode, adjacentNode}});
	        }
	    }
	}
	
	int spanningTree(int V, vector<vector<int>> adj[]) {
	    vector<pair<int, pair<int, int>>> edges;
	    findEdges(edges, adj, V);
	    disjointSet ds(V);
	    sort(edges.begin(), edges.end());
	    int weightOfMST = 0;
	    
	    for (auto edge: edges) {
	        int edgeWeight = edge.first;
	        int u = edge.second.first;
	        int v = edge.second.second;
	        
	        if (ds.find(u) != ds.find(v)) {
	            weightOfMST += edgeWeight;
	            ds.unionByRank(u, v);
	        }
	    }
	    
	    return weightOfMST;
    }
};