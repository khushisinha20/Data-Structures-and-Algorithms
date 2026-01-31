//leetcode.com/problems/count-visited-nodes-in-a-directed-graph/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countVisitedNodes(vector<int>& edges) {
        int n = edges.size();
        vector<int> result(n, 0);
        vector<int> inDegree(n, 0);

        for (int node: edges)
            ++inDegree[node];

        queue<int> nodesQueue;
        for (int node = 0; node < n; ++node)
            if (inDegree[node] == 0)
                nodesQueue.push(node);

        vector<int> tails;
        while (!nodesQueue.empty()) {
            int currNode = nodesQueue.front();
            nodesQueue.pop();

            tails.push_back(currNode);
            int next = edges[currNode];
            if (--inDegree[next] == 0)
                nodesQueue.push(next);
        }

        for (int i = 0; i < n; ++i) {
            if (inDegree[i] > 0 and result[i] == 0) {
                vector<int> cycle;
                int curr = i;
                while (result[curr] == 0) {
                    result[curr] = -1;
                    cycle.push_back(curr);
                    curr = edges[curr];
                }

                int cycleLen = cycle.size();
                for (int node: cycle)
                    result[node] = cycleLen;
            }
        }

        for (int i = tails.size() - 1; i >= 0; --i) {
            int curr = tails[i];
            result[curr] = result[edges[curr]] + 1;
        }

        return result;
    }
};
