//leetcode.com/problems/find-the-longest-valid-obstacle-course-at-each-position/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n = obstacles.size();
        vector<int> LIS;
        vector<int> result(n, 1);
        
        for (int i = 0; i < n; ++i) {
            int index = upper_bound(LIS.begin(), LIS.end(), obstacles[i]) - LIS.begin();
            if (index == LIS.size())
                LIS.push_back(obstacles[i]);
            else
                LIS[index] =  obstacles[i];
            result[i] = index + 1;
        }
        
        return result;
    }
};