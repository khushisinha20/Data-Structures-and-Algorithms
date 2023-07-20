//leetcode.com/problems/non-overlapping-intervals/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    static bool comparator(vector<int>& a, vector<int>& b) {
        return a[1] < b[1];
    }
    
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comparator);
        if (intervals.size() < 2)
            return 0;
        
        vector<int> previous = intervals[0];
        int removals = -1;
        
        for (auto& interval: intervals) {
            if (previous[1] > interval[0])
                ++removals;
            else
                previous = interval;
        }
        
        return removals;
    }
};