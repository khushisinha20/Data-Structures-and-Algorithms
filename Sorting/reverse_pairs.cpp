//leetcode.com/problems/reverse-pairs/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int merge(vector<int>& nums, int low, int mid, int high) {
        vector<int> buffer;
        int reversePairs = 0;
        int left = low;
        int right = mid + 1;
        int j = mid + 1;
        
        for (int i = low; i <= mid; ++i) {
            while (j <= high && nums[i] > 2LL * nums[j])
                ++j;
            reversePairs += (j - (mid + 1));
        }
        
        while (left <= mid && right <= high) {
            if (nums[left] <= nums[right])
                buffer.push_back(nums[left++]);
            else
                buffer.push_back(nums[right++]);
        }
        
        while (left <= mid)
            buffer.push_back(nums[left++]);
        
        while (right <= high)
            buffer.push_back(nums[right++]);
        
        for (int i = low; i <= high; ++i)
            nums[i] = buffer[i - low];
        
        return reversePairs;
    }

    int mergeSort(vector<int>& nums, int low, int high) {
        int reversePairs = 0;
        if (low < high) {
            int mid = low + (high - low) / 2;
            reversePairs += mergeSort(nums, low, mid);
            reversePairs += mergeSort(nums, mid + 1, high);
            reversePairs += merge(nums, low, mid, high);
        }
        return reversePairs;
    }
    
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};