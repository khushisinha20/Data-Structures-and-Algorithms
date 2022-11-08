//leetcode.com/problems/number-of-ways-to-arrive-at-destination/

#include <bits/stdc++.h>
#include <climits>
using namespace std;

class Solution {
public:
    void createAdjacencyList(vector<vector<pair<long long, long long>>>& adjacencyList, vector<vector<int>>& roads) {
        for (auto road: roads) {
            adjacencyList[road[0]].push_back({road[1], road[2]});
            adjacencyList[road[1]].push_back({road[0], road[2]});
        }
    }
    
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<long long, long long>>> adjacencyList(n);
        createAdjacencyList(adjacencyList, roads);
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> minHeap;
        vector<long long> shortestTime(n, 1e18);
        vector<long long> waysToReach(n, 0);
        minHeap.push({0, 0});
        waysToReach[0] = 1;
        shortestTime[0] = 0;
        int MOD = 1000000007;
        
        while (!minHeap.empty()) {
            long long timeTaken = minHeap.top().first;
            long long currentCity = minHeap.top().second;
            minHeap.pop();
            
            for (auto neighbour: adjacencyList[currentCity]) {
                long long edgeWeight = neighbour.second;
                long long adjacentCity = neighbour.first;
                if (timeTaken + edgeWeight < shortestTime[adjacentCity]) {
                    shortestTime[adjacentCity] = timeTaken + edgeWeight;
                    minHeap.push({shortestTime[adjacentCity], adjacentCity});
                    waysToReach[adjacentCity] = waysToReach[currentCity] % MOD;
                } else if (timeTaken + edgeWeight == shortestTime[adjacentCity]) {
                    waysToReach[adjacentCity] = (waysToReach[currentCity] + waysToReach[adjacentCity]) % MOD;
                }
            }
        }
        return waysToReach[n - 1] % MOD;
    }
};