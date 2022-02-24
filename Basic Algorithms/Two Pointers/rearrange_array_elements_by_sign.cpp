//leetcode.com/problems/rearrange-array-elements-by-sign

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int positive = 0;
        int negative = 1;
        vector<int> res(nums.size(), 0);
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] >= 0) {
                res[positive] = nums[i];
                positive += 2;
            } else {
                res[negative] = nums[i];
                negative += 2;
            }
        }
        return res;
    }
};