//leetcode.com/problems/find-right-interval/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        if (intervals.size() == 1)
            return {-1};
        
        vector<int> rightIntervalIndices(intervals.size(), -1);
        priority_queue<pair<int, int>> maxStartHeap;
        priority_queue<pair<int, int>> maxEndHeap;
        for (int i = 0; i < intervals.size(); ++i) {
            maxStartHeap.push({intervals[i][0], i});
            maxEndHeap.push({intervals[i][1], i});
        }
        
        while (!maxEndHeap.empty() && !maxStartHeap.empty()) {
            pair<int, int> nearestRightInterval;
            bool hasRightInterval = false;
            while (!maxEndHeap.empty() && !maxStartHeap.empty() && maxEndHeap.top().first <= maxStartHeap.top().first) { 
                nearestRightInterval = maxStartHeap.top();
                maxStartHeap.pop();
                hasRightInterval = true;
            }
            if (!hasRightInterval) {
                maxEndHeap.pop();
                continue;
            }
            rightIntervalIndices[maxEndHeap.top().second] = nearestRightInterval.second;
            maxEndHeap.pop();
            maxStartHeap.push(nearestRightInterval);
        }
        return rightIntervalIndices;
    }
};