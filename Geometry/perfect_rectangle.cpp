//leetcode.com/problems/perfect-rectangle/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        int n = rectangles.size();
        map<pair<int, int>, int> points;
        
        for (auto rectangle: rectangles) {
            ++points[{rectangle[0], rectangle[1]}];
            ++points[{rectangle[2], rectangle[3]}];
            --points[{rectangle[0], rectangle[3]}];
            --points[{rectangle[2], rectangle[1]}];
        }
        
        int corners = 0;
        
        for (auto point = points.begin(); point != points.end(); ++point) {
            if (point -> second == 1 || point -> second == -1)
                ++corners;
            else if (point -> second != 0)
                return false;
        }
        
        return corners == 4;
    }
};