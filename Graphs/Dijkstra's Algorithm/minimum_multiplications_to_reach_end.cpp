//bit.ly/3AugzNb

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        queue<pair<int, int>> nodes;
        nodes.push({start, 0});
        vector<int> minSteps(100000, INT_MAX);
        
        int MOD = 100000;
        minSteps[start] = 0;
        
        while (!nodes.empty()) {
            int currentNode = nodes.front().first;
            int steps = nodes.front().second;
            nodes.pop();
            
            for (auto num: arr) {
                int nextNum = (num * currentNode) % MOD;
                if (steps + 1 < minSteps[nextNum]) {
                    minSteps[nextNum] = steps + 1;
                    if (nextNum == end)
                        return steps + 1;
                    nodes.push({nextNum, steps + 1});
                }
            }
        }
        return -1;
    }
};