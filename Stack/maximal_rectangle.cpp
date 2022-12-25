//leetcode.com/problems/maximal-rectangle/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nearestSmallerToLeft(vector<int>& heights) {
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
    
    vector<int> nearestSmallerToRight(vector<int>& heights) {
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
    
    int maximumAreaRectangle(vector<int>& heights) {
        vector<int> nsl = nearestSmallerToLeft(heights);
        vector<int> nsr = nearestSmallerToRight(heights);
        int maxAreaRectangle = 0;
        for (int i = 0; i < heights.size(); ++i) {
            int width = nsr[i] - nsl[i] - 1;
            maxAreaRectangle = max(maxAreaRectangle, width * heights[i]);
        }
        return maxAreaRectangle;
    }
    
    void updateHistogram(vector<int>& histogram, vector<vector<char>>& matrix, int row) {
        for (int i = 0; i < matrix[row].size(); ++i) 
            if (matrix[row][i] == '0')
                histogram[i] = 0;
            else
                ++histogram[i];
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int> histogram(matrix[0].size(), 0);
        int maxArea = 0;
        for (int row = 0; row < matrix.size(); ++row) {
            updateHistogram(histogram, matrix, row);
            maxArea = max(maxArea, maximumAreaRectangle(histogram)); 
        }
        return maxArea;
    }
};