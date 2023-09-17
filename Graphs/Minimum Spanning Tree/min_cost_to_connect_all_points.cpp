//leetcode.com/problems/min-cost-to-connect-all-points/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<bool> inMST(n, false);
        vector<int> minDist(n, INT_MAX);
        
        minDist[0] = false;
        int minCost = 0;
        
        priority_queue<pair<int, int>> minHeap;
        minHeap.push({0, 0});
        
        while (!minHeap.empty()) {
            int u = minHeap.top().second;
            minHeap.pop();
            
            if (inMST[u])
                continue;
            
            inMST[u] = true;
            minCost += minDist[u];
            
            for (int v = 0; v < n; ++v) {
                if (!inMST[v]) {
                    int dist = abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1]);
                    if (dist < minDist[v]) {
                        minDist[v] = dist;
                        minHeap.push({-dist, v});
                    }
                }
            }
        }
        
        return minCost;
    }
};