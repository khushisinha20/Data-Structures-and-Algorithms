#include <bits/stdc++.h>
using namespace std;

//leetcode.com/problems/find-kth-largest-xor-coordinate-value/

class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        priority_queue<int, vector<int>, greater<int>> minHeap;
        
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (i > 0)
                    matrix[i][j] ^= matrix[i - 1][j];
                if (j > 0)
                    matrix[i][j] ^= matrix[i][j - 1];
                if (i > 0 and j > 0)
                    matrix[i][j] ^= matrix[i - 1][j - 1];
                minHeap.push(matrix[i][j]);
                if (minHeap.size() > k)
                    minHeap.pop();
            }
        }
        
        return minHeap.top();
    }
};
