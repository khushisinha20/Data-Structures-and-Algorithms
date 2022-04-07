//leetcode.com/problems/maximum-matrix-sum/submissions/

#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum = 0;
        long long negative_numbers = 0;
        long long min_number = INT_MAX;
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (matrix[i][j] < 0)
                    ++negative_numbers;
                sum += abs(matrix[i][j]);
                if (abs(matrix[i][j]) < min_number)
                    min_number = abs(matrix[i][j]);
            }
        }
        if (negative_numbers % 2 == 0)
            return sum;
        return sum - 2 * min_number;
    }
};