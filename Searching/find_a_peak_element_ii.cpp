//leetcode.com/problems/find-a-peak-element-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxInRow(vector<vector<int>>& matrix, int row) {
        int maxValueCol = 0;
        int maxValue = INT_MIN;

        for (int col = 0; col < matrix[0].size(); ++col) {
            if (matrix[row][col] > maxValue) {
                maxValue = matrix[row][col];
                maxValueCol = col;
            }
        }

        return maxValueCol;
    }

    vector<vector<int>> getPaddedMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> matrix(m + 2, vector<int>(n + 2, -1));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                matrix[i][j] = mat[i - 1][j - 1];
            }
        }

        return matrix;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        vector<vector<int>> matrix = getPaddedMatrix(mat);
        int low = 1;
        int high = matrix.size() - 2;
        vector<int> coordinates;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int maxValueCol = findMaxInRow(matrix, mid);

            if (matrix[mid][maxValueCol] > matrix[mid - 1][maxValueCol] &&
                matrix[mid][maxValueCol] > matrix[mid + 1][maxValueCol]) {
                coordinates = {mid - 1, maxValueCol - 1};
                break;
            } else if (matrix[mid - 1][maxValueCol] > matrix[mid][maxValueCol]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return coordinates;
    }
};

