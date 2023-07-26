//leetcode.com/problems/kth-largest-element-in-an-array/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int partition(vector<int>& nums, int low, int high) {
        int pivot = nums[low];
        int i = low;
        int j = high;
        
        while (i < j) {
            while (i <= high - 1 and nums[i] <= pivot)
                ++i;
            
            while (j >= low + 1 and nums[j] > pivot)
                --j;
            
            if (i < j)
                swap(nums[i], nums[j]);
        }
        swap(nums[low], nums[j]);
        
        return j;
    }
    
    int quickSelect(vector<int>& nums, int low, int high, int& k) {
        while (low <= high) {
            int partitionIndex = partition(nums, low, high);
            if (partitionIndex == k)
                return nums[partitionIndex];
            else if (partitionIndex > k)
                high = partitionIndex - 1;
            else
                low = partitionIndex + 1;
        }
        return -1;
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        k = nums.size() - k;
        return quickSelect(nums, 0, nums.size() - 1, k);
    }
};