#include <bits/stdc++.h>
using namespace std;

//leetcode.com/problems/next-permutation/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int less_than_next = -1;
        for (int i = nums.size() - 2; i >= 0; --i) {
            if (nums[i] < nums[i + 1]) {
                less_than_next = i;
                break;
            }
        }
        if (less_than_next == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        int idx = -1;
        for (int i = nums.size() - 1; i >= 0; --i) {
            if (nums[less_than_next] < nums[i]) {
                idx = i;
                break;
            }
        }
        swap(nums[idx], nums[less_than_next]);
        reverse(nums.begin() + less_than_next + 1, nums.end());
    }
};