//leetcode.com/problems/largest-rectangle-in-histogram/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextSmallerToLeft(vector<int>& heights) {
        vector<int> nsl(heights.size());
        stack<pair<int, int>> previousHeights;
        
        for (int i = 0; i < heights.size(); ++i) {
            if (!previousHeights.empty() && previousHeights.top().first < heights[i])
                nsl[i] = previousHeights.top().second;
            else {
                while (!previousHeights.empty() && previousHeights.top().first >= heights[i])
                    previousHeights.pop();
                if (previousHeights.empty())
                    nsl[i] = -1;
                else
                    nsl[i] = previousHeights.top().second;
            }
            previousHeights.push({heights[i], i});
        }
        return nsl;
    }
        
    vector<int> nextSmallerToRight(vector<int>& heights) {
        vector<int> nsr(heights.size());
        stack<pair<int, int>> nextHeights;
        
        for (int i = heights.size() - 1; i >= 0; --i) {
            if (!nextHeights.empty() && nextHeights.top().first < heights[i])
                nsr[i] = nextHeights.top().second;
            else {
                while (!nextHeights.empty() && nextHeights.top().first >= heights[i])
                    nextHeights.pop();
                if (nextHeights.empty())
                    nsr[i] = heights.size();
                else
                    nsr[i] = nextHeights.top().second;
            }
            nextHeights.push({heights[i], i});
        }
        return nsr;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        vector<int> nsl = nextSmallerToLeft(heights);
        vector<int> nsr = nextSmallerToRight(heights);
        int maxArea = 0;
        for (int i = 0; i < heights.size(); ++i) {
            int width = nsr[i] - nsl[i] - 1;
            maxArea = max(maxArea, width * heights[i]);
        }
        return maxArea;
    }
};