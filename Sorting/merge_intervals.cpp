//leetcode.com/problems/merge-intervals/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canBeMerged(vector<int>& first_interval, vector<int>& second_interval) {
        return first_interval[1] >= second_interval[0];
    }
    
    void mergeOverlappingIntervals(vector<int>& temp, vector<int>& interval) {
        temp[0] = min(temp[0], interval[1]);
        temp[1] = max(temp[1], interval[1]);
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> result;
        vector<int> temp = intervals[0];
        for (int i = 1; i < intervals.size(); ++i) {
            if (canBeMerged(temp, intervals[i])) {
                mergeOverlappingIntervals(temp, intervals[i]);
            } else {
                result.push_back(temp);
                temp = intervals[i];
            }
        }
        result.push_back(temp);
        return result;
    }
};