//leetcode.com/problems/rectangle-area/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int areaOfRectangle1 = (ax2 - ax1) * (ay2 - ay1);
        int areaOfRectangle2 = (bx2 - bx1) * (by2 - by1);
        int x1 = max(ax1, bx1);
        int x2 = min(ax2, bx2);
        int y1 = max(ay1, by1);
        int y2 = min(ay2, by2);
        int areaOfCommonRectangle = 0;
        if (x2 > x1 && y2 > y1)
            areaOfCommonRectangle = (x2 - x1) * (y2 - y1);
        return areaOfRectangle1 + areaOfRectangle2 - areaOfCommonRectangle;
    }
};