//leetcode.com/problems/construct-quad-tree/

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

class Solution {
public:
    bool isAllSame(vector<vector<int>>& grid, int row, int col, int n) {
        int value = grid[row][col];
        for (int i = row; i < row + n; ++i)
            for (int j = col; j < col + n; ++j)
                if (grid[i][j] != value)
                    return false;
        return true;
    }
    
    Node* recur(vector<vector<int>>& grid, int row, int col, int n) {
        if (isAllSame(grid, row, col, n))
            return new Node(grid[row][col], true);
        else {
            Node* root = new Node(1, false);
            root -> topLeft = recur(grid, row, col, n / 2);
            root -> topRight = recur(grid, row, col + n / 2, n / 2);
            root -> bottomLeft = recur(grid, row + n / 2, col, n / 2);
            root -> bottomRight = recur(grid, row + n / 2, col + n / 2, n / 2);
            
            return root;
        }
    }
    
    Node* construct(vector<vector<int>>& grid) {
        return recur(grid, 0, 0, grid.size());
    }
};