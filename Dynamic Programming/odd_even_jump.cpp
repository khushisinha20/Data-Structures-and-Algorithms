//leetcode.com/problems/odd-even-jump/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
        map<int, int> indexMap;
        int n = arr.size();
        vector<bool> isHigherPossible(n, false);
        vector<bool> isLowerPossible(n, false);
        indexMap[arr[n - 1]] = n - 1;
        isHigherPossible[n - 1] = true;
        isLowerPossible[n - 1] = true;
        int goodJumps = 1; 
        
        for (int i = n - 2; i >= 0; --i) {
            auto higher = indexMap.lower_bound(arr[i]);
            auto lower = indexMap.upper_bound(arr[i]);
            
            if (higher != indexMap.end())
                isHigherPossible[i] = isLowerPossible[higher -> second];
            
            if (lower != indexMap.begin()) {
                --lower;
                isLowerPossible[i] = isHigherPossible[lower -> second];
            }
            
            if (isHigherPossible[i])
                ++goodJumps;
            
            indexMap[arr[i]] = i;
        }
        
        return goodJumps;
    }
};