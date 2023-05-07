//leetcode.com/problems/count-subarrays-with-fixed-bounds/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long minKPosition = -1;
        long long maxKPosition = -1; 
        long long culpritPosition = -1;
        
        long long result = 0;
        
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > maxK or nums[i] < minK)
                culpritPosition = i;
            
            if (nums[i] == minK)
                minKPosition = i;
            
            if (nums[i] == maxK)
                maxKPosition = i;
            
            long long subarrayCount = min(minKPosition, maxKPosition) - culpritPosition;
            result += (subarrayCount <= 0) ? 0 : subarrayCount;
        }
        
        return result;
    }
};