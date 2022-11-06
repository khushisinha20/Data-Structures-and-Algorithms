//leetcode.com/problems/earliest-possible-day-of-full-bloom/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool comparator(pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;
    }
        
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<pair<int, int>> plants;
        for (int i = 0; i < plantTime.size(); ++i)
            plants.push_back({plantTime[i], growTime[i]});
        sort(plants.begin(), plants.end(), comparator);
        int earliestDay = 0;
        int currentDay = 0;
        for (int i = 0; i < plants.size(); ++i) {
            currentDay += plants[i].first;
            earliestDay = max(earliestDay, currentDay + plants[i].second);
        }
        return earliestDay;
    }
};