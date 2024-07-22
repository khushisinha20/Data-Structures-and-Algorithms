//leetcode.com/problems/maximum-number-of-non-overlapping-subarrays-with-sum-equals-target/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        unordered_set<int> prefixSums;
        prefixSums.insert(0);
        int ans = 0;

        int prefixSum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            prefixSum += nums[i];
            if (prefixSums.find(prefixSum - target) != prefixSums.end()) {
                ++ans;
                prefixSums = {0};
                prefixSum = 0;
            }
            prefixSums.insert(prefixSum);
        }

        return ans;
    }
};
