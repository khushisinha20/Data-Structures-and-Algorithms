//leetcode.com/problems/maximum-number-of-events-that-can-be-attended-ii/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    static bool comparator(const vector<int>& a, const vector<int>& b) {
        if (a[0] == b[0])
            return a[1] < b[1];
        return a[0] < b[0];
    }
public: 
    vector<vector<int>> dp;
    
    int helper(vector<vector<int>>& events, int k, int index, int previous) {
        if (index == events.size() or k == 0)
            return 0;
        
        if (dp[previous + 1][k] != -1)
            return dp[previous + 1][k];
        
        int take = 0;
        int notTake = 0;
        
        if (previous == -1 or events[previous][1] < events[index][0])
            take = events[index][2] + helper(events, k - 1, index + 1, index);
        notTake = helper(events, k, index + 1, previous);
        return dp[previous + 1][k] = max(take, notTake);
    }
    
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end(), comparator);
        int n = events.size();
        
        dp.resize(n + 1, vector<int> (k + 1, -1));
        return helper(events, k, 0, -1);
    }
};