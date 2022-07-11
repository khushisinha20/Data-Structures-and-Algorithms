//leetcode.com/problems/search-in-rotated-sorted-array/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int isMinimum(vector<int>& nums, int mid) {
        int n = nums.size();
        int previous = (mid - 1 + n) % n;
        int next = (mid + 1) % n;
        return nums[previous] >= nums[mid] && nums[next] >= nums[mid];
    }
    
    int indexOfMinimum(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        while (low <= high) {
            if (nums[low] <= nums[high])
                return low;
            int mid = low + (high - low) / 2;
            if (isMinimum(nums, mid))
                return mid;
            else if (nums[low] <= nums[mid])
                low = mid + 1;
            else if (nums[mid] <= nums[high])
                high = mid - 1;
        }
        return -1;
    }
    
    int binarySearch(vector<int>& nums, int target, int low, int high) {
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return -1;
    }
    
    int searchInFirstSegment(vector<int>& nums, int target) {
        int mid = indexOfMinimum(nums, target);
        if (nums[mid] == target)
            return mid;
        if (mid == 0)
            return binarySearch(nums, target, 0, nums.size() - 1);
        return binarySearch(nums, target, 0, mid - 1);
    }
    
    int searchInSecondSegment(vector<int>& nums, int target) {
        int mid = indexOfMinimum(nums, target);
        if (nums[mid] == target)
            return mid;
        if (mid == 0)
            return binarySearch(nums, target, 0, nums.size() - 1);
        return binarySearch(nums, target, mid + 1, nums.size() - 1);
    }
    
    int search(vector<int>& nums, int target) {
        return max(searchInFirstSegment(nums, target), searchInSecondSegment(nums, target));
    }
};