//leetcode.com/problems/separate-squares-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double areaDifference(vector<vector<int>>& squares, double h) {
        double above = 0;
        double below = 0;

        for (auto& square: squares) {
            double y = square[1];
            double l = square[2];
            double top = y + l;

            if (h <= y)
                above += l * l;
            else if (h >= top)
                below += l * l;
            else {
                double upper = top - h;
                double lower = h - y;
                above += upper * l;
                below += lower * l;
            }
        }

        return above - below;
    }

    double separateSquares(vector<vector<int>>& squares) {
        double low = 0;
        double high = 1e9;
        double eps = 1e-5;
        double ans = 0;

        while (high - low > eps) {
            double mid = (low + high) / 2;
            double diff = areaDifference(squares, mid);
            if (diff <= 0) {
                ans = mid;
                high = mid;
            } else {
                low = mid;
            }
        }

        return ans;
    }
};
