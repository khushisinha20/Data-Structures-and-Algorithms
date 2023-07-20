//leetcode.com/problems/minimum-swaps-to-arrange-a-binary-grid/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bubbleSort(vector<int>& targetRow) {
        int swaps = 0;
        
        for (int i = 0; i < targetRow.size(); ++i) {
            for (int j = 0; j < targetRow.size() - i - 1; ++j) {
                if (targetRow[j] > targetRow[j + 1]) {
                    swap(targetRow[j], targetRow[j + 1]);
                    ++swaps;
                }
            }
        }
        
        return swaps;
    }
    
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> targetRow(n);
        unordered_set<int> found;
        int swaps = 0;
        
        for (int i = 0; i < n; ++i) {
            int zeroesFromEnd = 0;
            int j = n - 1;
            
            while (j >= 0 and grid[i][j] == 0) {
                --j;
                ++zeroesFromEnd;
            }
            
            for (int k = n - 1; k >= 0; --k) {
                if (zeroesFromEnd >= k and found.find(k) == found.end()) {
                    found.insert(k);
                    targetRow[i] = n - k - 1;
                    break;
                }
            }
        }
        
        if (found.size() != n)
            return -1;
        
        return bubbleSort(targetRow);
    }
};