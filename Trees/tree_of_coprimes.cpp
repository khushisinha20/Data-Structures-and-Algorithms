//leetcode.com/problems/tree-of-coprimes/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> createGraph(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        return graph;
    }

    bool isCoprime(int a, int b) {
        return gcd(a, b) == 1;
    }

    void dfs(vector<int>& nums, vector<int>& result, vector<vector<int>>& graph, vector<vector<int>>& mostRecent, vector<int>& depth, int node, int parent, int currentDepth) {
        int currentValue = nums[node];
        result[node] = -1;
        int closestDepth = -1;

        for (int value = 1; value <= 50; ++value) {
            if (isCoprime(currentValue, value)) {
                if (!mostRecent[value].empty()) {
                    int recentNode = mostRecent[value].back();
                    if (depth[recentNode] > closestDepth) {
                        closestDepth = depth[recentNode];
                        result[node] = recentNode;
                    }
                }
            }
        }

        mostRecent[currentValue].push_back(node);
        depth[node] = currentDepth;

        for (auto& neighbor : graph[node]) {
            if (neighbor != parent) {
                dfs(nums, result, graph, mostRecent, depth, neighbor, node, currentDepth + 1);
            }
        }

        mostRecent[currentValue].pop_back();
    }

    vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<vector<int>> graph = createGraph(n, edges);
        vector<int> result(n, -1);
        vector<vector<int>> mostRecent(51);
        vector<int> depth(n);

        dfs(nums, result, graph, mostRecent, depth, 0, -1, 0);

        return result;
    }
};
