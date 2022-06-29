//leetcode.com/problems/n-queens-ii/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void helper(int row, vector<bool>& cols, vector<bool>& main_diag, vector<bool>& sec_diag, int& total_ways) {
        if (row == cols.size()) {
            ++total_ways;
            return;
        }
        
        for (int col = 0; col < cols.size(); ++col) {
            if (!cols[col] && !main_diag[row + col] && !sec_diag[row - col + cols.size() - 1]) {
                cols[col] = main_diag[row + col] = sec_diag[row - col + cols.size() - 1] = true;
                helper(row + 1, cols, main_diag, sec_diag, total_ways);
                cols[col] = main_diag[row + col] = sec_diag[row - col + cols.size() - 1] = false;
            }
        }
    }
    
    int totalNQueens(int n) {
        vector<bool> cols(n, false);
        vector<bool> main_diag(2 * n - 1, false);
        vector<bool> sec_diag(2 * n - 1, false);
        int total_ways = 0;
        helper(0, cols, main_diag, sec_diag, total_ways);
        return total_ways;
    }
};