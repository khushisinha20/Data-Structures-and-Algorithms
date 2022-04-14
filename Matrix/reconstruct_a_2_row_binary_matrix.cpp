//leetcode.com/problems/reconstruct-a-2-row-binary-matrix/submissions/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        int sum_of_columns = accumulate(colsum.begin(), colsum.end(), 0);
        if (upper + lower != sum_of_columns)
            return {};
        vector<int> upper_row(colsum.size(), 0);
        vector<int> lower_row(colsum.size(), 0);
        int col_with_1 = 0;
        for (int i = 0; i < colsum.size(); ++i) {
            if (colsum[i] == 2) {
                upper_row[i] = 1;
                lower_row[i] = 1;
                --upper;
                --lower;
            }
        }
        for (int i = 0; i < colsum.size(); ++i) {
            if (upper_row[i] == 0 && lower_row[i] == 0 && colsum[i] == 1) {
                if (upper > 0) {
                    upper_row[i] = 1;
                    --upper;
                } else if (lower > 0) {
                    lower_row[i] = 1;
                    --lower;
                } else {
                    break;
                }
             }
        }
        if (upper > 0 || lower > 0)
            return {};
        vector<vector<int>> matrix;
        matrix.push_back(upper_row);
        matrix.push_back(lower_row);
        return matrix;
    }
};
