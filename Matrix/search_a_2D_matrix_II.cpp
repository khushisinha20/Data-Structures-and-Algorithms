//leetcode.com/problems/search-a-2d-matrix-ii/

#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        int row = 0;
        int col = matrix[0].size() - 1;
        while (row < matrix.size() && col >= 0) {
            if (matrix[row][col] == target)
                return true;
            else if (matrix[row][col] > target)
                --col;
            else
                ++row;
        }
        return false;
    }
};