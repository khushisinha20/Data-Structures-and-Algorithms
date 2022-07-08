//leetcode.com/problems/kth-largest-element-in-an-array/

//O(n) in average case

//O(n ^ 2) in worst case

//Quick Select Algorithm

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int partition(vector<int>& a, int low, int high) {
        int pivot = a[high];
        int i = low - 1;
        for (int j = low; j < high; ++j) {
            if (a[j] < pivot) {
                ++i;
                swap(a[j], a[i]);
            }
        }
        swap(a[i + 1], a[high]);
        return i + 1;
    }
    
    int kthLargest(vector<int>& nums, int k, int low, int high) {
        int index = 0;
        while (low <= high) {
            index = partition(nums, low, high);
            if (index == k)
              return nums[index];
            else if (index > k)
                high = index - 1;
            else
                low = index + 1;
        }
        return -1;
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        k = nums.size() - k;
        int low = 0;
        int high = nums.size() - 1;
        return kthLargest(nums, k, low, high);
    }
};