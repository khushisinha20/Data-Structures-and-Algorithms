//leetcode.com/problems/maximum-number-of-visible-points/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findAngle(double dy, double dx) {
        double theta = atan2(dy, dx) * 180.0 / M_PI;
        if (theta < 0)
            theta += 360.0;
        return theta;
    }

    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        vector<double> angles;
        int sameLocationCount = 0;

        for (auto& point: points) {
            int dx = point[0] - location[0];
            int dy = point[1] - location[1];

            if (dx == 0 and dy == 0)
                ++sameLocationCount;
            else {
                double currentAngle = findAngle(dy, dx);
                angles.push_back(currentAngle);
            }
        }

        sort(angles.begin(), angles.end());
        int n = angles.size();
        for (int i = 0; i < n; ++i)
            angles.push_back(angles[i] + 360.0);

        int maxVisible = 0;
        int j = 0;
        for (int i = 0; i < n; ++i) {
            while (j < angles.size() and angles[j] <= angles[i] + angle)
                ++j;
            maxVisible = max(maxVisible, j - i);
        }

        return maxVisible + sameLocationCount;
    }
};
