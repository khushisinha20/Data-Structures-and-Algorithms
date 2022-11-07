//leetcode.com/problems/cheapest-flights-within-k-stops/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void createAdjacencyList(vector<vector<int>>& flights, vector<vector<pair<int, int>>>& adjacencyList) {
        for (auto flight: flights) {
            adjacencyList[flight[0]].push_back({flight[1], flight[2]});
        }
    }
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adjacencyList(n);
        createAdjacencyList(flights, adjacencyList);
        vector<int> leastPrice(n, INT_MAX);
        
        queue<pair<int, pair<int, int>>> nodes;
        nodes.push({0, {src, 0}});
        leastPrice[src] = 0;
        
        while (!nodes.empty()) {
            int stops = nodes.front().first;
            int node = nodes.front().second.first;
            int price = nodes.front().second.second;
            nodes.pop();
            
            if (stops > k)
                continue;
            
            for (auto neighbour: adjacencyList[node]) {
                int adjacentNode = neighbour.first;
                int edgeWeight = neighbour.second;
                if (price + edgeWeight < leastPrice[adjacentNode] && stops <= k) {
                    leastPrice[adjacentNode] = price + edgeWeight;
                    nodes.push({stops + 1, {adjacentNode, price + edgeWeight}});
                }
            }
        }
        
        return leastPrice[dst] == INT_MAX ? -1 : leastPrice[dst];
    }
};