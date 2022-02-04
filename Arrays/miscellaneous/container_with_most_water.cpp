//leetcode.com/problems/container-with-most-water

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;
        int max_height = (j - i) * min(height[i], height[j]);
        while (i < j) {
            while (height[i] <= min(height[i], height[j]) && i < j) {
                ++i;
                max_height = max(max_height, (j - i) * min(height[i], height[j]));
            }
            while (height[j] <= min(height[i], height[j]) && i < j) {
                --j;
                max_height = max(max_height, (j - i) * min(height[i], height[j]));
            }
        }
        return max_height;
    }
};