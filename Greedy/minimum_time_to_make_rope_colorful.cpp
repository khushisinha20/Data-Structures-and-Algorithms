//leetcode.com/problems/minimum-time-to-make-rope-colorful/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        colors += '1';
        neededTime.push_back(-1);
        int cost = 0;
        
        for (int i = 0; i < colors.size(); ++i) {
            char currentColor = colors[i];
            int sumOfTimes = neededTime[i];
            int maxTime = neededTime[i];
            ++i;
            bool isRepeating = false;
            
            while (i < colors.size() and colors[i] == currentColor) {
                isRepeating = true;
                sumOfTimes += neededTime[i];
                maxTime = max(maxTime, neededTime[i]);
                ++i;
            }
            
            if (isRepeating) {
                cost += (sumOfTimes - maxTime);
                i -= 2;
            } else
                --i;
        }
        
        return cost;
    }
};