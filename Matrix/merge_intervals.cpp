//leetcode.com/problems/merge-intervals/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged_intervals;
        vector<int> temp_interval = intervals[0];
        for (auto current_interval: intervals) {
            if (current_interval[0] <= temp_interval[1]) {
                temp_interval[1] = max(current_interval[1], temp_interval[1]);
            } else {
                merged_intervals.push_back(temp_interval);
                temp_interval = current_interval;
            }
        }
        merged_intervals.push_back(temp_interval);
        return merged_intervals;
    }
};