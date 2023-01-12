//leetcode.com/problems/shortest-subarray-with-sum-at-least-k/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        deque<pair<long long, int>> prefixSum;
        long long currentSum = 0;
        int minLength = INT_MAX;
        
        for (int i = 0; i < nums.size(); ++i) {
            currentSum += nums[i];
            if (currentSum >= k)
                minLength = min(minLength, i + 1);
            
            while (!prefixSum.empty() && currentSum - prefixSum.front().first >= k) {
                minLength = min(minLength, i - prefixSum.front().second);
                prefixSum.pop_front();
            }
            
            if (prefixSum.empty() || currentSum > prefixSum.back().first)
                prefixSum.push_back({currentSum, i});
            else {
                while (!prefixSum.empty() && currentSum <= prefixSum.back().first) 
                    prefixSum.pop_back();
                prefixSum.push_back({currentSum, i});
            }
        }
        return minLength == INT_MAX ? -1 : minLength;
    }
};