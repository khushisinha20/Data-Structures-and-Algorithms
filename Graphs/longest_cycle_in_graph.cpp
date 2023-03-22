//leetcode.com/problems/longest-cycle-in-a-graph/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestCycle(vector<int>& edges) {
        vector<pair<int, int>> cycleTracker(edges.size(), {-1, -1});
        int answer = INT_MIN;
        
        for (int node = 0; node < edges.size(); ++node) {
            int source = node;
            int currentNode = node;
            int distanceFromSource = 0;
            while (currentNode != -1) {
                if (cycleTracker[currentNode] == make_pair(-1, -1)) {
                    cycleTracker[currentNode] = {source, distanceFromSource++};
                } else {
                    if (cycleTracker[currentNode].first == source)
                        answer = max(answer, distanceFromSource - cycleTracker[currentNode].second);
                    break;
                }
                currentNode = edges[currentNode];
            }
        }
        return answer == INT_MIN ? -1 : answer;
    }
};