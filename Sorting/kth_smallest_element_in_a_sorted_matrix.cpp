//leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/\\\

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int partition(vector<vector<int>>& matrix, int low, int high) {
        int i = low - 1;
        int cols = matrix[0].size();
        int pivot = matrix[high / cols][high % cols]; 
        for (int j = low; j < high; ++j) {
            if (matrix[j / cols][j % cols] < pivot) {
                ++i;
                swap(matrix[j / cols][j % cols], matrix[i / cols][i % cols]);
            }
        }
        
        swap(matrix[(i + 1) / cols][(i + 1) % cols], matrix[high / cols][high % cols]);
        return i + 1;
    }
    
    int getKthSmallest(vector<vector<int>>& matrix, int k, int low, int high) {
        int cols = matrix[0].size();
        int rowKthSmallest =  k / cols;
        int colKthSmallest = k % cols;
        int index = 0;
        while (low <= high) {
            index = partition(matrix, low, high);
            if (index == k) {
                cout << rowKthSmallest << " " << colKthSmallest;
                return matrix[rowKthSmallest][colKthSmallest];
            }
            else if (index > k)
                high = index - 1;
            else
                low = index + 1;
        }
        return -1;
    }
    
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        --k;
        return getKthSmallest(matrix, k, 0, (matrix.size() * matrix.size()) - 1);
    }
};