//leetcode.com/problems/find-k-th-smallest-pair-distance/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPossible(vector<int>& nums, int targetDistance, int k) {
        int n = nums.size();
        int j = 1;
        int totalPairs = 0;
        
        for (int i = 0; i < n; ++i) {
            while (j < n and nums[j] - nums[i] <= targetDistance)
                ++j;
            --j;
            totalPairs += (j - i);
        }
        
        return totalPairs >= k;
    }
    
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(),  nums.end());
        int maxDistance = nums.back() - nums.front();
        
        int left = 0;
        int right = maxDistance;
        int ans = -1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (isPossible(nums, mid, k)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        return ans;
    }
};