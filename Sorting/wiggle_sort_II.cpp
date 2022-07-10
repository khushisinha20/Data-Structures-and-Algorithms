//leetcode.com/problems/wiggle-sort-ii/

#include <bits/stdc++.h>
using namespace std;

//Average Time Complexity: O(n)

//Auxiliary Space: O(n)

class Solution {
public:
    void threeWayPartition(vector<int>& nums, int median) {
        int start = 0;
        int mid = 0;
        int end = nums.size() - 1;
        while (mid <= end) {
            if (nums[mid] < median) {
                swap(nums[start], nums[mid]);
                ++start;
                ++mid;
            } else if (nums[mid] == median) {
                ++mid;
            } else {
                swap(nums[mid], nums[end]);
                --end;
            }
        }
    }
    
    int getMedian(vector<int>& nums) {
        int mid = nums.size() / 2;
        nth_element(nums.begin(), nums.begin() + mid, nums.end());
        return nums[mid];
    }
    
    void wiggleSort(vector<int>& nums) {
        int median = getMedian(nums);
        threeWayPartition(nums, median);
        int mid = nums.size() / 2;
        int small_numbers_position = mid;
        if (nums.size() % 2 == 0)
            small_numbers_position = mid - 1;
        int large_numbers_position = nums.size() - 1;
        vector<int> res(nums.size());
        for (int i = 0; i < nums.size(); i += 2)
            res[i] = nums[small_numbers_position--];
        for (int i = 1; i < nums.size(); i += 2)
            res[i] = nums[large_numbers_position--];
        nums = res;
    }
};