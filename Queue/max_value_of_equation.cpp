//leetcode.com/problems/max-value-of-equation/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        deque<vector<int>> maxDifferences;
        int maxValue = INT_MIN;
        
        for (int i = 0; i < points.size(); ++i) {
            while (!maxDifferences.empty() and points[i][0] - maxDifferences.front()[0] > k)
                maxDifferences.pop_front();
            
            if (!maxDifferences.empty())
                maxValue = max(maxValue, maxDifferences.front()[1] + points[i][0] + points[i][1]);
            
            int currentDifference = points[i][1] - points[i][0];
            
            while (!maxDifferences.empty() and maxDifferences.back()[1] <= currentDifference)
                maxDifferences.pop_back();
            
            maxDifferences.push_back({points[i][0], currentDifference});
        }
        
        return maxValue;
    }
};