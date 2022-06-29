//leetcode.com/problems/trapping-rain-water/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() < 3)
            return 0;
        int left = 0;
        int right = height.size() - 1;
        int maxLeft = 0;
        int maxRight = 0;
        int water = 0;
        while (left < right) {
            if (height[left] <= height[right]) {
                maxLeft = max(maxLeft, height[left]);
                water += maxLeft - height[left];
                ++left;
            } else {
                maxRight = max(maxRight, height[right]);
                water += maxRight - height[right];
                --right;
            }
        }
        return water;
    }
};