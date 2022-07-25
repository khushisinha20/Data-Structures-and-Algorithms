//leetcode.com/problems/largest-rectangle-in-histogram/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nearestSmallestLeft(vector<int>& arr, vector<int>& heights) {
        stack<pair<int, int>> s;
        for (int i = 0; i < heights.size(); ++i) {
            if (s.empty())
                arr[i] = -1;
            else if (!s.empty() && s.top().first < heights[i])
                arr[i] = s.top().second;
            else if (!s.empty() && s.top().first >= heights[i]) {
                while (!s.empty() && s.top().first >= heights[i])
                    s.pop();
                if (s.empty())
                    arr[i] = -1;
                else
                    arr[i] = s.top().second;
            }
            s.push({heights[i], i});
        }
    }
    
    void nearestSmallestRight(vector<int>& arr, vector<int>& heights) {
        stack<pair<int, int>> s;
        for (int i = heights.size() - 1; i >= 0; --i) {
            if (s.empty())
                arr[i] = heights.size();
            else if (!s.empty() && s.top().first < heights[i]) 
                arr[i] = s.top().second;
            else if (!s.empty() && s.top().first >= heights[i]) {
                while (!s.empty() && s.top().first >= heights[i])
                    s.pop();
                if (s.empty())
                    arr[i] = heights.size();
                else
                    arr[i] = s.top().second;
            }
            s.push({heights[i], i});
        }
    }
    
    int largestRectangleArea(vector<int>& heights) {
        vector<int> nearest_smallest_left(heights.size());
        vector<int> nearest_smallest_right(heights.size());
        nearestSmallestLeft(nearest_smallest_left, heights);
        nearestSmallestRight(nearest_smallest_right, heights);
        int largest_area = 0;
        for (int i = 0; i < heights.size(); ++i) {
            int width = nearest_smallest_right[i] - nearest_smallest_left[i] - 1;
            largest_area = max(largest_area, width * heights[i]);
        }
        return largest_area;
    }
};