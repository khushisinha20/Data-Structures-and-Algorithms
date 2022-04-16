//leetcode.com/problems/minimum-cost-homecoming-of-a-robot-in-a-grid/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int initial_row = startPos[0];
        int initial_col = startPos[1];
        int final_row = homePos[0];
        int final_col = homePos[1];
        int cost = 0;
        while (initial_row != final_row) {
            if (initial_row < final_row)
                cost += rowCosts[++initial_row];
            if (initial_row > final_row)
                cost += rowCosts[--initial_row];
        }
        while (initial_col != final_col) {
            if (initial_col < final_col)
                cost += colCosts[++initial_col];
            if (initial_col > final_col)
                cost += colCosts[--initial_col];
        }
        return cost;
    }
};