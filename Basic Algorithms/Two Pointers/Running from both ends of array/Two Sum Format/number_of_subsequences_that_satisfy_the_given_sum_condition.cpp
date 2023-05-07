//leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int MOD = 1000000007;
    
    void fillPowers(vector<int>& powers) {
        for (int i = 1; i < powers.size(); ++i) {
            powers[i] = (powers[i - 1] * 2) % MOD;
        }
    }
    
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int start = 0;
        int end = nums.size() - 1;
        int result = 0;
        vector<int> powers(nums.size(), 1);
        fillPowers(powers);
        
        while (start <= end) {
            if (nums[start] + nums[end] > target)
                --end;
            else {
                result = (result + powers[end - start]) % MOD;
                ++start;
            }
        }
        
        return result;
    }
};