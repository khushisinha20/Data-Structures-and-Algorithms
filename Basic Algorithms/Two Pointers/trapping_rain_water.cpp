//leetcode.com/problems/trapping-rain-water/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() < 3)
            return 0;
        int maxLeft = height[0];
        int maxRight = height[height.size() - 1];
        int trappedWater = 0;
        int left = 1;
        int right = height.size() - 2;
        while (left <= right) {
            if (maxLeft < maxRight) {
                if (height[left] >= maxLeft) {
                    maxLeft = height[left];
                } else {
                    trappedWater += (maxLeft - height[left]);
                }
                ++left;
            } else {
                if (height[right] > maxRight) {
                    maxRight = height[right];
                } else {
                    trappedWater += (maxRight - height[right]);
                }
                --right;
            }
        }
        return trappedWater;
    }
};