//leetcode.com/problems/time-taken-to-mark-all-nodes/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void calculateMaxDepth(int node, int parent, vector<vector<int>>& adjList, vector<vector<int>>& maxDepth) {
        for (int neighbor: adjList[node]) {
            if (neighbor != parent) {
                calculateMaxDepth(neighbor, node, adjList, maxDepth);
                int propagationTime = maxDepth[neighbor][0] + (neighbor % 2 == 1 ? 1 : 2);

                if (propagationTime > maxDepth[node][0]) {
                    maxDepth[node][1] = maxDepth[node][0];
                    maxDepth[node][0] = propagationTime;
                } else if (propagationTime > maxDepth[node][1]) {
                    maxDepth[node][1] = propagationTime;
                }
            }
        }
    }

    void computeFinalTimes(int node, int parent, int inheritedTime, vector<int>& result, vector<vector<int>>& adjList, vector<vector<int>>& maxDepth) {
        result[node] = max(maxDepth[node][0], inheritedTime);
        int propagationTimeFromParent = node % 2 == 0 ? 2 : 1;

        for (int neighbor: adjList[node]) {
            if (neighbor != parent) {
                int propagationTime = maxDepth[neighbor][0] + (neighbor % 2 == 1 ? 1 : 2);
                int alternateDepth = (propagationTime == maxDepth[node][0]) ? maxDepth[node][1] : maxDepth[node][0];
                computeFinalTimes(neighbor, node, max(propagationTimeFromParent + inheritedTime, propagationTimeFromParent + alternateDepth), result, adjList, maxDepth);
            }
        }
    }

    vector<int> timeTaken(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<int> result(n);
        vector<vector<int>> maxDepth(n, vector<int> (2, 0));
        vector<vector<int>> adjList(n);

        for (auto& edge: edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        calculateMaxDepth(0, -1, adjList, maxDepth);
        computeFinalTimes(0, -1, 0, result, adjList, maxDepth);

        return result;
    }
};
