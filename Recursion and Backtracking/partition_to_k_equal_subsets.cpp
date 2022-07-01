//leetcode.com/problems/partition-to-k-equal-sum-subsets/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPossibleToPartition(vector<int>& nums, int sum, int idx, vector<int>& bucket) {
        if (idx >= nums.size())
            return true;
        
        for (int i = 0; i < bucket.size(); ++i) {
            if (bucket[i] + nums[idx] <= sum) {
                bucket[i] += nums[idx];
                if (isPossibleToPartition(nums, sum, idx + 1, bucket))
                    return true;
                bucket[i] -= nums[idx];
            }
            if (bucket[i] == 0)
                break;
        }
        return false;
    }
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        if (k == 1)
            return true;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (nums.size() < k || sum % k != 0)
            return false;
        
        vector<int> bucket(k, 0);
        
        return isPossibleToPartition(nums, sum / k, 0, bucket);
    }
};