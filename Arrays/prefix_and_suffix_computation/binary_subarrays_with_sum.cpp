//leetcode.com/problems/binary-subarrays-with-sum/

#include <bits/stdc++.h>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> mp;
        mp.insert({0, 1});
        int sum = 0;
        int subarray_with_given_sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if (mp.find(sum - goal) != mp.end())
                subarray_with_given_sum += mp[sum - goal];
            ++mp[sum];
        }
        return subarray_with_given_sum;
    }
};