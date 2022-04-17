//leetcode.com/problems/non-overlapping-intervals/submissions/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int left = 0;
        int right = 1;
        int minimum_removals = 0;
        sort(intervals.begin(), intervals.end());
        while (right < intervals.size()) {
            if (intervals[left][1] <= intervals[right][0]) {
                left = right;
                ++right;
            } else if (intervals[left][1] <= intervals[right][1]) {
                ++minimum_removals;
                ++right;
            } else if (intervals[left][1] > intervals[right][1]) {
                ++minimum_removals;
                left = right;
                ++right;
            }
        }
        return minimum_removals;
    }
};