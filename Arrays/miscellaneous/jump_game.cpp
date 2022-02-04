//leetcode.com/problems/jump-game/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i = 0;
        for (int jump = 0; i <= jump && i < nums.size(); ++i) {
            jump = max(jump, i + nums[i]);
        }
        return i == nums.size();
    }
};