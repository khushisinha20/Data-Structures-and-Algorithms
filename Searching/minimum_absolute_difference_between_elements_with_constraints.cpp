//leetcode.com/problems/minimum-absolute-difference-between-elements-with-constraint/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        int minDifference = INT_MAX;
        set<int> window;
        
        for (int i = x; i < nums.size(); ++i) {
            window.insert(nums[i - x]);
            auto upperBound = window.upper_bound(nums[i]);
            if (upperBound != window.end())
                minDifference = min(minDifference, abs(nums[i] - *upperBound));
            if (upperBound != window.begin())
                minDifference = min(minDifference, abs(nums[i] - *prev(upperBound)));
        }
        
        return minDifference;
    }
};