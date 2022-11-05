//leetcode.com/problems/maximum-total-importance-of-roads/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<long long> outdegree(n, 0);
        for (int i = 0; i < roads.size(); ++i) {
            ++outdegree[roads[i][1]];
            ++outdegree[roads[i][0]];
        }
        sort(outdegree.begin(), outdegree.end());
        signed long long maxImportance = 0;
        while (n--) {
            maxImportance += outdegree[n] * (n + 1);
        }
        return maxImportance;
    }
};