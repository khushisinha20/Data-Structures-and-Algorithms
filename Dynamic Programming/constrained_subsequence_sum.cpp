//leetcode.com/problems/constrained-subsequence-sum/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> maxHeap;
        maxHeap.push({nums[0], 0});
        int n = nums.size();
        
        vector<int> dp = nums;
        int maxSum = dp[0];
        
        for (int i = 1; i < n; ++i) {
            while (!maxHeap.empty() and i - maxHeap.top().second > k)
                maxHeap.pop();
            dp[i] = max(dp[i], nums[i] + maxHeap.top().first);
            maxHeap.push({dp[i], i});
            maxSum = max(maxSum, dp[i]);
        }
        
        return maxSum;
    }
};