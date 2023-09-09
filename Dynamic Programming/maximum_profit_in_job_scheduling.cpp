//leetcode.com/problems/maximum-profit-in-job-scheduling/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> getJobs(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> jobs;
        int n = endTime.size();
        
        for (int i = 0; i < n; ++i)
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        
        return jobs;
    }
    
    int nextJobIndex(vector<vector<int>>& jobs, int currentJobEndTime) {
        int low = 0;
        int high = jobs.size() - 1;
        int ans = -1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (jobs[mid][0] >= currentJobEndTime) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return ans;
    }
    
    int helper(vector<vector<int>>& jobs, int index, vector<int>& dp) {
        if (index >= jobs.size())
            return 0;
        
        if (dp[index] != -1)
            return dp[index];
        
        int take = jobs[index][2] + helper(jobs, nextJobIndex(jobs, jobs[index][1]), dp);
        int notTake = helper(jobs, index + 1, dp);
        
        return dp[index] = max(take, notTake);
    }
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> jobs = getJobs(startTime, endTime, profit);
        
        auto comparator = [&] (const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        };
        
        sort(jobs.begin(), jobs.end(), comparator);
        vector<int> dp(jobs.size(), -1);
        
        return helper(jobs, 0, dp);
    }
};