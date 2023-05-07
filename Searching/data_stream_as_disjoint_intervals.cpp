//leetcode.com/problems/data-stream-as-disjoint-intervals/

#include <bits/stdc++.h>
using namespace std;

class SummaryRanges {
public:
    map<int, int> intervals;
    
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        int left = value;
        int right = value;
        
        auto justGreater = intervals.upper_bound(value);
        
        if (justGreater != intervals.begin()) {
            auto before = justGreater;
            --before;
            
            if (before -> second == value - 1)
                left = before -> first;
            
            if (before -> second >= value)
                return;
        }
        
        if (justGreater != intervals.end() and justGreater -> first == value + 1) {
            right = justGreater -> second;
            intervals.erase(justGreater);
        }
        
        intervals[left] = right;
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> result;
        for (auto& interval: intervals)
            result.push_back({interval.first, interval.second});
        
        return result;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */