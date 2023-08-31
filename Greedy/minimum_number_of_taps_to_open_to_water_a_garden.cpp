//leetcode.com/problems/minimum-number-of-taps-to-open-to-water-a-garden/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> endPoint(n + 1, 0);
        
        for (int i = 0; i < ranges.size(); ++i) {
            int start = max(0, i - ranges[i]);
            int end = min(n, i + ranges[i]);
            endPoint[start] = max(endPoint[start], end);
        }
        
        int taps = 0;
        int currentEnd = 0;
        int maxEnd = 0;
        
        for (int i = 0; i < n + 1; ++i) {
            if (i > maxEnd)
                return -1;
            
            if (i > currentEnd) {
                ++taps;
                currentEnd = maxEnd;
            }
            
            maxEnd = max(maxEnd, endPoint[i]);
        }
        
        return taps;
    }
};