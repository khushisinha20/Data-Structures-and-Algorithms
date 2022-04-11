//leetcode.com/problems/diagonal-traverse/

#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int> >& mat) {
        vector<int> res(mat.size() * mat[0].size(), 0);
        int row = 0;
        int col = 0;
        for (int i = 0; i < res.size(); ++i) {
            res[i] = mat[row][col];
            if ((row + col) % 2 == 0) {
                if (col == mat[0].size() - 1)
                    ++row;
                else if (row == 0)
                    ++col;
                else {
                    --row;
                    ++col;
                }
            } else {
                if (row == mat.size() - 1)
                    ++col;
                else if (col == 0)
                    ++row;
                else {
                    ++row;
                    --col;
                }
            }
        }
        return res;
    }
};