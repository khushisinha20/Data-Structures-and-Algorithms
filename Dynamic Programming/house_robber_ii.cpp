//leetcode.com/problems/house-robber-ii/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int helper(vector<int>& nums) {
        int previous = nums[0];
        int previousOfPrevious = 0;
        
        for (int i = 1; i < nums.size(); ++i) {
            int take = nums[i];
            if (i > 1)
                take += previousOfPrevious;
            int notTake = previous;
            int current = max(take, notTake);
            previousOfPrevious = previous;
            previous = current;
        }
        return previous;
    }
    
    int rob(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];
        vector<int> excludeLast(nums.begin(), nums.end() - 1);
        vector<int> excludeFirst(nums.begin() + 1, nums.end());
        return max(helper(excludeFirst), helper(excludeLast));
    }
};