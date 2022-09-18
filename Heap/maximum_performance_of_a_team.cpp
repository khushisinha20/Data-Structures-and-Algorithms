//leetcode.com/problems/maximum-performance-of-a-team/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void combineEfficiencyAndSpeed(vector<pair<long long, long long>>& engineers, vector<int>& efficiency, vector<int>& speed) {
        for (int i = 0; i < engineers.size(); ++i)
            engineers[i] = {efficiency[i], speed[i]};
    }
    
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<long long, long long>> engineers(n);
        combineEfficiencyAndSpeed(engineers, efficiency, speed);
        sort(engineers.rbegin(), engineers.rend());
        long long teamSpeed = 0;
        long long maxTeamPerformance = 0;
        long long currentTeamPerformance = 0;
        priority_queue<long long, vector<long long>, greater<long long>> min_heap;
        for (int i = 0; i < engineers.size(); ++i) {
            min_heap.push(engineers[i].second);
            teamSpeed += engineers[i].second;
            if (min_heap.size() > k) {
                teamSpeed -= min_heap.top();
                min_heap.pop();
            }
            currentTeamPerformance = teamSpeed * engineers[i].first;
            maxTeamPerformance = max(maxTeamPerformance, currentTeamPerformance);
        }
        return maxTeamPerformance % 1000000007;
    }
};