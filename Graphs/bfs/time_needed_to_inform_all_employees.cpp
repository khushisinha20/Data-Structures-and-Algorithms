//leetcode.com/problems/time-needed-to-inform-all-employees/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> adjacencyList[100001];
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        queue<pair<int, int>> nodes;
        vector<bool> visited(n, false);
        
        for (int i = 0; i < n; ++i) {
            if (manager[i] != -1)
                adjacencyList[manager[i]].push_back(i); 
            else {
                 nodes.push({0, i});
                 visited[i] = true;
            }
        }
        
        int maxTime = INT_MIN;
        
        while (!nodes.empty()) {
            int time = nodes.front().first;
            int node = nodes.front().second;
            
            maxTime = max(maxTime, time);
            nodes.pop();
            
            for (auto& adjacentNode: adjacencyList[node]) {
                if (!visited[adjacentNode]) {
                    visited[adjacentNode];
                    nodes.push({time + informTime[node], adjacentNode});
                }
            }
        }
        
        return maxTime;
    }
};