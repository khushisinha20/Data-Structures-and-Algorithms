//leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        
        int answer = 1;
        int previousStart = points[0][0];
        int previousEnd = points[0][1];
        
        for (int i = 1; i < points.size(); ++i) {
            if (points[i][0] <= previousEnd) {
                previousStart = points[i][0];
                previousEnd = min(previousEnd, points[i][1]);
            } else {
                previousStart = points[i][0];
                previousEnd = points[i][1];
                ++answer;
            }
        }
        
        return answer;
    }
};