//leetcode.com/problems/rotting-oranges/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void segregateOranges(vector<vector<int>>& grid, int& fresh_oranges, queue<pair<int, int>>& rotten_oranges) {
        for (int row = 0; row < grid.size(); ++row) {
            for (int col = 0; col < grid[0].size(); ++col) {
                if (grid[row][col] == 1)
                    ++fresh_oranges;
                if (grid[row][col] == 2)
                    rotten_oranges.push({row, col});
            }
        }
    }
    
    void bfs(vector<vector<int>>& grid, int& fresh_oranges, queue<pair<int, int>>& rotten_oranges, int& min_time) {
        while (!rotten_oranges.empty()) {
            int size = rotten_oranges.size();
            for (int i = 0; i < size; ++i) {
                int row = rotten_oranges.front().first;
                int col = rotten_oranges.front().second;
               rotten_oranges.pop();
               if (col < grid[0].size() - 1 && grid[row][col + 1] == 1) {
                   grid[row][col + 1] = 2;
                   rotten_oranges.push({row, col + 1});
                   --fresh_oranges;
               }
               if (col > 0 && grid[row][col - 1] == 1) {
                   grid[row][col - 1] = 2;
                   rotten_oranges.push({row, col - 1});
                   --fresh_oranges;
               }
               if (row < grid.size() - 1 && grid[row + 1][col] == 1) {
                   grid[row + 1][col] = 2;
                   rotten_oranges.push({row + 1, col});
                   --fresh_oranges;
               }
               if (row > 0 && grid[row - 1][col] == 1) {
                   grid[row - 1][col] = 2;
                   rotten_oranges.push({row - 1, col});
                   --fresh_oranges;
               }
           }
           if (!rotten_oranges.empty())
             ++min_time;
        }
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh_oranges = 0;
        queue<pair<int, int>> rotten_oranges;
        segregateOranges(grid, fresh_oranges, rotten_oranges);
        int min_time = 0;
        bfs(grid, fresh_oranges, rotten_oranges, min_time);
        return fresh_oranges == 0 ? min_time : -1;
    }
};