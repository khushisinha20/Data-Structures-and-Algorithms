//leetcode.com/problems/the-time-when-the-network-becomes-idle/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> getGraph(vector<vector<int>>& edges, vector<int>& patience) {
        int n = patience.size();
        vector<vector<int>> graph(n);
        
        for (auto& edge: edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        return graph;
    }
    
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        vector<vector<int>> graph = getGraph(edges, patience);
        queue<int> nodes;
        int n = patience.size();
        vector<int> time(n, 0);
        vector<bool> visited(n, false);
        nodes.push(0);
        visited[0] = true;
        int arrivalTime = 0;
        
        while (!nodes.empty()) {
            int size = nodes.size();
            while (size--) {
                int currentNode = nodes.front();
                nodes.pop();
                
                time[currentNode] = arrivalTime;
                
                for (auto& neighbour: graph[currentNode]) {
                    if (!visited[neighbour]) {
                        nodes.push(neighbour);
                        visited[neighbour] = true;
                    }
                }
            }
            ++arrivalTime;
        }
        
        int slowest = 0;
        
        for (int node = 1; node < n; ++node) {
            int firstReplyReceiptTime = 2 * time[node];
            int waitingTime = firstReplyReceiptTime - 1;
            int messagesResent = waitingTime / patience[node];
            int totalTime = firstReplyReceiptTime + messagesResent * patience[node];
            slowest = max(totalTime, slowest);
        }
        
        return slowest + 1;
    }
};