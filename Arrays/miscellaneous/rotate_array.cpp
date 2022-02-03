//leetcode.com/problems/rotate-array/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void reverseArray(vector<int>& nums, int start, int end) {
        while (start <= end) {
            swap(nums[start], nums[end]);
            ++start;
            --end;
        }
    }
    
    void rotate(vector<int>& nums, int k) {
        if (nums.size() == 1) {
            return;
        }
        if (nums.size() <= k) {
            k = (k % nums.size());  
        }
        reverseArray(nums, 0, nums.size() - k - 1);
        reverseArray(nums, nums.size() - k, nums.size() - 1);
        reverseArray(nums, 0, nums.size() - 1);
    }
};