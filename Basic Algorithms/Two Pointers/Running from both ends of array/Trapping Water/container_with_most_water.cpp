//leetcode.com/problems/container-with-most-water/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        //Moving towards the greater height
        int left = 0;
        int right = height.size() - 1;
        int max_water = 0;
        while (left < right) {
            max_water = max(max_water, ((right - left) * min(height[left], height[right])));
            if (height[left] > height[right])
                --right;
            else
                ++left;
        }
        return max_water;
    }
};