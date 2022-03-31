//leetcode.com/problems/insert-interval/submissions/

#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > insert(vector<vector<int> >& intervals, vector<int>& newInterval) {
        vector<vector<int> > res;
        int i = 0;
        while (i < intervals.size() && intervals[i][0] <= newInterval[0]) {
            res.push_back({intervals[i][0], intervals[i][1]});
            ++i;
        }
        if (res.size() == 0 || res.back()[1] < newInterval[0]) {
            res.push_back({newInterval[0], newInterval[1]});
        } else {
            res.back()[0] = min(newInterval[0], res.back()[0]);
            res.back()[1] = max(newInterval[1], res.back()[1]);
        }
        while (i < intervals.size() && res.back()[1] >= intervals[i][0]) {
            res.back()[0] = min(intervals[i][0], res.back()[0]);
            res.back()[1] = max(intervals[i][1], res.back()[1]);
            ++i;
        }
        while (i < intervals.size()) {
            res.push_back(intervals[i]);
            ++i;
        }
        return res;
    }
};