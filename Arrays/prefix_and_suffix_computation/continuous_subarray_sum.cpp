//leetcode.com/problems/continuous-subarray-sum/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> remainders;
        int prefixSum = nums[0];
        remainders[prefixSum % k] = 0;
        remainders[0] = -1;
        for (int i = 1; i < nums.size(); ++i) {
            prefixSum += nums[i];
            if (remainders.find(prefixSum % k) != remainders.end()) {
                if (remainders[prefixSum % k] != i - 1)
                    return true;
            } else
                remainders[prefixSum % k] = i;
        }
        return false;
    }
};