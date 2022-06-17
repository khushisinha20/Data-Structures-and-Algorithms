//leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> lookup;
    const int MOD = 1000000007;
    
    int calculateResult(int order) {
        if (order < lookup.size())
            return lookup[order];
        
        while (lookup.size() <= order) {
            lookup.push_back((lookup.back() << 1 ) % MOD);
        }
        
        return lookup.back();
    }
    
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int start = 0;
        int end = nums.size() - 1;
        int res = 0;
        
        lookup.push_back(1);
        
        while (start <= end) {
            if (nums[start] + nums[end] > target)
                --end;
            else {
                res = (res + calculateResult(end - start)) % MOD;
                ++start;
            }
        }
        return res;
    }
};