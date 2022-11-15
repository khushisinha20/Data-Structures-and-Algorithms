//leetcode.com/problems/couples-holding-hands/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void storeIndices(vector<int>& row, unordered_map<int, int>& index) {
        for (int i = 0; i < row.size(); ++i)
            index[row[i]] = i;
    }
    
    int minSwapsCouples(vector<int>& row) {
        unordered_map<int, int> index;
        storeIndices(row, index);
        int minSwapsRequired = 0;
        
        
        for (int i = 0; i < row.size() - 1; i += 2) {
            if (row[i] % 2 == 0 && row[i + 1] == row[i] + 1) 
                continue;
            if (row[i] % 2 == 1 && row[i + 1] == row[i] - 1)
                continue;
            if (row[i] % 2 == 0) {
                int currentNext = row[i + 1];
                int nextAfterSwap = row[i] + 1;
                swap(row[i + 1], row[index[row[i] + 1]]);
                ++minSwapsRequired;
                int temp = currentNext;
                index[currentNext] = index[nextAfterSwap];
                index[nextAfterSwap] = index[temp];
            } else {
                int currentNext = row[i + 1];
                int nextAfterSwap = row[i] - 1;
                ++minSwapsRequired;
                swap(row[i + 1], row[index[row[i] - 1]]);
                int temp = currentNext;
                index[currentNext] = index[nextAfterSwap];
                index[nextAfterSwap] = index[temp];
            }
        }
        return minSwapsRequired;
    }
};