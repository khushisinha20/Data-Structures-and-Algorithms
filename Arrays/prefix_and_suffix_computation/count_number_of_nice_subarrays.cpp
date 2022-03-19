//leetcode.com/problems/count-number-of-nice-subarrays

#include <bits/stdc++.h>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] & 1)
                nums[i] = 1;
            else
                nums[i] = 0;
        }
        unordered_map<int, int> mp;
        mp.insert({0, 1});
        int sum = 0;
        int nice_subarrays = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if (mp.find(sum - k) != mp.end()) {
                nice_subarrays += mp[sum - k];
            }
            ++mp[sum];
        }
        return nice_subarrays;
    }
};