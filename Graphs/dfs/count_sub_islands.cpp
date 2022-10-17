//leetcode.com/problems/count-sub-islands/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, vector<vector<bool>>& visited, int row, int col, bool& isNotSubIsland) {
        if (row < 0 || row >= grid2.size() || col < 0 || col >= grid2[0].size() || grid2[row][col] == 0 || visited[row][col])
            return;
        
        
        visited[row][col] = true;
        
        if (grid1[row][col] == 0) 
            isNotSubIsland = true;
        
        dfs(grid1, grid2, visited, row + 1, col, isNotSubIsland);
        dfs(grid1, grid2, visited, row - 1, col, isNotSubIsland);
        dfs(grid1, grid2, visited, row, col + 1, isNotSubIsland);
        dfs(grid1, grid2, visited, row, col - 1, isNotSubIsland);
    }
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        vector<vector<bool>> visited(grid2.size(), vector<bool> (grid2[0].size(), false));
        int subIslands = 0;
        bool isNotSubIsland = false;
        for (int row = 0; row < grid2.size(); ++row) {
            for (int col = 0; col < grid2[0].size(); ++col) {
                if (!visited[row][col] && grid2[row][col] == 1) {
                    isNotSubIsland = false;
                    dfs(grid1, grid2, visited, row, col, isNotSubIsland);
                    if (!isNotSubIsland)
                        ++subIslands;
                }
            }
        }
        return subIslands;
    }
};