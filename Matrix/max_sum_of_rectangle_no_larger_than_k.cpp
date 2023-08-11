//leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int maxSum = INT_MIN;
        int numRows = matrix.size();
        int numCols = matrix[0].size();
        
        for (int left = 0; left < numCols; ++left) {
            vector<int> rowSums(numRows, 0);
            for (int right = left; right < numCols; ++right) {
                for (int row = 0; row < numRows; ++row)
                    rowSums[row] += matrix[row][right];
                
                set<int> sumSet = {0};
                int runningSum = 0;
                
                for (auto& rowSum: rowSums) {
                    runningSum += rowSum;
                    auto it = sumSet.lower_bound(runningSum - k);
                    if (it != sumSet.end())
                        maxSum = max(maxSum, runningSum - *it);
                    
                    sumSet.insert(runningSum);
                }
            }
        }
        
        return maxSum;
    }
};