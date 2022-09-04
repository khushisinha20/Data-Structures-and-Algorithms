//practice.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    void storeOnes(queue<pair<pair<int, int>, int>>& q, vector<vector<int>>& grid, vector<vector<bool>>& visited) {
        for (int row = 0; row < grid.size(); ++row) {
            for (int col = 0; col < grid[0].size(); ++col) {
                if (grid[row][col]) {
                    q.push({{row, col}, 0});
                    visited[row][col] = true;
                }
            }
        }
    }
    
    bool liesInsideGrid(int& row, int& col, vector<vector<int>>& grid) {
        return row >= 0 && row < grid.size() && col >= 0 && col < grid[0].size();
    }
    
    void bfs(queue<pair<pair<int, int>, int>>& q, vector<vector<int>>& grid, vector<vector<bool>>& visited, vector<vector<int>>& distance) {
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while (!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int steps = q.front().second;
            q.pop();
            distance[row][col] = steps;
            
            for (auto direction: directions) {
                int neighbour_row = row + direction.first;
                int neighbour_col = col + direction.second;
                if (liesInsideGrid(neighbour_row, neighbour_col, grid) && !visited[neighbour_row][neighbour_col]) {
                    visited[neighbour_row][neighbour_col] = true;
                    q.push({{neighbour_row, neighbour_col}, steps + 1});
                }
            }
        }
    }
    
	vector<vector<int>> nearest(vector<vector<int>>grid) {
	    queue<pair<pair<int, int>, int>> q;
	    int rows = grid.size();
	    int cols = grid[0].size();
	    vector<vector<bool>>visited (rows, vector<bool> (cols, false));
	    storeOnes(q, grid, visited);
	    vector<vector<int>>distance (rows, vector<int> (cols, 0));
	    bfs(q, grid, visited, distance);
	    return distance;
	}
};