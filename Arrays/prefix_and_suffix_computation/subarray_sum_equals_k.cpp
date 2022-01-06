//leetcode.com/problems/subarray-sum-equals-k/submissions/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp.insert({0, 1});
        int sum = 0;
        int required_subarrays = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if (mp.find(sum - k) != mp.end()) {
                required_subarrays += mp[sum - k];
            }
            mp[sum] += 1;
        }
        return required_subarrays;
    }
};