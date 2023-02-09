//leetcode.com/problems/set-matrix-zeroes/submissions/

#include <bit>/stdc++.h>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool zeroInFirstRow = false;
        
        for (int row = 0; row < matrix.size(); ++row) {
            for (int col = 0; col < matrix[0].size(); ++col) {
                if (matrix[row][col] == 0) {
                    matrix[0][col] = 0;
                    if (row > 0)
                        matrix[row][0] = 0;
                    else
                        zeroInFirstRow = true;
                }
            }
        }
        
        for (int row = 1; row < matrix.size(); ++row) {
            for (int col = 1; col < matrix[row].size(); ++col) {
                if (matrix[0][col] == 0 || matrix[row][0] == 0)
                    matrix[row][col] = 0;
            }
        }
        
        if (matrix[0][0] == 0) {
            for (int row = 0; row < matrix.size(); ++row)
                matrix[row][0] = 0;
        }
        
        if (zeroInFirstRow) {
            for (int col = 0; col < matrix[0].size(); ++col)
                matrix[0][col] = 0;
        }
        
    }
};