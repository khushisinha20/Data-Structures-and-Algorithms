//leetcode.com/problems/reshape-the-matrix/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        if (mat.size() * mat[0].size() != r * c)
            return mat;
        
        vector<vector<int>> reshaped_matrix(r, vector<int> (c, 0));
        for (int i = 0; i < r * c; ++i) {
            reshaped_matrix[i / c][i % c] = mat[i / mat[0].size()][i % mat[0].size()];    
        }
        return reshaped_matrix;
    }
};