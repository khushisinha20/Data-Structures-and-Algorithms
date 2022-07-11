//leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array///leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstPosition(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        int res = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                res = mid;
                high = mid - 1;
            } else if (nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return res;
    } 
    
    int lastPosition(vector<int>& nums, int target) {
        if (firstPosition(nums, target) == -1)
            return -1;
        int low = firstPosition(nums, target);
        int high = nums.size() - 1;
        int res = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                res = mid;
                low = mid + 1;
            } else if (nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return res;
    } 
    
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0)
            return {-1, -1};
        int first = firstPosition(nums, target);
        int last = lastPosition(nums, target);
        return {first, last};
    }
};