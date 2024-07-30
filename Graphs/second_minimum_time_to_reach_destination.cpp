#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> getGraph(vector<vector<int>>& edges, int& n) {
        vector<vector<int>> graph(n);
        for (auto& edge: edges) {
            graph[edge[0] - 1].push_back(edge[1] - 1);
            graph[edge[1] - 1].push_back(edge[0] - 1);
        }
        return graph;
    }

    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> graph = getGraph(edges, n);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        vector<pair<int, int>> times(n, {INT_MAX, INT_MAX});
        minHeap.push({0, 0});

        while (!minHeap.empty()) {
            auto [timeElapsed, currentNode] = minHeap.top();
            minHeap.pop();

            if (timeElapsed > times[currentNode].second)
                continue;

            int factor = timeElapsed / change;
            int newTime = timeElapsed + time;
            if (factor % 2 == 1)
                newTime = (factor + 1) * change + time;

            for (auto& neighbor: graph[currentNode]) {
                if (times[neighbor].first > newTime) {
                    times[neighbor].second = times[neighbor].first;
                    times[neighbor].first = newTime;
                    minHeap.push({newTime, neighbor});
                } else if (times[neighbor].second > newTime && newTime > times[neighbor].first) {
                    times[neighbor].second = newTime;
                    minHeap.push({newTime, neighbor});
                }
            }
        }

        return times[n - 1].second;
    }
};
