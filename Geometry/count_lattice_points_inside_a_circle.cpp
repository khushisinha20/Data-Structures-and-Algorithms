//leetcode.com/problems/count-lattice-points-inside-a-circle/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool liesInsideCircle(int x, int y, vector<int>& circle) {
        return (circle[0] - x) * (circle[0] - x) + (circle[1] - y) * (circle[1] - y) <= circle[2] * circle[2];
    }
    
    int countLatticePoints(vector<vector<int>>& circles) {
        set<pair<int, int>> lattice_points;
        for (auto circle: circles) {
            for (int i = circle[0] - circle[2]; i <= circle[0] + circle[2]; ++i) {
                for (int j = circle[1] - circle[2]; j <= circle[1] + circle[2]; ++j) {
                    if (liesInsideCircle(i, j, circle))
                        lattice_points.insert(make_pair(i, j));
                }
            }
        }
        return lattice_points.size();
    }
};