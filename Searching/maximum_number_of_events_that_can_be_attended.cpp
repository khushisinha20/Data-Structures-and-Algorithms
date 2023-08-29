//leetcode.com/problems/maximum-number-of-events-that-can-be-attended/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        
        set<int> availableDays;
        for (int i = 1; i <= 100000; i++) {
            availableDays.insert(i);
        }
        
        int attended = 0;
        for (const vector<int>& event : events) {
            auto it = availableDays.lower_bound(event[0]); 
            if (it != availableDays.end() && *it <= event[1]) {
                availableDays.erase(it);
                attended++;
            }
        }
        
        return attended;
    }
};
