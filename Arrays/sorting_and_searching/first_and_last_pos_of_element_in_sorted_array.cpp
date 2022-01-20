//leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array

#include <bits/stdc++.h>>
using namespace std;

class Solution {
public:
    int firstOccurence(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] > target) {
                high = mid - 1;
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                if (mid == 0 || nums[mid - 1] != nums[mid])
                    return mid;
                else
                    high = mid - 1;
            }
        }
        return -1;
    }
    
    int lastOccurence(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] > target) {
                high = mid - 1;
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                if (mid == nums.size() - 1 || nums[mid + 1] != nums[mid])
                    return mid;
                else
                    low = mid + 1;
            }
        }
        return -1;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> position;
        position.push_back(firstOccurence(nums, target));
        position.push_back(lastOccurence(nums, target));
        return position;
    }
};