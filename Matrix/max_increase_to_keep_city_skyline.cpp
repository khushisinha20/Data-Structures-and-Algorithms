//leetcode.com/problems/max-increase-to-keep-city-skyline/

#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int> >& grid) {
        vector<int> max_row(grid.size(), 0);
        vector<int> max_col(grid.size(), 0);
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid.size(); ++j) {
                max_row[i] = max(max_row[i], grid[i][j]);
                max_col[j] = max(max_col[j], grid[i][j]);
            }
        }
        int res = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid.size(); ++j) {
                res += min(max_row[i], max_col[j]) - grid[i][j];
            }
        }
        return res;
    }
};