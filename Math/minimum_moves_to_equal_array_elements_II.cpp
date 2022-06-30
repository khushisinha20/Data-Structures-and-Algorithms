//leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int mid = nums.size() / 2;
        int min_moves = 0;
        for (int i = 0; i < nums.size(); ++i) {
            min_moves += abs(nums[mid] - nums[i]);
        }
        return min_moves;
    }
};