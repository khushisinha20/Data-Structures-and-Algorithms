//leetcode.com/problems/insert-interval/submissions/

#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        int i = 0;
        //Phase 1: Does not overlap before merging
        while (i < intervals.size() && intervals[i][1] < newInterval[0]) 
            result.push_back(intervals[i++]);
        
        //Phase 2: Overlaps
        while (i < intervals.size() && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i++][1]);
        }
        result.push_back(newInterval);
        
        //Phase 3: Does not overlap after merging
        while (i < intervals.size()) 
            result.push_back(intervals[i++]);
        
        return result;
    }
};