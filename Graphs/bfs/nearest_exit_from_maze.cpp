//leetcode.com/problems/nearest-exit-from-entrance-in-maze/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    queue<pair<pair<int, int>, int>> getBorderCells(vector<vector<char>>& maze, int& entranceRow, int& entranceCol) {
        queue<pair<pair<int, int>, int>> cells;
        
        for (int row = 0; row < maze.size(); ++row) {
            for (int col = 0; col < maze[row].size(); ++col) {
                if ((row == 0 or col == 0 or row == maze.size() - 1 or col == maze[0].size() - 1) && maze[row][col] == '.' && (row != entranceRow || col != entranceCol)) {
                    cells.push({{row, col}, 0});
                    maze[row][col] = '+'; 
                }
            }
        }
        
        return cells;
    }
    
    bool liesInsideMaze(int row, int col, vector<vector<char>>& maze) {
        return row >= 0 && col >= 0 && row < maze.size() && col < maze[0].size();
    }
    
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int entranceRow = entrance[0];
        int entranceCol = entrance[1];
        auto cells = getBorderCells(maze, entranceRow, entranceCol);
        
        vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        while (!cells.empty()) {
            int row = cells.front().first.first;
            int col = cells.front().first.second;
            int distance = cells.front().second;
            cells.pop();
            
            if (row == entranceRow && col == entranceCol)
                return distance;
            
            for (auto& direction: directions) {
                int newRow = row + direction[0];
                int newCol = col + direction[1];
                
                if (liesInsideMaze(newRow, newCol, maze) && maze[newRow][newCol] == '.') {
                    cells.push({{newRow, newCol}, distance + 1});
                    maze[newRow][newCol] = '+';
                }
            }
        }
        
        return -1;
    }
};