//leetcode.com/problems/house-robber/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
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
};