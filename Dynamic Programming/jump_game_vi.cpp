#include <bits/stdc++.h>
using namespace std;

//leetcode.com/problems/jump-game-vi/

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n);
        dp[0] = nums[0];

        priority_queue<pair<int, int>> maxHeap;
        maxHeap.push({dp[0], 0});

        for (int i = 1; i < n; ++i) {
            while (!maxHeap.empty() and maxHeap.top().second < i - k)
                maxHeap.pop();

            dp[i] = nums[i] + maxHeap.top().first;
            maxHeap.push({dp[i], i});
        }

        return dp[n - 1];
    }
};
