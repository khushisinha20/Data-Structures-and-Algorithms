//leetcode.com/problems/subarray-sums-divisible-by-k/submissions/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int curr_sum = 0;
        int required_subarrays = 0;
        int remainder = 0;
        unordered_map<int, int> mp;
        mp.insert(make_pair(0, 1));
        for (int i = 0; i < nums.size(); ++i) {
            curr_sum += nums[i];
            remainder = curr_sum % k;
            if (remainder < 0) {
                remainder += k;
            }
            if (mp.find(remainder) != mp.end()) {
                required_subarrays += mp[remainder];
            }
            mp[remainder] += 1;
        }
        return required_subarrays;
    }
};