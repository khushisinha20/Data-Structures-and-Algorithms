//leetcode.com/problems/queens-that-can-attack-the-king/

#include <bits/stdc++.h>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<vector<int>> attacking_queen_coordinates;
        vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {-1, -1}, {1, 1}, {-1, 1}, {1, -1}};
        set<vector<int>> queen_coordinates;
        for (auto queen: queens) {
            queen_coordinates.insert(queen);
        }
        for (auto d: directions) {
            int i = king[0];
            int j = king[1];
            while (i >= 0 && i < 8 && j >= 0 && j < 8) {
                i += d[0];
                j += d[1];
                if (queen_coordinates.find({i, j}) != queen_coordinates.end()) {
                    attacking_queen_coordinates.push_back({i, j});
                    break;
                }
            }
        }
        return attacking_queen_coordinates;
    }
};