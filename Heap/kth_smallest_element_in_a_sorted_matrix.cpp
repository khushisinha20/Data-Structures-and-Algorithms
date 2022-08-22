//leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> max_heap;
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (max_heap.size() < k)
                    max_heap.push(matrix[i][j]);
                else {
                    if (matrix[i][j] < max_heap.top()) {
                        max_heap.push(matrix[i][j]);
                        max_heap.pop();
                    } else
                        break;
                }
            }
        }
        return max_heap.top();
    }
};