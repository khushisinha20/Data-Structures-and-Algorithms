//leetcode.com/problems/find-the-kth-smallest-sum-of-a-matrix-with-sorted-rows/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        vector<int> temp = mat[0];
        for (int row = 1; row < mat.size(); ++row) {
            vector<int> sum_till_current_row;
            for (int col = 0; col < mat[0].size(); ++col) {
                for (int i = 0; i < temp.size(); ++i) {
                    sum_till_current_row.push_back(temp[i] + mat[row][col]);
                }
            }
            sort(sum_till_current_row.begin(), sum_till_current_row.end());
            temp.clear();
            for (int i = 0; i < min(k + 1, (int)sum_till_current_row.size()); ++i)
                temp.push_back(sum_till_current_row[i]);
        }
        return temp[k - 1];
    }
};