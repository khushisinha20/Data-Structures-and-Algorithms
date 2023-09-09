//leetcode.com/problems/rearrange-array-to-maximize-prefix-score/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int positiveSumCount = 0;
        long long currentSum = 0;
        
        for (int i = nums.size() - 1; i >= 0; --i) {
            currentSum += nums[i];
            if (currentSum > 0)
                ++positiveSumCount;
        }
        
        return positiveSumCount;
    }
};