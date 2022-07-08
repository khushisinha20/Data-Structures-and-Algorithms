//practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1#

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    int maxMeetings(int start[], int end[], int n) {
        vector<pair<int, int>> timings;
        for (int i = 0; i < n; ++i) {
            timings.push_back(make_pair(end[i], start[i]));
        }
        sort(timings.begin(), timings.end());
        int res = 1;
        pair<int, int> prev_timings = timings[0];
        for (int i = 1; i < timings.size(); ++i) {
            if (timings[i].second > prev_timings.first) {
                ++res;
                prev_timings = timings[i];
            }
        }
        return res;
    }
};