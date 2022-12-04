//leetcode.com/problems/valid-triangle-number/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int triangles = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int first = 0;
            int second = i - 1;
            while (first < second) {
                if (nums[first] + nums[second] > nums[i]) {
                    triangles += (second - first);
                    --second;
                } else
                    ++first;
            }
        }
        return triangles;
    }
};