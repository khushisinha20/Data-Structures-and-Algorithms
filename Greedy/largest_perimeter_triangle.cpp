//leetcode.com/problems/largest-perimeter-triangle/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());
        int res = 0;
        for (int i = 0; i < nums.size() - 2; ++i) {
            if (nums[i] < nums[i + 1] + nums[i + 2]) {
                res = nums[i] + nums[i + 1] + nums[i + 2];
                 break;
            }
        }
        return res;
    }
};