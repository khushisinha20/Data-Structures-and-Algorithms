//leetcode.com/problems/maximal-rectangle/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nearestSmallerLeft(vector<int>& histogram, vector<int>& arr) {
        stack<pair<int, int>> s;
        for (int i = 0; i < histogram.size(); ++i) {
            if (s.empty())
                arr[i] = -1;
            else if (!s.empty() && s.top().first < histogram[i])
                arr[i] = s.top().second;
            else if (!s.empty() && s.top().first >= histogram[i]) {
                while (!s.empty() && s.top().first >= histogram[i])
                    s.pop();
                if (s.empty())
                    arr[i] = -1;
                else
                    arr[i] = s.top().second;
            }
            s.push({histogram[i], i});
        }
        return arr;
    }
    
    vector<int> nearestSmallerRight(vector<int>& histogram, vector<int>& arr) {
        stack<pair<int, int>> s;
        for (int i = histogram.size() - 1; i >= 0; --i) {
            if (s.empty())
                arr[i] = histogram.size();
            else if (!s.empty() && s.top().first < histogram[i])
                arr[i] = s.top().second;
            else if (!s.empty() && s.top().first >= histogram[i]) {
                while (!s.empty() && s.top().first >= histogram[i])
                    s.pop();
                if (s.empty())
                    arr[i] = histogram.size();
                else
                    arr[i] = s.top().second;
            }
            s.push({histogram[i], i});
        }
        return arr;
    }
    
    int maximumAreaInHistogram(vector<int>& histogram) {
        vector<int> nearest_smaller_left(histogram.size());
        vector<int> nearest_smaller_right(histogram.size());
        nearestSmallerLeft(histogram, nearest_smaller_left);
        nearestSmallerRight(histogram, nearest_smaller_right);
        int max_area = 0;
        for (int i = 0; i < histogram.size(); ++i) {
            int width = nearest_smaller_right[i] - nearest_smaller_left[i] - 1;
            max_area = max(max_area, histogram[i] * width);
        }
        return max_area;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int> histogram;
        for (int col = 0; col < matrix[0].size(); ++col) 
            histogram.push_back(matrix[0][col] - '0');
        
        int maximal_rectangle = maximumAreaInHistogram(histogram);
        for (int row = 1; row < matrix.size(); ++row) {
            for (int col = 0; col < matrix[0].size(); ++col) {
                if (matrix[row][col] != '0')
                    histogram[col] += (matrix[row][col] - '0');
                else
                    histogram[col] = 0;
            }
            maximal_rectangle = max(maximal_rectangle, maximumAreaInHistogram(histogram));
        }
        
        return maximal_rectangle;
    }
};