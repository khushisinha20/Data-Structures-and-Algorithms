//leetcode.com/problems/jump-game/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_reach = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] + i > max_reach)
                max_reach = nums[i] + i;
            if (max_reach == i) // stuck at a position, cannot move further
                break;
        }
        return max_reach >= nums.size() - 1;
    }
};