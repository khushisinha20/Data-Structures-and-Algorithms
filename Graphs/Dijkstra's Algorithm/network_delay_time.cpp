//leetcode.com/problems/network-delay-time/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void createAdjacencyList(vector<vector<int>>& times, vector<vector<pair<int, int>>>& adjacencyList) {
        for (auto time: times) {
            adjacencyList[time[0]].push_back({time[1], time[2]});
        }
    }
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adjacencyList(n + 1); 
        createAdjacencyList(times, adjacencyList);
        
        vector<int> shortestTime(n + 1, 10001);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        
        shortestTime[k] = 0;
        minHeap.push({0, k});
        while (!minHeap.empty()) {
            int currentTime = minHeap.top().first;
            int currentNode = minHeap.top().second;
            minHeap.pop();
            
            for (auto neighbours: adjacencyList[currentNode]) {
                int edgeWeight = neighbours.second;
                int adjacentNode = neighbours.first;
                if (edgeWeight + currentTime < shortestTime[adjacentNode]) {
                    shortestTime[adjacentNode] = edgeWeight + currentTime;
                    minHeap.push({shortestTime[adjacentNode], adjacentNode});
                }
            } 
        }
        
        for (int i = 1; i <= n; ++i)
            if (shortestTime[i] == 10001)
                return -1;
        
        return *max_element(shortestTime.begin() + 1, shortestTime.end());
    }
};