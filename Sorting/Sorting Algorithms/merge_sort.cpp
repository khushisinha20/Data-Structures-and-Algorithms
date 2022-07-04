//leetcode.com/problems/sort-an-array/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void outPlaceMerge(vector<int> &nums, int low, int mid, int high) {
        if (low >= high)
            return;
        
        int l = low;
        int r = mid + 1;
        int size = high - low + 1;
        int current_index = 0;
        vector<int> buffer(size, 0);
        while (l <= mid && r <= high) {
            if (nums[l] < nums[r])
                buffer[current_index++] = nums[l++];
            else
                buffer[current_index++] = nums[r++];
        } 
        while (l <= mid)
            buffer[current_index++] = nums[l++];
        while (r <= high)
            buffer[current_index++] = nums[r++];
        for (int i = 0; i < buffer.size(); ++i)
            nums[i + low] = buffer[i];
    }

    void mergeSort(vector<int> &nums, int low, int high) {
        if (low >= high)
            return;
        int mid =  low + (high - low) / 2;
        mergeSort(nums, low, mid);
        mergeSort(nums, mid + 1, high);
        outPlaceMerge(nums, low, mid, high);
    }
    
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};