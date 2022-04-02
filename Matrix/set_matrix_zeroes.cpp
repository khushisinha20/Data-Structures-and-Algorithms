//leetcode.com/problems/set-matrix-zeroes/submissions/

#include <bit>/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool zero_in_first_col = false;
        for (int rows = 0; rows < matrix.size(); ++rows) {
            if (matrix[rows][0] == 0) {
                zero_in_first_col = true;
            }
            for (int cols = 1; cols < matrix[0].size(); ++cols) {
                if (matrix[rows][cols] == 0) {
                    matrix[rows][0] = 0;
                    matrix[0][cols] = 0;
                }
            }
        }
        for (int rows = matrix.size() - 1; rows >= 0; --rows) {
            for (int cols = matrix[0].size() - 1; cols >= 1; --cols) {
                if (matrix[rows][0] == 0 || matrix[0][cols] == 0)
                    matrix[rows][cols] = 0;
            }
            if (zero_in_first_col)
                matrix[rows][0] = 0;
        }
    }
};