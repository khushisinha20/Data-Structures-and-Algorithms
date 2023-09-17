//leetcode.com/problems/removing-minimum-and-maximum-from-array/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMinElementIndex(vector<int>& nums) {
        int minElement = nums[0];
        int minIndex = 0;

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] < minElement) {
                minElement = nums[i];
                minIndex = i;
            }
        }

        return minIndex;
    }
    
    int findMaxElementIndex(vector<int>& nums) {
        int maxElement = nums[0];
        int maxIndex = 0;

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > maxElement) {
                maxElement = nums[i];
                maxIndex = i;
            }
        }

        return maxIndex;
    }
    
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int minElementIndex = findMinElementIndex(nums);
        int maxElementIndex = findMaxElementIndex(nums);
        
        int first = min(minElementIndex, maxElementIndex);
        int second = max(minElementIndex, maxElementIndex);
        
        int deleteFromLeft = second + 1;
        int deleteFromRight = n - first;
        int deleteFromBoth = first + 1 + n - second;
        
        return min(deleteFromLeft, min(deleteFromRight, deleteFromBoth));
    }
};