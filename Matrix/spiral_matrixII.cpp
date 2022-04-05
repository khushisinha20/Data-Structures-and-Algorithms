//leetcode.com/problems/spiral-matrix-ii/submissions/

#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int> (n, 0));
        int rowStart = 0;
        int colStart = 0;
        int rowEnd = matrix.size() - 1;
        int colEnd = matrix.size() - 1;
        int count = 0;
        while (count < (n * n)) {
            for (int i = colStart; count < n * n && i <= colEnd; ++i) {
                matrix[rowStart][i] = count + 1;
                ++count;
            }
            ++rowStart;
            for (int i = rowStart; count < n * n && i <= rowEnd; ++i) {
                matrix[i][colEnd] = count + 1;
                ++count;
            }
            --colEnd;
            for (int i = colEnd; count < n * n && i >= colStart; --i) {
                matrix[rowEnd][i] = count + 1;
                ++count;
            }
            --rowEnd;
            for (int i = rowEnd; count < n * n && i >= rowStart; --i) {
                matrix[i][colStart] = count + 1;
                ++count;
            }
            ++colStart;
        }
        return matrix;
    }
};